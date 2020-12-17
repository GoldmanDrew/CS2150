/*
Drew Goldman
dag5wd
11/10/2020
huffmandec.cpp
*/

// ALTERED VERSION OF SKELETON
// This program is the skeleton code for the lab 10 in-lab.
// It uses C++ streams for the file input,
// and just prints out the data when read in from the file.

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include "huffmanNode.h"
using namespace std;


void huffmanTreeBuilder(huffmanNode* n, char c, string p);

char getCharacter(huffmanNode* n, char c)
{
  if(c == '0') {
  	if(!n->left) return n->getData();
  	else return '\0';
  }
  else {
 	 if(!n->right) return n->getData();
	  else return '\0';
  }
}

// main(): we want to use parameters
int main (int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    huffmanNode* node = new huffmanNode(0, '\0');
    // read in the first section of the file: the prefix codes
    while (true) {
        string prefix, character;
        // read in the first token on the line
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;
        
      	huffmanTreeBuilder(node, character[0], prefix);
        // do something with the prefix code
        // cout << "character '" << character << "' has prefix code '" << prefix << "'" << endl;
    }

    // read in the second section of the file: the encoded message
    stringstream sstm;
    while ( true ) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') break;
       
        // add it to the stringstream
        sstm << bits;
    }
    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    // cout << "All the bits: " + allbits << endl;
    // close the file before exiting
    file.close();
    
    
    string ret = "";
    huffmanNode* node2 = node;
    for (int j = 0; j < allbits.length(); j++) {
    	if (allbits[j] == '0' && node2->left) node2 = node2->left;
    	
    	else if(allbits[j] == '1' && node2->right) node2 = node2->right;
    	
    	if(getCharacter(node2, allbits[j]) != '\0') {
    		char c = getCharacter(node2, allbits[j]);
    		ret += c;
   		node2 = node;
    	}
    
    }
    
    cout << ret << endl;
    
    return 0;
}


void huffmanTreeBuilder(huffmanNode* n, char c, string p) {
 if(p.length() == 0) n->setData(c);
 
  if(p[0] == '0') {
    if(!n->left) n->left = new huffmanNode(0, '\0');
  
    huffmanTreeBuilder(n->left, c, p.substr(1, p.length()));
  }
  else if(p[0] == '1') {
    if(!n->right) n->right = new huffmanNode(0, '\0');
   
    huffmanTreeBuilder(n->right, c, p.substr(1, p.length()));
  }
}

