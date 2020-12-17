/*
Drew Goldman
dag5wd
11/8/2020
huffmanNode.h
*/

#ifndef HUFFMAN_NODE_H
#define HUFFMAN_NODE_H

#include <vector>
#include <string>
using namespace std;

class huffmanNode {
public:

  ~huffmanNode();
  huffmanNode(int f, char d);
  
  int getFrequency() const;
  char getData();
  string getPrefix();
  
  void setFrequency(int s);
  void inc();
  
  huffmanNode* left;
  huffmanNode* right;
  string prefix;
  bool operator< (const huffmanNode& n) const;
  
private:

  char data;
  int frequency;
  friend class heap;
  
};
#endif
