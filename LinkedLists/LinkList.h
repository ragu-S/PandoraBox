/*
* A doubly linked list program meant to show how link lists work, as well as what methods are needed, and can be useful for doubly linked lists
* By Ragu S.
* Date: Nov 17, 2013
* Course: OOP344B
*/

#include <iostream>

class Node {
  class List;
public:
  int _data;
  Node();
  Node(int);
  Node* _prev;
  Node* _next;
  ~Node();
  friend class List;
};

class List {
  Node* _head;
  Node* _tail;
  Node* _cur;
public:
  List();
  void add_head(int);
  void add_tail(int);
  std::ostream& display(std::ostream& os);

  bool goFromHead();
  bool goFromTail();
  Node* gotTo(int);

  int retrieveFromHead();
  int retrieveFromTail();

  int remove_head();
  int remove_tail();
  ~List();
};

std::ostream& operator<<(std::ostream& os, List& l);