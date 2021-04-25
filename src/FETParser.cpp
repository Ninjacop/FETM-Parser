// FETParser.cpp
// Created 24 March 2021
#include "FETParser.h"
#define FET_DESC_LENGTH 2
#define BUFFER_LEN 100

// FETParser::parseHeader(std::string filename)
// Opens a file with a given FETM filename. Then, go byte by byte
// through the file, evaluating and storing different types based
// on identifiers. A FETM header consists of one byte that encodes
// for the file, followed by a string of metadata.
FETHeader FETParser::parseHeader(std::string filename) {
  std::ifstream fetfile;
  char buffer[BUFFER_LEN];
  FETHeader feth;

  fetfile.open(filename, std::ios::binary);
  if (!fetfile.is_open()) {
    std::cout << "Could not open .FETM file" << std::endl;
    exit(1);
  }

  if (fetfile.read(buffer, BUFFER_LEN)) {
    for (int i = 0; i < BUFFER_LEN; i++) {
      switch (buffer[i]) {
        case Types::UnsignedChar:
          feth.setFiletype((char)getUnsignedChar(std::string(buffer), i));
          break;
        case Types::String:
          feth.setMetadata(getString(std::string(buffer), i));
          return feth;
        default:
          break;
        }
    }
  }
                               
  return feth;
}

Node FETParser::getNextToken(std::string str, int pos) {
  switch (str[pos]) {
    case Char:
    case UnsignedChar: 
      break;
  default:
    break;
  }

  Node node;
  node.setType(Char);

  return node;
}

// FETParser::getUnsignedChar(std::string str, int pos)
// Get the next byte in a given string, marked in 
// FETParser::parseHeader()
unsigned char FETParser::getUnsignedChar(std::string str, int pos) {
  return (unsigned char)str[pos+1];
}

// FETParser::getString(std::string str, int pos)
// Continuously feed bytes from a given C string into a 
// str::string, starting at a specific position. 
std::string FETParser::getString(std::string str, int pos) {
  std::string returnString;

  while (str[pos] != '\0') {
    returnString += str[pos];
    pos++;
  }

  return returnString;
}
