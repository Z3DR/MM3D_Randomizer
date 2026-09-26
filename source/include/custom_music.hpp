#pragma once

#include <3ds.h>

#include <array>
#include <string>
#include <vector>

#include "rnd/music.h"


namespace CustomMusic {
  // index -> song path for this seed; empty = leave vanilla. Linked slots are NOT filled here.
  extern std::array<std::string, BGM_COUNT> assignments;
  extern std::vector<std::string> reportLines;

  void Reset();
  void CreateDirectories(FS_Archive sdmcArchive);
  void Assign(bool customOnly);
  bool Place(FS_Archive sdmcArchive, const std::string& lumaSdDir);
}  // namespace CustomMusic
