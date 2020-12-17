/*
Drew Goldman
dag5wd
10/9/2020
hashTable.h
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

class HashTable {
 public:
  
  HashTable(int s);
  ~HashTable();
  unsigned int hashFunction(const string& x) const;
  void insert(const string& x);
  bool find(const string& x) const;

 private:
  vector<list<string>> t;
};

#endif
