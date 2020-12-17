/*
Drew Goldman
dag5wd
9/29/2020
bitCounter.cpp
*/

#include <iostream>
#include <math.h> 
#include <string>
#include <array>
#include <sstream>

using namespace std;

int toBaseTen(char at) { 
    if(at >= '0' && at <= '9') return (int)at - '0'; 
    else return 10 + ((int)at - 'A'); 
}

char fromBaseTen(int at) {
  if(at > -1 && at < 10) return (char)(at + '0'); 
  else return (char)('A' + (at - 10)); 
}

int numOnes(int n) {
  if(n%2 == 0) return n/2;
  else return 1 + numOnes(floor(n/2));
}

string changeBase(string input, int startBase, int endBase) {
  int p = 1;
  int baseTen = 0;
  int length = input.length(); 
  string output = "";
  for(int i = length - 1; i > -1; i--) {
    if(toBaseTen(input[i]) > startBase-1) {
      cout << "Error";
      return "";
    }
    baseTen = baseTen + toBaseTen(input[i])*p;
    p = p * startBase;
  }
  string stringResult = to_string(baseTen);
  while(baseTen >  0) {
    string cInsert = string(1, fromBaseTen(baseTen % endBase));
    output.insert(0, cInsert);
    baseTen /= endBase;
  }
  return output;
}

int main(int argc, char *argv[]) {
  int i = 0;
  while(i < argc) {
    if(argv[i] == NULL) {
      return 0;
    }
    i++;
  }
  string b = argv[1];
  stringstream bStream(b);
  int bitcountee = 0;
  bStream >> bitcountee;
  int bitcount = numOnes(bitcountee);
  
  cout << b + " has " + to_string(bitcount) + " bit(s)" << endl;
  
  string input = argv[2];
  
  string sBase = argv[3];
  stringstream sStream(sBase);
  int startBase = 0;
  sStream >> startBase;

  string eBase = argv[4];
  stringstream eStream(eBase);
  int endBase = 0;
  eStream >> endBase;
  
  cout << input + " (base " + sBase + ")" + " = " + changeBase(input, startBase, endBase) + " (base " + eBase +")" << endl;
  return 0;
}
