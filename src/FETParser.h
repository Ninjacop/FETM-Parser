#ifndef SRC_FETPARSER_H
#define SRC_FETPARSER_H

#include "../lib/libs.h"
#include "FETHeader.h"
#include "Node.h"

class FETParser {
  private:
    std::ifstream fetfile;
    std::vector<Node> nodelist;

  public:
    FETHeader parseHeader(std::string filename);
    unsigned char getUnsignedChar(std::string str, int pos);
    unsigned short getUnsignedShort(std::string str, int pos);
    std::string getString(std::string str, int pos);
    Node getNextToken(std::string str, int pos);
};

#endif
