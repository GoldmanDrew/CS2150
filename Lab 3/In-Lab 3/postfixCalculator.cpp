/*
Drew Goldman
dag5wd
9/15/2020
Filename: postfixCalculator.cpp
*/

#include <iostream>
#include<stack>
#include<string>
#include "postfixCalculator.h"
using namespace std;



postfixCalculator::postfixCalculator() {
}

postfixCalculator::~postfixCalculator() {
}

int postfixCalculator::output(string input) {
  int x1 = 0, x2 = 0;
  for(int i = 0; i < input.length(); i++) {
    if(input[i] == ' ') continue;
    else if(isOp(input[i])) {
      if((i+1) < input.length() && isNum(input[i+1])) {
	int num = 0;
	while(isNum(input[i+1])) {
	  num = num*10 + (input[i+1] - '0');
	  i++;
	}
	int negation = -1*(num);
	theStack.push(negation);
      }
      else { 
	if(!theStack.empty()) {
	  x1 = theStack.top();
	  theStack.pop();
	}
	if(!theStack.empty()) {
	  x2 = theStack.top();
	  theStack.pop();
	}
	int output = op(x1, x2, input[i]);
	theStack.push(output);
      }
    }
    else if (isNum(input[i])) {
      int num = 0;
      //check for more than one digit number
      while(i<input.length() && isNum(input[i])) {
	num = (num*10) + (int)(input[i] - '0'); 
	i++;
      }
      i--;
      theStack.push(num);
    }
  }
  if(!theStack.empty()) return theStack.top();
  else return 0;
}

bool postfixCalculator::isNum(char c) {
  if(c <= '9' && c >= '0') return true;
  else return false;
}

bool postfixCalculator::isOp(char c) {
  if(c == '+' || c == '-' || c == '*' || c == '/' || c == '~') return true;
  else return false;
}

int postfixCalculator::op(int x1, int x2, char c) {
  if(c == '+') return x1+x2;
  if(c == '-') return x2-x1;
  if(c == '*') return x1*x2;
  if(c == '/') return x2/x1;
  if(c == '~') return -x1;
  else return 0;      
}
