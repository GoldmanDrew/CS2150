/*
Drew Goldman
dag5wd
11/8/2020
huffmanNode.cpp
*/

#include "huffmanTree.h"
using namespace std;

huffmanTree::huffmanTree() {
  root = NULL;
}

huffmanTree::~huffmanTree() {
  delete root;
}

huffmanNode* huffmanTree::merge(huffmanNode* l, huffmanNode* r) {

  int totalF = l->getFrequency() + l->getFrequency();
  huffmanNode* mergedN = new huffmanNode(totalF, '0');
  mergedN->right = r;
  mergedN->left = l;
  
  return mergedN;
}

heap huffmanTree::build(heap hHeap) {
  while(hHeap.getSize() != 1) {
  
    huffmanNode* l = hHeap.findMin();
    hHeap.deleteMin();
    
    huffmanNode* r = hHeap.findMin();
    hHeap.deleteMin();
    
    huffmanNode* merged = merge(l, r);
    hHeap.insert(merged);
  }
  return hHeap;
}


void huffmanTree::setPrefix(huffmanNode* n, string p) {
  if(!n->right && !n->left) n->prefix = p;
  
  if(n->left) setPrefix(n->left, p +"0");
  if(n->right) setPrefix(n->right, p +"1");
}

void huffmanTree::printPrefix(huffmanNode* n, string p) {
  if(!n->right && !n->left) {
    if(n->getData() == ' ') cout << "space " + p << endl;
    else cout << n->getData() << " " + p << endl;
  }
 
  if(n->left) printPrefix(n->left, p + "0");
  if(n->right) printPrefix(n->right, p + "1");
}

