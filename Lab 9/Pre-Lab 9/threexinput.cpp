/*
Drew Goldman
dag5wd
10/30/2020
threexinput.cpp
*/

#include <cstdlib>
#include <iostream>
#include <cstring>
#include "timer.h"

using namespace std;

extern "C" int threexplusone(int);

int main() {
  
  int x, n;
  
  cout << "Enter a number: ";
  cin >> x;
  
  cout << "Enter iterations of subroutine: ";
  cin >> n;
  
  timer t;
  t.start();
  for (int i = 0; i < n; i++) threexplusone(x);
  t.stop();
  
  double averageT = 0;
  averageT = t.getTime() / n;
  
  cout << "Steps: " << threexplusone(x) << endl;
  // cout << "Average time: " << averageT << endl;
  return 0;
  
}
