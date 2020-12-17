/*
Drew Goldman
dag5wd
9/23/2020
stacknode.h
*/

#ifndef STACKNODE_H
#define STACKNODE_H

#include <iostream>
#include <iterator> 
#include <string>
using namespace std;

class stacknode {
 public:

  stacknode();

 private:

  int e;

  stacknode* next;

  friend class stack;
  
};

#endif
