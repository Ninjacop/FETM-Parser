#ifndef FETPARSER_H
#define FETPARSER_H

#include "../../lib/libs.h"
#include "NodeList.h"

/**
 * FETParser class. Parses a FETM file, 
 * breaking it up into nodes. 
 */ 
class FETParser {
  private:
    /** File to read information from. */
    std::ifstream fetfile;
    /** Raw file header data. */
    std::vector<char> raw_header;
    /** List of collected nodes. */
    NodeList nodelist;

    void set_fetfile(std::string filename);
    NodeList collect_nodes();
    NodeList::Node next();
    std::vector<char> get_char_data();
    std::vector<char> get_uchar_data();
    std::vector<char> get_short_data();
    std::vector<char> get_ushort_data();
    std::vector<char> get_int_data();
    std::vector<char> get_hex_data();
    std::vector<char> get_float_data();
    std::vector<char> get_str_data();
  public: 
    FETParser();
    FETParser(std::string filename);
    ~FETParser();

    std::vector<char> get_raw_header_data();
    NodeList get_nodes();
};

#endif