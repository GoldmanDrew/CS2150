/*
Drew Goldman
dag5wd
11/8/2020
huffmanenc.cpp
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <iterator>
#include "heap.h"
#include "huffmanTree.h"
#include "huffmanNode.h"

using namespace std;

int main(int argc,char* argv[]) {
  // verify file is the only parameter
  if (argc != 2) {
  	cout << "Incorrect inputs" << endl;
  	exit(1);
  }

  ifstream file(argv[1]);
  // if file is null, exit
  if (!file.is_open()) {
    	cout << "'" << argv[1] << "' cannot be opened" << endl;
    	exit(2);
  }
  
  // section 1
  char g;
  vector<int> nums;
  int A = 0;
  int E = 0;
  int U = 0;
  int total = 0;
  huffmanTree* tree = new huffmanTree();
  nums.resize(128);
  
  while (file.get(g)) {
  	A = (int) g;
  	if (isprint(A)) {
  		total++;
  		nums.at(A)++;
  	}
  }
  
  
  heap h;
  for (int i = 0; i < 128; i++) {
  	if (nums.at(i) > 0) {
    		huffmanNode* n = new huffmanNode(nums.at(i), (char)i);
    		h.insert(n);
    		U++;
    	}
  }
  
  heap build = tree->build(h);
  huffmanNode* base = build.findMin();
  
  tree->printPrefix(base, "");
  tree->setPrefix(base, "");
  
  
  // section 2                                                 
  cout << "----------------------------------------" << endl;
  
  file.clear();
  file.seekg(0);
  
  char gPrime;
  while(file.get(gPrime)) {
  	for(int i = 1; i < (1 + h.getSize()); i++) {
        	huffmanNode * n = h.find(i);
     		if(gPrime == n->getData()) {
			E += n->prefix.size();
			cout << n->prefix << " ";
      		}
    	}
    }
    cout << endl;
    file.close();
  
  // section 3
  cout << "----------------------------------------" << endl;
  cout << "There are a total of " << total << " symbols that are encoded."<< endl;
  cout << "There are " << U << " distinct symbols used." << endl;
  cout << "There were " << 8*total << " bits in the original file." << endl;
  cout << "There were " << E << " bits in the compressed file." << endl;
  
  double compressionRatio = (double) (8*total)/E;
  cout << "This gives a compression ratio of: " << compressionRatio << endl;
  
  double cost = (double) E/total;
  cout << "The cost of the Huffman Tree is " << cost << endl;

  return 0;
}

