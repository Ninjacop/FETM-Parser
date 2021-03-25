#ifndef SRC_FETPARSER_HPP
#define SRC_FETPARSER_HPP

#include "../lib/libs.hpp"

typedef struct {
  unsigned char filetype;
  std::string metadata;
} FETHeader;

// Various identifiers/types used in FETM files 
enum FETTypes {
  Char = 0x00,
  UnsignedChar = 0x01, // reads one byte, 0x00
  Short = 0x02,
  UnsignedShort = 0x03, // reads two bytes, 0x0000
  Int = 0x04,
  Hex = 0x05,
  Float = 0x06,
  String = 0x07
};

class FETParser {
  private:
    std::ifstream fetfile;

  public:
    FETHeader parseHeader(std::string filename);
    unsigned char getUnsignedChar(char* str, int pos);
    unsigned short getUnsignedShort(char* str, int pos);
    std::string getString(char* str, int pos);
};

#endif
