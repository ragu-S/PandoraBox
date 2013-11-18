/*
* A doubly linked list program meant to show how link lists work, as well as what methods are needed, and can be useful for doubly linked lists
* By Ragu S.
* Date: Nov 17, 2013
* Course: OOP344B
*/

#include "LinkList.h"
using namespace std;

Node::Node(){
  _prev = _next = NULL;
  _data = 0;
}

Node::Node(int data) : _data(data){
  _prev = _next = NULL;
}

Node::~Node(){
}

List::List(){
  _head = new Node(0);
  _tail = _cur = _head;
  _head->_prev = NULL;
  _head->_next = NULL;
}

// This function adds a node to the front of the tail
void List::add_tail(int data){
  _cur = new Node(data);
  _cur->_next = NULL;
  _tail->_next = _cur;
  _cur->_prev = _tail;
  _tail = _cur;
}


// This function adds a node to the front of the head
void List::add_head(int data){
  _cur = new Node(data);
  _cur->_prev = NULL;
  _head->_prev = _cur;
  _cur->_next = _head;
  _head = _cur;
}

// This function removes a node from the head of the list
int List::remove_head(){
  int value = 0;
  if(_head)
    value = _head->_data;
  _cur = _head->_next;
  _cur->_prev = NULL;
  delete _head;
  _head = _cur;
  return value;
}

// This function removes a node from the tail, returning an int value
int List::remove_tail(){
  int value = 0;
  if(_tail)
    _tail->_data;
  _cur = _tail->_prev;
  _cur->_next = NULL;
  delete _tail;
  _tail = _cur;
  return value;
}

// This function returns an int value from the head
int List::retrieveFromHead(){
  return _head ? _head->_data : 0;
}

// This function returns an int value from the tail
int List::retrieveFromTail(){
  return _tail ? _tail->_data : 0;
}

// Moves current to head, each time this function is called it will move current across the list, returns true if it can continue to move
bool List::goFromHead(){
  bool canMove = true;
  if(!_cur->_prev){
    _cur = _head;
  }
  if(_cur)
    _cur = _cur->_next;
  else 
    canMove = false;
  return canMove;
}

// Moves current from tail, towards head, returns true if it can continue to move along the list
bool List::goFromTail(){
  bool canMove = true;
   if(!_cur->_next){
    _cur = _tail;
  }
  if(_cur){
   _cur = _cur->_next;
  }
  else
    canMove = false;
  return canMove;
}

// Displays the list, using ostream
ostream& List::display(ostream& os){
  _cur = _head;
  while(_cur){
    os << _cur->_data << " ";
    _cur = _cur->_next;
  }
  return os;
}

// Overloaded extraction operator, calls display function on a list object recieved by reference
ostream& operator<<(std::ostream& os, List& l){
  return l.display(os);
}

// List destructor, starts at head and continues towards tail
List::~List(){
  int i=1;
  Node* temp = _head;
  while (temp){
    temp = temp->_next;
    delete _head;
    _head = temp;
    cout << "deleted _cur " << i++ <<endl;
  }
}