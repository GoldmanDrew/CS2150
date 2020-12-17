/*
Drew Goldman
dag5wd
11/8/2020
huffmanNode.cpp
*/

#include "huffmanNode.h"
#include <iostream>
using namespace std;


huffmanNode::huffmanNode(int f, char d)
{
  right = NULL;
  left = NULL;
  prefix = "";
  data = d;
  frequency = f;
}

huffmanNode::~huffmanNode() {
  delete right;
  delete left;
}

char huffmanNode::getData()
{
  return data;
}

int huffmanNode::getFrequency() const
{
  return frequency;
}


void huffmanNode::setFrequency(int ct)
{
  frequency = ct;
}

bool huffmanNode::operator<(const huffmanNode& n) const {
  return(this->getFrequency() < n.getFrequency());
}

