/*
Drew Goldman
dag5wd
10/9/2020
HashTable.cpp
*/

#include <iostream>
#include <string>
#include "hashTable.h"
using namespace std;


bool isPrime(unsigned int num) {
  if(num == 2) return true;
  if(num < 2) return false;
  if(num % 2 == 0) return false;
  int i = 3;
  while(i*i < (num + 1)) {
    if((num % i) == 0) return false;
    i++;
  }
  return true;
}

int higherPrime(unsigned int num) {
  while(!isPrime(++num));
  return num;
}

HashTable::HashTable(int s) {
  int nextPrime = higherPrime(s);
  t.resize(nextPrime);
}

HashTable::~HashTable() {
}

unsigned int HashTable::hashFunction(const string& x) const {
  unsigned int hash = 0 ;
  for(int i = 0; i < x.size(); i++) {
    hash = hash*31 + int(x[i]);
  }
  return hash;
  
}

void HashTable::insert(const string& x) {
  int hashCode = hashFunction(x) % t.capacity();
  t[hashCode].push_back(x);
}

bool HashTable::find(const string& x) const {
  int hashCode = hashFunction(x) % t.capacity();
  list<string> reference = t[hashCode];
  for(string s : reference) {
    if(s == x) return true;
  }
  return false;
}
