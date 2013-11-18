/*
* The purpose of this program is to see how classes and attributes are stored, i.e. with 
* classes memory for variables are placed in a different order than in regular functions,
* including main
* 
* Author: Ragu S.
* Date: Nov 09, 2013
*/
#include <iostream>
using namespace std;

class tester {
public:
	int data1;
	int data[5];
	int data3;
	tester(int a, int b[], int c):data1(a), data3(c){
		for(int i =0; i < 5; i++)
		  data[i] = b[i]; 
	}
	
	void display(){
	  int i = 0;
	  cout << "Address of x is " << &data1 << " and its value is " << data1 << endl;
	  cout << "Address of y is " << &data3 << " and its value is " << data3 << endl;
	  cout << "Address of data array is " << &data << " and its values are " ;
      while(i<5) {
	    cout << data[i++];
	    if(i<5)
	    cout << ", ";
      }
      cout << endl;
      data[5] = 40;
	  data[-1] = 12;
	
	  cout << "Address of x is " << &data1 << " and its value is " << data1 << endl;
	  cout << "Address of y is " << &data3 << " and its value is " << data3 << endl;
	}
};

void someFunction(){
    int x = 6;
	int arry[5] = {1,2,3,4,5};
	int y = 8;
	int i = 0;
	cout << "****************************************************"<<endl;
	cout << "Address of x is " << &x << " and its value is " << x << endl;
	cout << "Address of y is " << &y << " and its value is " << y << endl;
	cout << "Address of arry is " << &arry << " and its values are " ;
	while(i<5) {
	 cout << arry[i++];
	 if(i<5)
	 cout << ", ";
    }
    cout << endl;
	arry[5] = 40;
	arry[-1] = 12;
	
	cout << "Address of x is " << &x << " and its value is " << x << endl;
	cout << "Address of y is " << &y << " and its value is " << y << endl;
	cout << "Address of arry is " << &arry << " and arry[-1] value is " << arry[-1] << endl;
	cout << "****************************************************"<<endl;
}

int main() {
	int array[5] = {1,2,3,4,5};
	tester a(6, array, 8);
	a.display();
	someFunction();
	int x = 6;
	int arry[5] = {1,2,3,4,5};
	int y = 8;
	int i=0;
	
	cout << "****************************************************"<<endl;
	cout << "Address of x is " << &x << " and its value is " << x << endl;
	cout << "Address of y is " << &y << " and its value is " << y << endl;
	cout << "Address of arry is " << &arry << " and its values are "; 
	while(i<5) {
	 cout << arry[i++];
	 if(i<5)
	 cout << ", ";
    }
    cout << endl;
	arry[5] = 40;
	arry[-1] = 12;
	
	cout << "Address of x is " << &x << " and its value is " << x << endl;
	cout << "Address of y is " << &y << " and its value is " << y << endl;
	cout << "Address of arry is " << &arry << " and arry[-1] value is " << arry[-1] << endl;
	
	return 0;
}
