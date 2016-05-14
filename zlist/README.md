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

`void push\_front(zType const &);`
Add a new element to the front of the list.
Complexity: constant

`void push\_back(zType const &);`
Add a new element to the back of the list.
Complexity : O(1)

<br />

## Remove element :

### void pop\_front();

Remove the first element. <br />
Complexity : O(1)

### void pop\_back();

Remove the last element. <br />
Complexity : O(1)

### void erase();

Remove all the element from the list. This member function iterate
through the linked list and destroy and the nodes. <br />
Complexity : O(n)

<br />

## Element acces :

### front() middle() tail()

The 3 methodes returns a reference to the front, middle and tail
element in the list container. <br />
Both front() and tail() member function have a constant complexity
except for middle() which is O(n). <br />

<br />

## Capacity :

### size\_t size() const;

Return the number of element in the list. <br />
Complexity : O(1)

### bool empty() const;

Return true if the list is empty. <br />
Complexity : O(1)

<br />

## Iterators (Forward iterator only. More coming&#x2026;) :

### Iterator begin();

Return an iterator who pointing to the first element of the list. <br />
Complexity : O(1)

### Iterator end();

Return an iterator who pointing to the past end of the list
which is null. <br />
Complexity : O(1)

<br />

## Operations :

### void reverse();

Reverse all the elements of the list. The head becomes the tail
and the tail becomes the head.<br />
Complexity : O(n)

### void swap(Zlist &instance);

Exchange all the content of the container by the content of
'instance'. After this call, the content of 'this' are those of
'instance'. <br />
Complexity : O(1)
