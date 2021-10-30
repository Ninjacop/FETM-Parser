#include "lib/libs.h"
#include "src/fetm/FETParser.h"

// Enters the FETM file parser program
int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "Usage: fetmworks [file to parse]" << std::endl;
    return EXIT_FAILURE;
  }

  FETParser fetp(argv[1]);
  NodeList nlist = fetp.get_nodes();
  std::vector<char> header = fetp.get_raw_header_data();

  for (int i = 0; i < header.size(); i++) {
    std::cout << header.at(i);
  }

  std::cout << std::endl;

  std::cout << nlist.get_size() << std::endl;
}
