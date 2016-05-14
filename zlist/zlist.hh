// Author: zagabe.ed@gmail.com (Eddy Zagabe)
//
// Zlist implementation which is a linked list. A data structure
// that can hold an arbitrary number of data item.

#ifndef ZLIST_HH_
#define ZLIST_HH_

#include <string>  // for size_t

// Zlist class definition
template <typename zType>
class Zlist {
 private:
  // Definition of a node
  struct Node {
    zType data;
    struct Node *next;
    struct Node *prev;
  };
  
 public:
  // Constructor
  Zlist() : count_(0), phead_(nullptr), ptail_(nullptr) {}

  // Desctructor
  virtual ~Zlist() {
    struct Node *prev = nullptr;
    struct Node *curr = phead_;
    
    while (curr) {
      prev = curr;
      curr = curr->next;
      delete prev;
    }
  }

  // Return the number of elements in the list.
  size_t size() const { return (count_); }

  // Return true if the list is empty
  bool empty() const { return (count_ == 0 ? true : false); }

  // Access to the front of the list
  zType front() const { return (phead_ ? phead_->data : 0); }

  // Access to the middle element of the list
  zType middle() const;

  // Access to the last element of the list
  zType tail() const { return (ptail_ ? ptail_->data : 0); }

  // Add an element to the front of the list
  void push_front(const zType &item);

  // Add an element to the back of the list
  void push_back(const zType &item);

  // Remove the first element of the list
  void pop_front();

  // Remove the last element of the list
  void pop_back();

  // Remove on element from the list
  void erase(const zType &data);
  
  // Remove all the elements from the list
  void clear();

  // Reverse all the elements of the list. The head becomes the tail
  // and the tail becomes the head.
  void reverse();

  // Swap two instances of Zlist
  void swap(Zlist &list);

  // Implementation of a class Iterator who helps you iterate through
  // the list. (Forward iteratation)
  class Iterator {
   public:
    // Constructor
    Iterator(struct Node *node) : node_(node) {}

    // Desctructor
    ~Iterator() {}

    // Return a reference to the node
    struct Node *getNode() { return node_; }
    
    // Overload operator= for the iterator
    Iterator &operator=(const Iterator &other) {
      node_ = other.node_;
      return *this;
    }

    // Return true if the two iterators are equals
    bool operator==(const Iterator &other) { return node_ == other.node_; }

    // Return true if the two iterator are different
    bool operator!=(const Iterator &other) { return node_ != other.node_; }

    // Move the iterator to the next element
    Iterator &operator++() {
      if (node_) node_ = node_->next;
      return *this;
    }

    // Move the iterator to the next element
    Iterator &operator++(int) {
      ++(*this);
      return *this;
    }

    // Return the target data by the iterator
    zType &operator*() { return node_->data; }

   private:
    // Iterator's pointer who iterate through the linked list
    struct Node *node_;
  };

  // Initializes and return an iterator pointing the head of the list
  Iterator begin() { return Iterator(phead_); }

  // Return null
  Iterator end() { return Iterator(NULL); }

  // Remove one element from the list specified by the index
  void erase(const Zlist<zType>::Iterator &ite);

 private:
  // Store the number of elements in the list.
  int count_;

  // Pointer to the head of the list
  struct Node *phead_;

  // Pointer to the tail of the list
  struct Node *ptail_;

  // Delete a node and decrement the counter
  void delete_node(int pos, struct Node *prev, struct Node *curr) {
    if (pos == 0) phead_ = curr->next;
    if (pos == count_ - 1) ptail_ = prev;
    prev->next = curr->next;
    delete curr;
    count_--;
    if (count_ == 0) {
      phead_ = nullptr;
      ptail_ = nullptr;
    }
  }
};

// Add an element to the front of the list
template <typename zType>
void Zlist<zType>::push_front(zType const &item) {
  struct Node *node = new Node;

  node->data = item;
  node->next = phead_;
  node->prev = nullptr;
  if (phead_) phead_->prev = node;
  phead_ = node;
  if (count_ == 0) ptail_ = node;
  count_++;
}

// Add an element to the back of the list
template <typename zType>
void Zlist<zType>::push_back(zType const &item) {
  struct Node *node = new Node;

  node->data = item;
  node->next = nullptr;
  node->prev = ptail_;
  if (count_ == 0) {
    ptail_ = node;
    phead_ = node;
  } else {
    ptail_->next = node;
    ptail_ = node;
  }
  count_++;
}

// Remove the first element of the list
template <typename zType>
void Zlist<zType>::pop_front() {
  struct Node *tmp;

  if (count_ <= 0 || !phead_) return;
  tmp = phead_;
  phead_ = tmp->next;
  if (phead_) phead_->prev = nullptr;
  delete tmp;
  count_--;
  if (count_ == 0) phead_ = 0;
}

// Remove the last element of the list
template <typename zType>
void Zlist<zType>::pop_back() {
  struct Node *tmp;

  if (count_ <= 0 || !phead_) return;
  tmp = ptail_;
  ptail_ = tmp->prev;
  if (ptail_) ptail_->next = nullptr;
  delete tmp;
  count_--;
  if (count_ == 0) phead_ = nullptr;
}

// Remove one element from the list specified by the index
template <typename zType>
void Zlist<zType>::erase(const Zlist<zType>::Iterator &ite) {
  struct Node *prev = phead_;
  struct Node *curr = phead_;

  if (!phead_) return;
  for (int c = 0; curr; curr = curr->next, c++) {
    if (curr == ite.getNode())
      delete_node(c, prev, curr);
  }
}

// Remove one element from the list
template <typename zType>
void Zlist<zType>::erase(const zType &data) {
  struct Node *prev = phead_;
  struct Node *curr = phead_;

  for (; curr; curr = curr->next) {
    if (curr->data == data)
      delete_node(prev, curr);
  }
}

// Remove all the elements of the list
template <typename zType>
void Zlist<zType>::clear() {
  struct Node *prev = nullptr;

  for (struct Node *tmp = phead_; tmp; tmp = tmp->next) {
    prev = tmp;
    tmp = tmp->next;
    delete prev;
  }
  phead_ = nullptr;
  ptail_ = nullptr;
  count_ = 0;
}

// Access to the middle element of the list
template <class zType>
zType Zlist<zType>::middle() const {
  struct Node *mid = phead_;
  int count = 0;

  for (struct Node *tmp = phead_; tmp; tmp = tmp->next) {
    if (count & 1) mid = mid->next;
    count++;
  }
  return mid;
}

// Reverse the elements of the list
template <class zType>
void Zlist<zType>::reverse() {
  struct Node *next;
  struct Node *prev = nullptr;

  if (!phead_ || count_ <= 1) return;
  ptail_ = phead_;
  for (struct Node *current = phead_; current; current = next) {
    next = current->next;
    current->next = prev;
    prev = current;
  }
  phead_ = prev;
}

// Swap two instances of Zlist
template <class zType>
void Zlist<zType>::swap(Zlist &list) {
  struct Node *pheadTmp;
  struct Node *ptailTmp;
  int count;

  pheadTmp = list.phead_;
  ptailTmp = list.ptail_;
  count = list.count_;
  list.phead_ = phead_;
  list.ptail_ = ptail_;
  list.count_ = count_;
  phead_ = pheadTmp;
  ptail_ = ptailTmp;
  count_ = count;
}

#endif  // ZLISH_HH_
