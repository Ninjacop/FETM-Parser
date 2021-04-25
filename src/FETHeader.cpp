#include "FETHeader.h" 

FETHeader::FETHeader() {
  
}

FETHeader::FETHeader(char filetype, std::string metadata) {
  this->filetype = filetype;
  this->metadata = metadata;
}

FETHeader FETHeader::getHeader() {
  return *this;
}

void FETHeader::setHeader(char filetype, std::string metadata) {
  this->filetype = filetype;
  this->metadata = metadata;
}

char FETHeader::getFiletype() {
  return filetype;
}

void FETHeader::setFiletype(char filetype) {
  this->filetype = filetype;
}

std::string FETHeader::getMetadata() {
  return metadata;
}

void FETHeader::setMetadata(std::string metadata) {
  this->metadata = metadata;
}