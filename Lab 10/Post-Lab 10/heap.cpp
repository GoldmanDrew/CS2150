/*
Drew Goldman
dag5wd
11/8/2020
heap.cpp
*/

// ADAPTED Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#include <iostream>
#include "heap.h"
#include "huffmanNode.h"
using namespace std;

// default constructor
heap::heap() : hSize(0) {
    hHeap.push_back(0);
}

// builds a heap from an unsorted vector
heap::heap(vector<huffmanNode*> vec) : hSize(vec.size()) {
    hHeap = vec;
    hHeap.push_back(hHeap[0]);
    hHeap[0] = 0;
    for (int i = hSize/2; i > 0; i--) {
        percolateDown(i);
    }
}


// the destructor doesn't need to do much
heap::~heap() {
}

void heap::insert(huffmanNode* n){
    // a vector push_back will resize as necessary
    hHeap.push_back(n);
    // move it up into the right position
    percolateUp(++hSize);
}

void heap::percolateUp(int hole) {
    // get the value just inserted
    int x = hHeap[hole]->getFrequency();
    huffmanNode* n = hHeap[hole];
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (x < hHeap[hole/2]->getFrequency()); hole /= 2) {
        hHeap[hole] = hHeap[hole/2]; // move the parent down
    }
    // correct position found!  insert at that spot
    hHeap[hole] = n;
}

huffmanNode* heap::findMin(){
  if(!isEmpty()) return hHeap[1];
  return NULL;
}

huffmanNode* heap::deleteMin(){
  // make sure the heap is not empty
    if (isEmpty()) {
        throw "deleteMin() called on empty heap";
    }

    // save the value to be returned
    huffmanNode* ret = hHeap[1];
    // move the last inserted position into the root
    hHeap[1] = hHeap[hSize--];
    // make sure the vector knows that there is one less element
    hHeap.pop_back();
    // percolate the root down to the proper position
    if (!isEmpty()) {
        percolateDown(1);
    }
    // return the old root node
    return ret;
}

void heap::percolateDown(int hole) {
    // get the value to percolate down
    int x = hHeap[hole]->getFrequency();
    huffmanNode* n = hHeap[hole];
    // while there is a left child...
    while (hole*2 <= hSize) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ((child+1 <= hSize) && (hHeap[child+1]->getFrequency() < hHeap[child]->getFrequency())) {
            child++;
        }
        // if the child is greater than the node...
        if (x > hHeap[child]->getFrequency()) {
            hHeap[hole] = hHeap[child]; // move child up
            hole = child;             // move hole down
        } else {
            break;
        }
    }
    // correct position found!  insert at that spot
    hHeap[hole] = n;
}
    

unsigned int heap::getSize(){
  return hSize;
}

huffmanNode* heap::find(int i) {
  return hHeap[i];
}


void heap::makeEmpty() {
  hSize = 0;
  hHeap.resize(1);
}

bool heap::isEmpty() {
  if(hSize == 0) {
    return true;
  }
  else return false;
}

