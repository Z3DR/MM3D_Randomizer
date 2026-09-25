#include "custom_music.hpp"

#include <sys/stat.h>

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <filesystem>

#include "music_streams.hpp"
#include "random.hpp"
#include "settings.hpp"
#include "utils.hpp"

namespace fs = std::filesystem;

namespace CustomMusic {
  using Music::kNoLink;
  using Music::streamSlots;
  using Music::StreamSlot;

  std::array<std::string, BGM_COUNT> assignments;
  std::vector<std::string> reportLines;

  static const std::string musicRoot = "/MM3DR/Custom Music/";
  static const std::string reportPath = musicRoot + "custom_music_report.txt";
  static const std::string musicStreamDir = "/romfs/sound/streaming/stream/";
  static const std::string manifestName = "/mm3dr_custom_music.txt";

  static constexpr std::array<rnd::SeqType, 5> musicCategories = {
      rnd::SEQ_BGM_WORLD, rnd::SEQ_BGM_BATTLE, rnd::SEQ_BGM_EVENT, rnd::SEQ_FANFARE, rnd::SEQ_OCARINA,
  };

  // A slot gets its own folder and can be assigned directly.
  static bool IsAssignable(const StreamSlot& slot) {
    return slot.file != nullptr && slot.category != rnd::SEQ_NOSHUFFLE && slot.linkedTo == kNoLink;
  }

  /*-------------------
  |   CSTM HEADERS    |
  -------------------*/

  struct StreamHeader {
    u8 codec;
    bool loops;
    u8 channels;
    s32 sampleRate;
  };

  // Reads only the first 0x200 bytes. Returns false for anything that isn't a well-formed CSTM.
  static bool ReadStreamHeader(const std::string& path, StreamHeader& out) {
    auto file = FILEPtr{std::fopen(path.c_str(), "rb"), std::fclose};
    if (!file) {
      return false;
    }
    std::array<u8, 0x200> buf{};
    const size_t n = std::fread(buf.data(), 1, buf.size(), file.get());
    auto rd16 = [&](size_t o) { u16 v; std::memcpy(&v, &buf[o], 2); return v; };
    auto rd32 = [&](size_t o) { u32 v; std::memcpy(&v, &buf[o], 4); return v; };

    if (n < 0x20 || std::memcmp(buf.data(), "CSTM", 4) != 0 || rd16(0x04) != 0xFEFF) {
      return false;
    }
    u32 info = 0;
    for (u16 i = 0, count = rd16(0x10); i < count; i++) {
      const size_t e = 0x14 + i * 0x0C;
      if (e + 0x0C > n) {
        return false;
      }
      if (rd16(e) == 0x4000) {
        info = rd32(e + 4);
        break;
      }
    }
    if (info == 0 || info + 0x28 > n || std::memcmp(&buf[info], "INFO", 4) != 0) {
      return false;
    }

    out.codec = buf[info + 0x20];
    out.loops = buf[info + 0x21] != 0;
    out.channels = buf[info + 0x22];
    out.sampleRate = static_cast<s32>(rd32(info + 0x24));
    return true;
  }

  /*-------------------
  |   LIBRARY SCAN    |
  -------------------*/

  struct Song {
    std::string path;
    StreamHeader header;
  };

  // Non-recursive: subfolders of a category folder are slot folders and are scanned separately.
  static std::vector<Song> ScanFolder(const std::string& dir) {
    std::vector<Song> songs;
    std::error_code ec;
    for (auto it = fs::directory_iterator(dir, ec); !ec && it != fs::directory_iterator(); it.increment(ec)) {
      if (!it->is_regular_file(ec)) {
        continue;
      }
      std::string ext = it->path().extension().string();
      std::transform(ext.begin(), ext.end(), ext.begin(), [](unsigned char c) { return std::tolower(c); });
      if (ext != ".bcstm") {
        continue;
      }
      Song song{it->path().string(), {}};
      if (!ReadStreamHeader(song.path, song.header)) {
        reportLines.push_back("REJECTED (not a valid CSTM file): " + song.path);
        continue;
      }
      songs.push_back(std::move(song));
    }
    // Directory order isn't guaranteed; sort so the same library always gives the same assignment.
    std::sort(songs.begin(), songs.end(), [](const Song& a, const Song& b) { return a.path < b.path; });
    return songs;
  }

  static bool Fits(const Song& s, const StreamSlot& slot) {
    return s.header.codec == 2 && s.header.channels == 2 && s.header.loops == slot.loops;
  }

  // Explains why a song fits none of the given slots. `target` names them for the report,
  // e.g. "Termina Field" or "every slot in Fanfares".
  static std::string RejectReason(const Song& s, const std::vector<size_t>& slots, const std::string& target) {
    const StreamHeader& h = s.header;
    if (h.codec != 2) {
      return "codec " + std::to_string(h.codec) + ", needs DSP-ADPCM";
    }
    if (h.channels != 2) {
      return std::to_string(h.channels) + (h.channels == 1 ? " channel" : " channels") + ", needs 2";
    }
    if (slots.empty()) {
      return "no replaceable slot";
    }
    return h.loops ? "loops, but " + target + " expects a one-shot"
                   : "does not loop, but " + target + " expects a looping song";
  }

  /*-------------------
  |    ASSIGNMENT     |
  -------------------*/

  void Reset() {
    assignments.fill({});
    reportLines.clear();
  }

  void Assign(bool customOnly) {
    for (const rnd::SeqType cat : musicCategories) {
      const std::string catName = Music::CategoryFolder(cat);
      const std::string catDir = musicRoot + catName + "/";

      std::vector<size_t> slots;  // eligible slots in this category
      for (size_t i = 0; i < BGM_COUNT; i++) {
        if (IsAssignable(streamSlots[i]) && streamSlots[i].category == cat) {
          slots.push_back(i);
        }
      }
      Shuffle(slots);  // so ties and leftovers don't always favour low indices

      // 1. Slot folders
      for (const size_t i : slots) {
        const StreamSlot& slot = streamSlots[i];
        std::vector<Song> own;
        for (Song& song : ScanFolder(catDir + slot.displayName + "/")) {
          if (Fits(song, slot)) {
            own.push_back(std::move(song));
          } else {
            reportLines.push_back("REJECTED (" + RejectReason(song, {i}, slot.displayName) + "): " + song.path);
          }
        }
        if (!own.empty()) {
          assignments[i] = RandomElement(own).path;
        }
      }

      // 2. Category folder
      std::vector<Song> pool;
      for (Song& song : ScanFolder(catDir)) {
        const bool fitsAny = std::any_of(slots.begin(), slots.end(),
                                         [&](size_t i) { return Fits(song, streamSlots[i]); });
        if (fitsAny) {
          pool.push_back(std::move(song));
        } else {
          reportLines.push_back("REJECTED (" + RejectReason(song, slots, "every slot in " + catName) + "): " + song.path);
        }
      }

      std::vector<bool> used(pool.size(), false);
      std::vector<size_t> available(pool.size());  // indices into pool that may still be drawn
      for (size_t k = 0; k < pool.size(); k++) {
        available[k] = k;
      }
      for (const size_t i : slots) {
        if (!assignments[i].empty()) {
          continue;
        }
        std::vector<size_t> fit;  // positions in `available`
        for (size_t a = 0; a < available.size(); a++) {
          if (Fits(pool[available[a]], streamSlots[i])) {
            fit.push_back(a);
          }
        }
        if (fit.empty()) {
          continue;
        }
        const size_t a = RandomElement(fit);
        const size_t k = available[a];
        assignments[i] = pool[k].path;
        used[k] = true;
        if (!customOnly) {
          available.erase(available.begin() + a);
        }
      }

      for (size_t k = 0; k < pool.size(); k++) {
        if (!used[k]) {
          reportLines.push_back("UNUSED (no free " + catName + " slot left for it): " + pool[k].path);
        }
      }
    }
  }

  /*-------------------
  |    DIRECTORIES    |
  -------------------*/

  void CreateDirectories(FS_Archive sdmcArchive) {
    Handle dir;
    if (R_SUCCEEDED(FSUSER_OpenDirectory(&dir, sdmcArchive, fsMakePath(PATH_ASCII, "/MM3DR/Custom Music")))) {
      FSDIR_Close(dir);
      return;
    }

    std::vector<std::string> dirs = {"/MM3DR/", musicRoot};
    for (const rnd::SeqType cat : musicCategories) {
      dirs.push_back(musicRoot + Music::CategoryFolder(cat) + "/");
    }
    for (const StreamSlot& slot : streamSlots) {
      if (IsAssignable(slot)) {
        dirs.push_back(musicRoot + Music::CategoryFolder(slot.category) + "/" + slot.displayName + "/");
      }
    }

    const auto printInfo = [&](size_t progress) {
      consoleClear();
      printf("\x1b[10;10HCreating Custom Music Directories");
      printf("\x1b[11;10HProgress: %zu/%zu", progress, dirs.size());
    };

    printInfo(0);
    for (size_t i = 0; i < dirs.size(); i++) {
      FSUSER_CreateDirectory(sdmcArchive, fsMakePath(PATH_ASCII, dirs[i].c_str()), FS_ATTRIBUTE_DIRECTORY);
      printInfo(i + 1);
    }
  }

  /*-------------------
  |     PLACEMENT     |
  -------------------*/

  static bool FileExists(const std::string& path) {
    struct stat st;
    return stat(path.c_str(), &st) == 0;
  }

  static u64 FileSize(const std::string& path) {
    struct stat st;
    return stat(path.c_str(), &st) == 0 ? static_cast<u64>(st.st_size) : 0;
  }


  static void CleanUpPrevious(FS_Archive sdmcArchive, const std::string& lumaSdDir) {
    const std::string manifestPath = lumaSdDir + manifestName;
    const std::string streamDir = lumaSdDir + musicStreamDir;
    if (auto manifest = FILEPtr{std::fopen(manifestPath.c_str(), "r"), std::fclose}) {
      char line[512];
      while (std::fgets(line, sizeof(line), manifest.get())) {
        std::string path = line;
        while (!path.empty() && (path.back() == '\n' || path.back() == '\r')) {
          path.pop_back();
        }
        if (path.rfind(streamDir, 0) == 0 && path.find("..") == std::string::npos) {
          FSUSER_DeleteFile(sdmcArchive, fsMakePath(PATH_ASCII, path.c_str()));
        }
      }
    }
    FSUSER_DeleteFile(sdmcArchive, fsMakePath(PATH_ASCII, manifestPath.c_str()));
  }

  static void WriteReport(const std::vector<std::string>& placedLines) {
    auto report = FILEPtr{std::fopen(reportPath.c_str(), "w"), std::fclose};
    if (!report) {
      return;
    }
    std::fprintf(report.get(), "Custom Music report for seed %s\n\n", Settings::seed.c_str());
    std::fprintf(report.get(), "Placed (%zu):\n", placedLines.size());
    for (const std::string& line : placedLines) {
      std::fprintf(report.get(), "  %s\n", line.c_str());
    }
    std::fprintf(report.get(), "\nNotes (%zu):\n", reportLines.size());
    for (const std::string& line : reportLines) {
      std::fprintf(report.get(), "  %s\n", line.c_str());
    }
  }

  bool Place(FS_Archive sdmcArchive, const std::string& lumaSdDir) {
    // 1. Directories
    for (const char* sub : {"/romfs", "/romfs/sound", "/romfs/sound/streaming", "/romfs/sound/streaming/stream"}) {
      FSUSER_CreateDirectory(sdmcArchive, fsMakePath(PATH_ASCII, (lumaSdDir + sub).c_str()), FS_ATTRIBUTE_DIRECTORY);
    }

    // 2. Always undo the previous generation, so turning the option off restores vanilla
    CleanUpPrevious(sdmcArchive, lumaSdDir);

    // 3.
    if (!Settings::CustomMusic) {
      return true;
    }

    // 4. Placement list, grouped so a slot and its linked mirrors succeed or get skipped together
    struct Copy {
      size_t slot;
      std::string src;
      std::string dst;
    };
    std::vector<std::vector<Copy>> groups;
    for (size_t i = 0; i < BGM_COUNT; i++) {
      if (assignments[i].empty()) {
        continue;
      }
      std::vector<Copy> group;
      group.push_back({i, assignments[i], lumaSdDir + musicStreamDir + streamSlots[i].file});
      for (size_t j = 0; j < BGM_COUNT; j++) {
        if (streamSlots[j].linkedTo == i && streamSlots[j].file != nullptr) {
          group.push_back({j, assignments[i], lumaSdDir + musicStreamDir + streamSlots[j].file});
        }
      }
      groups.push_back(std::move(group));
    }

    // 5. Anything still at a destination after cleanup was put there by the user. Leave it alone.
    std::vector<Copy> copies;
    for (const auto& group : groups) {
      bool foreign = false;
      for (const Copy& c : group) {
        if (FileExists(c.dst)) {
          reportLines.push_back("SKIPPED (existing file not written by the randomizer): " + c.dst);
          foreign = true;
        }
      }
      if (!foreign) {
        copies.insert(copies.end(), group.begin(), group.end());
      }
    }

    std::vector<std::string> placedLines;
    if (!copies.empty()) {
      // 6. Free space
      u64 needed = 0;
      for (const Copy& c : copies) {
        needed += FileSize(c.src);
      }
      FS_ArchiveResource res{};
      if (R_SUCCEEDED(FSUSER_GetArchiveResource(&res, SYSTEM_MEDIATYPE_SD))) {
        const u64 freeBytes = static_cast<u64>(res.freeClusters) * res.clusterSize;
        if (needed > freeBytes) {
          reportLines.push_back("NOTHING PLACED: songs need " + std::to_string(needed / 1024) + " KB but the SD card has " +
                                std::to_string(freeBytes / 1024) + " KB free");
          copies.clear();
        }
      }
    }

    if (!copies.empty()) {
      // 7. Manifest first, so a copy interrupted by power loss still gets cleaned up next time
      const std::string manifestPath = lumaSdDir + manifestName;
      if (auto manifest = FILEPtr{std::fopen(manifestPath.c_str(), "w"), std::fclose}) {
        for (const Copy& c : copies) {
          std::fprintf(manifest.get(), "%s\n", c.dst.c_str());
        }
      } else {
        reportLines.push_back("NOTHING PLACED: could not write " + manifestPath);
        copies.clear();
      }
    }

    // 8. Copy
    for (size_t n = 0; n < copies.size(); n++) {
      const Copy& c = copies[n];
      printf("\x1b[14;10HCustom Music: %zu/%zu", n + 1, copies.size());
      if (CopyFileChunked(sdmcArchive, c.dst.c_str(), c.src.c_str())) {
        placedLines.push_back(std::string(streamSlots[c.slot].displayName) + " <- " + c.src);
      } else {
        reportLines.push_back("FAILED (copy error): " + c.src + " -> " + c.dst);
      }
    }
    printf("\x1b[14;10H%30s", "");

    // 9. Report
    WriteReport(placedLines);
    return true;
  }
}  // namespace CustomMusic
