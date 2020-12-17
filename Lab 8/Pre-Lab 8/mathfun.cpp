/*
Drew Goldman
dag5wd
10/24/2020
mathfun.cpp
 */
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

extern "C" int product (int, int);
extern "C" int power (int, int);

// Purpose: This main program prints the product and power of two integers.

// Originally written by Adam Ferrari, and updated by Aaron Bloomfield

int  main () {

  // delcare the local variables
  int x, y, prod, pow;

  //inputs
  cout << "Enter integer 1: ";
  cin >> x;
  cout << "Enter integer 2: ";
  cin >> y;
  
  // sum up the array and print out results
  prod = product(x, y);
  cout << "Product: " << prod << endl;
  pow = power(x, y);
  cout << "Power: " << pow << endl;
  // all done!
  return 0;
}
