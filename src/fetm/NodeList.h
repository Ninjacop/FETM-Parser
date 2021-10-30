#ifndef NODELIST_H
#define NODELIST_H

#include "../../lib/libs.h"

/** Various identifiers/types used for nodes in FETM files. */
enum Types {
  Char = 0x00,            // reads one byte, 0x00
  UnsignedChar = 0x01,    // reads one byte, 0x00
  Short = 0x02,           // reads two bytes, 0x0000
  UnsignedShort = 0x03,   // reads two bytes, 0x0000
  Int = 0x04,             // reads four bytes, 0x00000000
  Hex = 0x05,             // reads four bytes, 0x00000000
  Float = 0x06,           // reads four bytes, 0x00000000
  String = 0x07,          // reads until 0x00
  Invalid = 0xFF          // placeholder
};

/**
 * NodeList class. An implementation of an array list made 
 * for FETM nodes. Contains an inner class for nodes, and 
 * a select amount of methods to manipulate the list.
 */  
class NodeList {
  public:
    /**
     * Node class. Contains all data for each chunk of 
     * FETM data read in, contains raw hexadecimal data 
     * as well as a type indicator. 
     */
    class Node {
      private:
        /** Type of data stored in the node. */
        Types type;
        /** Raw data of a FETM file chunk. */
        std::vector<char> data;

      public:
        Node();
        Node(Types type, std::vector<char> data);
        ~Node();
        void set_type(Types type);
        Types get_type();
        void set_data(std::vector<char> data);
        std::vector<char> get_data();
    };

    NodeList();
    NodeList(int size);
    ~NodeList();
    Node get(int idx);
    void set(int idx, Node node);
    void add(Node node);
    void add(int idx, Node node);
    Node remove(int idx);
    int get_size();

    private: 
      /** List to store all nodes. */
      std::vector<Node> list;
      /** Size of the list. */
      int size;
};

#endif