// main.cpp
// Created 24 March 2021

#include "lib/libs.h"
#include "src/FETParser.h"


// Enters the FETM file parser program
int main(int argc, char* argv[]) {
  FETParser fetp;
  FETHeader feth;
  std::string filename;

  if (argc != 2) {
    std::cout << ".FETM file not supplied." << std::endl;
    exit(1);
  }

  feth = fetp.parseHeader(std::string(argv[1]));
  std::cout << "Is .FETM file? (has 0x7C): " <<
    (feth.getFiletype() == (char)0x7C ? "Yes" : "No") << std::endl;
  std::cout << "Metadata: " << feth.getMetadata() << std::endl;

  return 0;
}
