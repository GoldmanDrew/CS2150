/*
Drew Goldman
dag5wd
11/8/2020
heap.h
*/

// ADAPTED Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#ifndef HEAP_H
#define HEAP_H
#include "huffmanNode.h"
#include <vector>
#include <unordered_map>
using namespace std;

class heap{
 public:
  heap();
  heap(vector<huffmanNode*> vec);
  ~heap();
   
  void insert(huffmanNode* n);
  huffmanNode* findMin();
  huffmanNode* deleteMin();
  unsigned int getSize();
  void makeEmpty();
  bool isEmpty();
  huffmanNode* find(int i);
  
  vector<huffmanNode*> hHeap;

 private:
 unsigned int hSize;
 void percolateUp(int hole);
 void percolateDown(int hole);
 
 };
 
#endif
