/*
Drew Goldman
dag5wd
9/23/2020
stack.h
*/

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <iterator> 
#include <string>
#include "stacknode.h"
using namespace std;

class stack {
 public:

  stack();

  ~stack();
  
  void push(int e);

  void pop();

  int top();

  bool empty();

 private:
  
  stacknode* tNode;

  friend class stacknode;

};

#endif
