#include "cosmetics.hpp"
#include "random.hpp"
#include <iomanip>
#include <sstream>
#include <3ds.h>

namespace Cosmetics {

  bool ValidHexString(std::string_view hexStr) {
    return hexStr.find_first_not_of("0123456789ABCDEFabcdef") == std::string_view::npos && hexStr.length() == 6;
  }

  Color_RGB HexStrToColorRGB(const std::string& hexStr) {
    u32 hex = std::stoi(hexStr, nullptr, 16);

    return Color_RGB{
      .r = ((hex & 0xFF0000) >> 16) / 255.0f,
      .g = ((hex & 0x00FF00) >> 8)  / 255.0f,
      .b = (hex & 0x0000FF) / 255.0f,
      .a = 1.0f,
    };
  }

  std::string CustomColorOptionText(std::string_view color) {
    return std::string(CUSTOM_COLOR_STR.substr(0, CUSTOM_COLOR_STR.length() - 6)).append(color);
  }

  std::string GetCustomColor(const std::string& str) {
    return str.substr(str.length() - 6);
  }

  const std::array<std::string_view, 31> tunicColors = {
    "168A0E", //Kokiri Green
    "96000E", //Goron Red
    "002A8E", //Zora Blue
    "303030", //Black
    "FFFFFF", //White
    "139ED8", //Azure Blue
    "13E9D8", //Vivid Cyan
    "C23333", //Light Red
    "D10044", //Fuchsia
    "8C008C", //Purple
    "400040", //Majora Purple
    "641E7F", //Twitch Purple
    "AA0565", //Magenta
    "710093", //Violet
    "E9144A", //Persian Rose
    "E5DA32", //Dirty Yellow
    "FF7FED", //Blush Pink
    "D92994", //Hot Pink
    "DB557F", //Rose Pink
    "DD3E00", //Orange
    "808080", //Gray
    "CECE00", //Yellow
    "A3C0C0", //Silver
    "FF794E", //Beige
    "00CA65", //Teal
    "400000", //Blood Red
    "CE2500", //Blood Orange
    "000070", //Royal Blue
    "00D000", //NES Green
    "005218", //Dark Green
    "0F50BC", //Lumen
  };

  // Names of tunicColors, in the same order.
  const std::array<std::string_view, 31> tunicColorNames = {
    "Kokiri Green", "Goron Red",    "Zora Blue",    "Black",        "White",      "Azure Blue", "Vivid Cyan",
    "Light Red",    "Fuchsia",      "Purple",       "Majora Purple", "Twitch Purple", "Magenta", "Violet",
    "Persian Rose", "Dirty Yellow", "Blush Pink",   "Hot Pink",     "Rose Pink",  "Orange",     "Gray",
    "Yellow",       "Silver",       "Beige",        "Teal",         "Blood Red",  "Blood Orange", "Royal Blue",
    "NES Green",    "Dark Green",   "Lumen",
  };

  //Generate random hex color
  std::string RandomColor() {
    std::ostringstream color;
    //use default rand to not interfere with main settings
    // Uppercase and setfill to ensure that we have a full 6 hexadecimal value.
    color << std::uppercase << std::hex << std::setw(6) << std::setfill('0') << (rand() % 0x1000000);
    return color.str();
  }

} //namespace Cosmetics
