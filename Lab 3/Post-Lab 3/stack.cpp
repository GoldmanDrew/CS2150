/*
Drew Goldman
dag5wd
9/23/2020
stack.cpp
*/

#include <iostream>
#include <iterator> 
#include <string>
#include "stack.h"
using namespace std;

stack::stack() {
  tNode = new stacknode();
}

stack::~stack() {
  delete tNode;
}

void stack::push(int e) {
  stacknode* newNode = new stacknode();
  newNode->next = tNode;
  newNode->e = e;
  tNode = newNode;

}

void stack::pop() {
  if(!empty()) {
    tNode = tNode->next;
  }
}

int stack::top() {
  return tNode->e;

}

bool stack::empty() {
  if(tNode == NULL) return true;
  else return false;
}
