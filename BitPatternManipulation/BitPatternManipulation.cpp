/*
 * The purpose of this program is to demonstrate algorthims that manipulate bit patterns of unsigned 
 * and character values.
 * Coded by Ragu S.
 * For: OOP344 Fall 2013
 * November 28, 2013
*/

#include <iostream>
using namespace std;

// a function that inserts a byte sized bit pattern into an integer bit pattern
void setBits(unsigned int& val, int pos, char num){	
	pos--;
	for(int i = 0; i < 8; i++){
		(num & (1 << i)) ? val |= (1 << (pos+i)) : val &= ~(1<<(pos+i));
    }
}

// recursive function that prints the bits
void displayBits(unsigned int& value, int size){
  if(--size) {
    cout << !!(value & 1 << size);
    if(size%8 == 0){
    	cout << " ";
    }
    displayBits(value, size);
  }
  else {
    cout << !!(value & 1 << size) << endl;
  }
}

// A function that allows for left or right circular shifting, i.e. the bits are placed in the opposite end rather than simply being lost
void circularShift(unsigned int& val, int shift){
	static int count = 0;
	if (shift--){
	 (val = val >> 1)  && (val |= (val << 31 & 1 << 31)) && (displayBits(val, 32),1), circularShift(val, shift); 
    }
    cout << endl;
}

void circular_shift(unsigned int& val, int shift, const char& direction){
	unsigned int val_copy = 0; // this will be used to sort the bits that would otherwise have been lost in the shift
	if(direction == 'r'){ // right shift
	  val_copy |= val << 32 - shift; 
	  val = val >> shift;
	  val |= val_copy;
	}
	else{ // left shift
	  val_copy |= val >> 32 - shift; 
	  val = val << shift;
	  val |= val_copy;		
	}
}

int main() {
	unsigned int num = 0xF;
	char value = 'r';
	unsigned char value2 = 0xFF;
	cout << "Inital bit pattern of 0xF (15 in base ten) is as indicated below" << endl; 
	displayBits(num, 32);
    circular_shift(num, 8, 'l');
	cout << endl;
	cout << "After shifting the bits 8 placeholders to the left, \n"
	     << "the bit pattern is as follows" << endl; 
	cout << endl;
	displayBits(num, 32);
	
	cout << "As an bonus can you figure out what the value of the above bit pattern is?" << endl;
	cout << "hint: the value of a left-shift expression x << y is x * 2^y . " << endl;
	cout << endl;
		
	cout << "********************************************************************" << endl;
	cout << endl;
	num = 0;
	cout << "Initially the bit pattern for the integer zero is as indicated below"<< endl;
	cout << endl;
	displayBits(num, 32);
	setBits(num, 12, value2);
	cout << endl;
	cout << "Now bit pattern 1111 11111 inserted into the integer\n"
	     << "starting from the 12th bit position, as indicated below" << endl;
	cout << endl;
    displayBits(num, 32);
	return 0;
}
