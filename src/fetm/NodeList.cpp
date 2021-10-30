#include "NodeList.h"

/**
 * Default constructor for NodeList. Initializes the node list
 * and sets the size to 0.
 */ 
NodeList::NodeList() {
  list = std::vector<Node>();
  size = 0;
}

/**
 * Extended constructor for NodeList. Initializes the node list,
 * sets the size to a user defined value, and then reserves
 * that amount of elements in the list.
 */
NodeList::NodeList(int size) {
  NodeList();
  this->size = size;
  list.reserve(size);
}

/**
 * Default deconstructor for NodeList.
 */ 
NodeList::~NodeList() {

}

/**
 * Get a node located at a certain index.
 * 
 * @param idx index of element to return.
 * @return the node located at the requested index.
 */ 
NodeList::Node NodeList::get(int idx) {
  if (idx < 0 || idx >= list.size()) {
    return NodeList::Node();
  }

  return list.at(idx);
}

/**
 * Set the element at a certain index to a new node.
 * Cannot append new nodes to the list.
 * 
 * @param idx index of element to set.
 * @param node new node to set at the requested index.
 */
void NodeList::set(int idx, NodeList::Node node) {
  if (idx >= 0 && idx < list.size()) {
    list.at(idx) = node;
  }
}

/**
 * Add a node to the end of the node list.
 * 
 * @param node node to add.
 */
void NodeList::add(NodeList::Node node) {
  list.push_back(node);
}

/**
 * Add a node at a certain index. The node located at the 
 * requested index and all nodes after are shifted right,
 * and then the node is inserted.
 * 
 * @param idx index to add the node.
 * @param node node to add.
 */ 
void NodeList::add(int idx, NodeList::Node node) {
  if (idx >= 0 && idx < list.size()) {
    std::vector<NodeList::Node>::iterator it = list.begin() + idx;
    list.insert(it, node);
  }
}

/**
 * Remove a node at a certain index.
 * 
 * @param idx index of the element to remove.
 * @return removed element if removed, invalid node if not.
 */ 
NodeList::Node NodeList::remove(int idx) {
  if (idx >= 0 && idx < list.size()) {
    NodeList::Node node_to_delete = list.at(idx);
    list.erase(list.begin() + idx);
    list.shrink_to_fit();
    
    return node_to_delete;
  }

  return NodeList::Node();
}

/**
 * Get the current size of the node list.
 */ 
int NodeList::get_size() {
  return list.size();
}

/**
 * Default constructor for Node. Sets the type to invalid (0xFF) 
 * and the data to an invalid character (0xFF).
 */ 
NodeList::Node::Node() {
  type = Types::Invalid;
  data = std::vector<char>(Invalid);
}

/**
 * Extended constructor for Node. Sets the type and data to a user
 * defined value.
 */ 
NodeList::Node::Node(Types type, std::vector<char> data) {
  this->type = type;
  this->data = data;
}

/**
 * Default deconstructor for Node.
 */
NodeList::Node::~Node() {

}

/**
 * Set the type of a node.
 * 
 * @param type type to set.
 */
void NodeList::Node::set_type(Types type) {
  this->type = type;
}

/**
 * Get the type of a node.
 * 
 * @return the type of a node.
 */ 
Types NodeList::Node::get_type() {
  return type;
}

/**
 * Set the data of a node.
 * 
 * @param data new data to insert into the node.
 */ 
void NodeList::Node::set_data(std::vector<char> data) {
  this->data = data;
}

/**
 * Get the data of a node.
 *
 * @return the data of a node.
 */ 
std::vector<char> NodeList::Node::get_data() {
  return data;
}