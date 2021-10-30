#include "FETParser.h"

/**
 * Default constructor for FETParser.
 */
FETParser::FETParser() {

}

/**
 * Extended constructor for FETPParser. Opens a FETM file
 * specified by the user, and collects all the nodes.
 */ 
FETParser::FETParser(std::string filename) {
  const int header_length = 3;

  if (!fetfile.is_open()) {
    fetfile.open(filename, std::ios::binary | std::ios::in);
  }

  nodelist = collect_nodes();

  for (int i = 0; i < header_length; i++) {
    for (int j = 0; j < nodelist.get(i).get_data().size(); j++) {
      raw_header.push_back(nodelist.get(i).get_data().at(j));
    }
  }  
} 

/**
 * Default deconstructor for FETParser.
 */ 
FETParser::~FETParser() {

}

/**
 * Close a current FETM file, if open, reset the node list, and open the new file.
 * 
 * @param filename new file to open.
 */ 
void FETParser::set_fetfile(std::string filename) {
  if (fetfile.is_open()) {
    fetfile.close();
    nodelist = NodeList();
  }
  
  fetfile.open(filename, std::ios::binary | std::ios::in);
}

/**
 * Collect all the nodes inside a FETM file.
 * 
 * @return a completed list of nodes.
 */
NodeList FETParser::collect_nodes() {
  NodeList nodes;
  
  while (!fetfile.eof()) {
    nodes.add(next());
  }

  return nodes;
}

/**
 * Get the next node in a FETM file. 
 * 
 * @return the next node in a FETM file.
 */ 
NodeList::Node FETParser::next() {
  NodeList::Node n = NodeList::Node();
  int curr = fetfile.get();

  switch (curr) {
    case Char:
      n.set_type(Char);
      n.set_data(get_char_data());
      break;
    case UnsignedChar:
      n.set_type(UnsignedChar);
      n.set_data(get_uchar_data());
      break;
    case Short:
      n.set_type(Short);
      n.set_data(get_short_data());
      break;
    case UnsignedShort:
      n.set_type(UnsignedShort);
      n.set_data(get_short_data());
      break;
    case Int:
      n.set_type(Int);
      n.set_data(get_int_data());
      break;
    case Hex:
      n.set_type(Hex);
      n.set_data(get_hex_data());
      break;
    case Float:
      n.set_type(Float);
      n.set_data(get_float_data());
      break;
    case String:
      n.set_type(String);
      n.set_data(get_str_data());
      break;
  }

  return n;
}

/**
 * Get the character data from the FETM file currently
 * being read. Should return a vector of a single raw character,
 * as FETM files denote a character as one byte (0x00).
 * 
 * @return a vector of characters encoding a character in hexadecimal for node data. 
 */
std::vector<char> FETParser::get_char_data() {
  std::vector<char> char_data;
  char_data.push_back(fetfile.get());
  return char_data;
}

/**
 * Get the unsigned character data from the FETM file currently
 * being read. Should return a vector of a single raw unsigned character,
 * as FETM files denote a character as one byte (0x00).
 * 
 * @return a vector of characters encoding an unsigned character in hexadecimal for node data. 
 */
std::vector<char> FETParser::get_uchar_data() {
  std::vector<char> uchar_data;
  uchar_data.push_back(fetfile.get());
  return uchar_data;
}

/**
 * Get the short data from the FETM file currently
 * being read. Should return a vector encoding a raw short,
 * as FETM files denote a short as two bytes (0x0000).
 * 
 * @return a vector of characters encoding a short in hexadecimal for node data. 
 */
std::vector<char> FETParser::get_short_data() {
  const int short_length = 2;
  std::vector<char> short_data;
  
  for (int i = 0; i < short_length; i++) {
    short_data.push_back(fetfile.get());
  }

  return short_data;
}

/**
 * Get the usigned short data from the FETM file currently
 * being read. Should return a vector encoding a raw unsigned short,
 * as FETM files denote an unsigned short as two bytes (0x0000).
 * 
 * @return a vector of characters encoding an unsigned short in hexadecimal for node data. 
 */
std::vector<char> FETParser::get_ushort_data() {
  const int ushort_length = 2;
  std::vector<char> ushort_data;
  
  for (int i = 0; i < ushort_length; i++) {
    ushort_data.push_back(fetfile.get());
  }

  return ushort_data;
}

/**
 * Get the integer data from the FETM file currently
 * being read. Should return a vector encoding a raw integer,
 * as FETM files denote an integer as four bytes (0x00000000).
 * 
 * @return a vector of characters encoding an unsigned short in hexadecimal for node data. 
 */
std::vector<char> FETParser::get_int_data() {
  const int int_length = 4;
  std::vector<char> int_data;

  for (int i = 0; i < int_length; i++) {
    int_data.push_back(fetfile.get());
  }

  return int_data;
}

/**
 * Get the hexadecimal data from the FETM file currently
 * being read. Should return a vector encoding a raw hexadecimal value,
 * as FETM files denote a hexadecimal value as four bytes (0x00000000).
 * 
 * @return a vector of characters encoding a hexadecimal value for node data. 
 */
std::vector<char> FETParser::get_hex_data() {
  const int hex_length = 4;
  std::vector<char> hex_data;

  for (int i = 0; i < hex_length; i++) {
    hex_data.push_back(fetfile.get());
  }

  return hex_data;
}

/**
 * Get the float data from the FETM file currently
 * being read. Should return a vector encoding a float value,
 * as FETM files denote a float value as four bytes (0x00000000).
 * TODO say something about the manilla not being encoded, and this is all raw data. 
 * 
 * @return a vector of characters encoding a float value for node data. 
 */
std::vector<char> FETParser::get_float_data() {
  const int float_length = 4;
  std::vector<char> float_data;

  for (int i = 0; i < float_length; i++) {
    float_data.push_back(fetfile.get());
  }

  return float_data;
}

/**
 * Get the string data from the FETM file currently
 * being read. Should return a vector of raw characters,
 * as FETM files read strings by reading in characters until a NULL (0x00)
 * is reached.
 * 
 * @return a vector of characters encoding a string for node data. 
 */
std::vector<char> FETParser::get_str_data() {
  std::vector<char> str;
  int curr = fetfile.get();

  while (curr != 0) {
    str.push_back(curr);
    curr = fetfile.get();
  }

  return str;
}

/**
 * Get the raw header data within a FETM file.
 */ 
std::vector<char> FETParser::get_raw_header_data() {
  return raw_header;
}

/**
 * Get the node list of a FETM file once it has been read.
 * 
 * @return the complete node list of a FETM file.
 */
NodeList FETParser::get_nodes() {
  return nodelist;
}