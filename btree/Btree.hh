// Author : zagabe.ed@gmail.com (Eddy ZAGABE)
//
// Implementation of Btree which an binary tree. The class use the
// linked list representation.
// (See README.md for more information)
//

#ifndef BTREE_HH_
#define BTREE_HH_

#include <queue> // for queue class template

// Btree class implementation
template <typename zType>
class Btree {
 private:
  // Node definition
  struct Node {
    zType data;
    struct Node *left;
    struct Node *right;
  };

 public:
  // Constructor
  Btree() : root_(nullptr), nodes_count_(0) {}

  // Desctructor
  ~Btree() {}

  // Add a new node to the tree
  void insert(const zType &data);

  // Return the number of nodes
  const int nodes_count() { return nodes_count_; }

 private:
  // Number of nodes
  int nodes_count_;

  // Root node
  struct Node *root_;

  // References to the next empty nodes
  std::queue<struct Node *> queue_;
  

  // insert_node inserts a new node recusively
  void insert_node(const zType &data);
};

// insert_node inserts a new node recursively
template <typename zType>
void Btree<zType>::insert_node(const zType &data) {
  struct Node *new_node = new struct Node;
  struct Node *tmp;

  new_node->data = data;
  new_node->left = nullptr;
  new_node->right = nullptr;
  if (!root_) {
    root_ = new_node;
    queue_.push(root_);
  } else {
    tmp = queue_.front();
    if (!tmp->left) tmp->left = new_node;
    else tmp->right = new_node;
    if (tmp->left && tmp->right) queue_.pop();
    queue_.push(new_node);
  }
  nodes_count_++;
}

// insert adds a new node to the tree
template <typename zType>
void Btree<zType>::insert(const zType &data) {
  insert_node(data);
}

#endif  // BTREE_HH_
