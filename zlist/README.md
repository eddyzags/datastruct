# Zlist (Linked list)

# Introduction

Zlist is a class that implements a linked list. A list is an
ordered set of data elements, each containing a link to its
successor (and sometimes its predecessor). They are multiple ways
to design a linked list in memory. However, the Zlist use a list.
A linked list is great for storing data when
the number of items is either unknown (which would be possible with
an array but should involve reallocation...)

# Features 

### Modifiers

`void push_front(zType const &);`  
Add a new element to the front of the list.  
Complexity: constant

`void push_back(zType const &);`  
Add a new element to the back of the list.  
Complexity: constant

`void pop_front();`  
Remove the first element of the list.  
Complexity: constant

`void pop_back();`  
Remove the last element of the list.  
Complexity: constant

`void clear();`  
Remove all the elements from the list.  
Complexity: linear

### Access

`zType front() const;`  
Return the first element of the list or null if empty.  
Complexity: constant

`zType middle() const`  
Return the middle element of the list or null if empty.  
Complexity: constant

`zType back() const`  
Return the last element of the list or null if empty.  
Complexity: constant

### Capacity

`size_t size() const;`  
Return the number of element in the list.  
Complexity: constant

`bool empty() const;`
Return true if the list is empty.  
Complexity: constant

### Iterators

`Iterator begin();`  
Return an iterator that points to the first element of the list.  
Complexity: constant

`Iterator end();`  
Return an iterator that points to the past end of the list which is null.  
Complexity: constant

### Operations

`void reverse();`  
Reverse all the elements of the list. The head becomes the tail
and the tail becomes the head.  
Complexity: constant

`void swap(Zlist &list);`
Exchange all the content of the container by the content of
`list`. After this call, the content of the targeted list become that of the caller.  
Complexity: constant
