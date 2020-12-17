/*
Drew Goldman
dag5wd
11/8/2020
huffmanNode.h
*/

#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <iostream>
#include <string>
#include "heap.h"
#include "huffmanNode.h"

using namespace std;

class huffmanTree {
 public:
 
  huffmanTree();
  ~huffmanTree();

  heap build(heap hHeap);
  huffmanNode* merge(huffmanNode* l, huffmanNode* r);
  
  void setPrefix(huffmanNode* root, string p);
  void printPrefix(huffmanNode* root, string p);
 private:
 
  huffmanNode* root;

};

#endif
