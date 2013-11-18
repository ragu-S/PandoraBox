/*
* A doubly linked list program meant to show how link lists work, as well as what methods are needed, and can be useful for doubly linked lists
* By Ragu S.
* Date: Nov 17, 2013
* Course: OOP344B
*/

#include "LinkList.h"
using namespace std;

int main(){
  List a;
  int numNodes = 0;

  //=============================================================
  
  for(int i = 1; i < 5; i++){
    a.add_tail(i*3);
    cout << "adding " << i*3 << endl;
  }
  
  //=============================================================

  for(int i = 1; i < 5; i++){
    a.add_head(i*5);
    cout << "adding " << i*5 << endl;
  }

  //=============================================================

  cout << "Head's value is " << a.retrieveFromHead() << endl;
  cout << "Tail's value is " << a.retrieveFromTail() << endl;
  /*while(a.goFromHead()){
    numNodes++;
  }
  */
  a.remove_head();
  a.remove_tail();

  //=============================================================

  cout << a << endl;
  cout << "The number of nodes is " << numNodes << endl;
  
  return 0;
}