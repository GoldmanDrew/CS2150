/*
Drew Goldman
dag5wd
9/15/2020
Filename: postfixCalculator.cpp 
 */
#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include<stack>
#include<string>
using namespace std;

class postfixCalculator {

 public:

  //default constructor
  postfixCalculator();

  ~postfixCalculator();

  int output(string input);

  bool isNum(char c);

  bool isOp(char c);

  int op(int x1, int x2, char c);

  
private:

  stack<int> theStack;
  
};

#endif
