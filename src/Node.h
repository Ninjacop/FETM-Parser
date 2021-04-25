#ifndef NODE_H
#define NODE_H

#include "../lib/libs.h"

// Various identifiers/types used in FETM files 
enum Types {
  Char = 0x00,
  UnsignedChar = 0x01, // reads one byte, 0x00
  Short = 0x02,
  UnsignedShort = 0x03, // reads two bytes, 0x0000
  Int = 0x04,
  Hex = 0x05,
  Float = 0x06,
  String = 0x07
};

class Node {
  private:
    Types type;
    std::variant<int, float, std::string> data;

  public:

    Node() {
      
    }

    Node(Types type, std::variant<int, float, std::string> data) {
      this->type = type;
      this->data = data;
    }

    Node getNode() {
      return *this;
    }

    void setNode(Types type, std::variant<int, float, std::string> data) {
      this->type = type;
      this->data = data;
    }

    Types getType() {
      return this->type;
    }

    void setType(Types type) {
      this->type = type;
    }

    std::variant<int, float, std::string> getData() {
      return this->data;
    }

    void setData(std::variant<int, float, std::string> data) {
      this->data = data;
    }
};

#endif