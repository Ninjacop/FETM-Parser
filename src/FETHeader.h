#ifndef FETHEADER_H
#define FETHEADER_H

#include "../lib/libs.h"

class FETHeader {
  private:
    char filetype;
    std::string metadata;

  public:
    FETHeader();
    FETHeader(char filetype, std::string metadata);
    FETHeader getHeader();
    void setHeader(char filetype, std::string metadata);
    char getFiletype();
    void setFiletype(char filetype);
    std::string getMetadata();
    void setMetadata(std::string metadata);
};

#endif