/**
* file
* Drew Goldman
* dag5wd
* 11/12/2020
* topological.cpp
*/


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;


 /**
 * @brief A class node containing its name, edges, and indegree that points to a class or classes.
 */
struct classPointer{

  /**                                                                         
  * @var numEdges the number of edges of the class                                                                        
  */
  int numEdges;
  
  /**                                                                         
  * @var outDegree the number of edges pointing to the class                                                                         
  */
  int outDegree;
  
  /**                                                                         
  * @var title the class name                                                                        
  */
  string title;
  
  /**                                                                         
  * @var nextClass the pointer to the next course(s)                                                            
  */
  classPointer* nextClass;
  
};

 /**
 * @brief Structure to compare two ClassPointers' titles
 */
struct sortClassPointers {  
 /**
 * @brief comparator function for sort by title
 *
 * @return whether or not p1.title < p2.title
 * @param p1 first pointer to be compared
 * @param p2 second pointer to be compared
 */
  bool operator()(const classPointer* p1, const classPointer* p2) const { 
  	int ret = (p1->title).compare(p2->title);
  	if (ret >= 0) return false;
  	else return true;
  }
};


 /**
 * @brief main method to run topological algorithm
 *
 * @return 0 upon a lack of errors :)
 * @param argc command-line parameter containing the number of parameters given at run time
 * @param argv strings of different parameters
 * @see fileio2.cpp to see original source code, as this code was ADAPTED from that file.
 */
int main(int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // read in two strings
    string s;
    vector<classPointer*> v;
    while ( true ) {
    	file >> s;
    	if ("0" == s) {
    		file >> s;
    		if("0" == s) break;
    	}
    	classPointer* p = new classPointer();
    	
    	for (int i = 0; i < v.size(); i++) {
    		if (s == v[i]->title) {
    			stack <classPointer*> myStack;
    			v[i]->outDegree++;
    			p = v[i]->nextClass;
    			while (p != NULL) {
    				myStack.push(p);
    				//p->outDegree++;
    				p = p->nextClass;
    			}
   
    			file >> s;
    			bool equals = false;
    			for(int j = 0; j < v.size(); j++) {
    				if (s == v[j]->title) {
    					equals = true;
    				}
    			}
    			
    			if (!equals) {
				classPointer* p2 = new classPointer();
    				p2->title = s;
    				v.push_back(p2);
    			}
    			
    			classPointer* p3 = new classPointer();
    			p3->title = s;
    			p = p3;
    			
    			while (myStack.size() > 0) {
    				//myStack.top()->outDegree++;
    				myStack.top()->nextClass = p;
    				p = myStack.top();
    				myStack.pop();
    			}
			v[i]->nextClass = p;
			break;
		}
	}
   	if ("" == p->title) {
   	 	p->title = s;
   	 	file >> s;
   	 	classPointer* p4 = new classPointer();
   	 	p4->title = s;
   	 	p->outDegree++;
   	 	p->nextClass = p4;
   	 	v.push_back(p);
   	 	
   	 	bool equals = false;
   	 	for(int i = 0; i < v.size(); i++) {
   	 		if(s == v[i]->title) equals = true;
   	 	}
   	 	
   	 	if (!equals) {
   	 		classPointer* p5 = new classPointer();
   	 		p5->title = s;
   	 		v.push_back(p5);
   	 	}
   	 	
   	 }
    }
    // output those strings
    // cout << s1 << endl;
    // cout << s2 << endl;

    // close the file before exiting
    file.close();
    sort(v.begin(), v.end(), sortClassPointers());
    int size = v.size();
    classPointer* p6;
    
    for (int i = 0; i < size; i++) {
    	//v[i]->outDegree++;
    	p6 = v[i]->nextClass;
    	while(p6 != NULL) {
    		p6 = p6->nextClass;
    	}
    }
    
    bool classMap[size][size];
    
    for(int j = 0; j < size; j++) {
    	for(int k = 0; k < size; k++) classMap[j][k] = false; //initialize matrix with false
    }
    
    for(int i = 0; i < size; i++) {
    	stack<classPointer*> myStack2;
    	//v[i]->outDegree++;
    	classPointer* p7 = v[i]->nextClass;
    	
    	while(p7 != NULL) {
    		myStack2.push(p7);
    		//myStack2.top()->outDegree++;
    		p7 = myStack2.top()->nextClass;
    	}
    	
    	while(myStack2.size() > 0) {
    		for(int j = 0; j < size; j++) {
    			if((v[j]->title == myStack2.top()->title) && (i != j)) classMap[i][j] = true;
    		}
    		myStack2.pop();
    	}
    }
    
    int r = 0;
    int c = 0;
    int tmp = 0;
    while (c < v.size()) {
    	while (r < v.size()) {
    		if (classMap[r][c] == true) {
    			c++;
    			r = 0;
    		}
    		else r++;
    	}
    	/*
    	for (int i = c; i < c + 1; i++) {
  	  if (i < v.size() && v[i]->outDegree > 1) {
    		//sort(v.begin()+i+1, v.begin()+i+2, sortClassPointers());
    		string nextClass;
    		int outCount = v[i]->outDegree;
    		classPointer* original = v[i];
    		while( outCount > 0 && v[i]->nextClass) {
    			if(v[i]->nextClass) nextClass = v[i]->nextClass->title;
			int index = 0;
    			for(int j = v.size()-1; j > 0; j--) {
    				if (nextClass == v[j]->title) index = j;
    			}
    			string nextNextClass;
    			int index2 = 0;
    			if(v[i]->nextClass->nextClass) nextNextClass = v[i]->nextClass->nextClass->title;
    			for(int j = v.size()-1; j > 0; j--) {
    				if (nextNextClass == v[j]->title) index2 = j;
    			}
    			classPointer* tmp;
    			if (v[index]->title.compare(v[index2]->title) > 0) {
    				tmp = v[index];
    				v[index] = v[index2];
    				v[index2] = tmp;
    			}
    			outCount--;
    			v[i] = v[i]->nextClass;
    		}
    	  }
   	 }*/
    	
    	cout << v[c]->title + " ";
    	
    	for(int i = 0; i < v.size(); i++) {
    		classMap[c][i] = false;
    		classMap[i][c] = true;
    	}
    	tmp++;
    	
    	if(tmp < v.size()) c = 0;
    	else break;
    	r = 0;
    }
    
    return 0;
}

