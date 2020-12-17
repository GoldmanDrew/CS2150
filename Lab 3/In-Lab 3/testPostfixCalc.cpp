/*
Drew Goldman
dag5wd
9/15/2020
Filename: testPostfixCalculator.cpp
*/

#include <iostream>
#include<stack>
#include<string>
#include "postfixCalculator.h"
using namespace std;


int main() {
  postfixCalculator * calc = new postfixCalculator();
  string input = "";
  getline(cin, input);
  cout << calc->output(input) << endl;
  delete calc;
  return 0;
}
