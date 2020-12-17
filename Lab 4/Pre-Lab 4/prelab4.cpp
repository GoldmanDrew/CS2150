/*
Drew Goldman
dag5wd
9/23/2020
prelab4.cpp
*/

#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

void sizeOfTest() {
  cout << "Size of int: " << sizeof(int) << endl;
  cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
  cout << "Size of float: " << sizeof(float) << endl;
  cout << "Size of double: " << sizeof(double) << endl;
  cout << "Size of char: " << sizeof(char) << endl;
  cout << "Size of bool: " << sizeof(bool) << endl;
  cout << "Size of int*: " << sizeof(int*) << endl;
  cout << "Size of char*: " << sizeof(char*) << endl;
  cout << "Size of double*: " << sizeof(double*) << endl;
}

void overflow() {
  cout << UINT_MAX << " + 1 = " << UINT_MAX + 1 << endl;
}

void outputBinary(unsigned int x) {
  char binaryBits[32];
  string bits = "";
  for(int i = 0; i < 32; i++) {
    binaryBits[i] = '0';
  }
  for(int j = 31; j >-1; j--) {
    if(x % 2 == 1) binaryBits[j] = '1';
    x /= 2;
  }
  for(int k = 0; k < 32; k++) bits += binaryBits[k];
  while(bits.length() < 32) {
    bits.insert(0, "0");
  }
  for(int i = 28; i > 0; i--) {
    if(i%4 == 0) bits.insert(i, " ");
  }
  cout << bits << endl;
}

int main() {
  sizeOfTest();
  overflow();
  int x = 0;
  cin >> x;
  outputBinary(x);
  return 0;
}

