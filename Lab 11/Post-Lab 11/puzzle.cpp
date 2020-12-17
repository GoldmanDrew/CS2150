/*
Drew Goldman
dag5wd
11/18/2020
puzzle.cpp
*/

#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <cctype>
#include <algorithm>
#include <unordered_map>
using namespace std;

  /**
  * @brief A puzzle node containing its coordinates, the number of moves, the cost to get to the goal puzzle, a 3x3 2D array, and a pointer to its antecedant
  */
	struct puzzle {
  /**                                                                         
  * @var x, y coordinates                                                                       
  */
		int x, y = 0;
  /**                                                                         
  * @var numMoves the number of moves performed                                                               
  */
		int numMoves = 0;
  /**                                                                         
  * @var misplaced the cost to get to the goal puzzle                                                                     
  */
		int misplaced = 0;
  /**                                                                         
  * @var matrix a 2D array containing the numebrs                                                                     
  */
		int matrix[3][3];
  /**                                                                         
  * @var antecedant a pointer to the parent puzzle                                                                      
  */
		puzzle* antecedant;
	};
	
unordered_set <string> visited;	
  /**
  * @brief puzzleConstructor A puzzle constructor
  */
	puzzle* puzzleConstructor (string s, int xP, int yP, int num, puzzle* ante) {
	
		puzzle* p = new puzzle();
		p->antecedant = ante;
		int strIndex = 0;
		int x, y = 0;
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				if(s[strIndex] == '0') {
					x = i;
					y = j;
					p->x = x;
					p->y = y;
				}
				p->matrix[i][j] = s[strIndex++] - '0';
			}
		}
		
		if(xP == -1 && yP == -1) {
			xP = x;
			yP = y;
			
		}
		else swap(p->matrix[x][y], p->matrix[xP][yP]);
		
		p->x = xP;
		p->y = yP;
		p->numMoves = num;
		p->misplaced = 69696969;
		
		return p;
	}
	
  /**
  * @brief toString convert a puzzle's matrix to a string
  */
	string toString(const puzzle& p) {
	
	    int index = 0;
	    string current = "000000000";
	    for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				current[index++] = p.matrix[i][j] + '0';
			}
	    }
	    return current;
	}

  /**
  * @brief tileMismatchCount a count of the cost to get to the final puzzle
  */
	int tileMismatchCount(const puzzle& p) {
	
		int count = 0;
		string final = "123456780";
		string thisPuzzle = toString(p);
		
		for(int i = 0; i <= 8; i++) {
			if('0' != thisPuzzle[i] && thisPuzzle[i] != final[i]) count++;
		}
		return count;
	}
	
  /**
  * @brief isInBounds checks if x and y are within the bounds of the matrix
  */
	int isInBounds(int x, int y) { 
   		 bool result = ((y > -1 && y <= 2) && (x > -1 && x <= 2));
   		 return result;
	} 

  /**
  * @brief finalTest checks if the matrix reached the final goal
  */
	bool finalTest(const puzzle& p) {
	
		string final = "123456780";
		string cur = toString(p);
		if(final == cur) {
			return 1;
		}
		return 0;
	}
	
  /**
  * @brief pComparator a structor to compare puzzles
  */
	struct pComparator { 
   		bool operator()(const puzzle* pL, const puzzle* pR) const { 
       		 return (pL->misplaced + pL->numMoves) > (pR->misplaced + pR->numMoves); 
   	 	}
   	 	/*bool operator()(const puzzle* pL, const puzzle* pR) const { 
       		 return toString(pL) == toString(pR);
   	 	} */
	}; 
	
	bool operator<(const puzzle& p1, const puzzle& p2) { 
  		return p1.x > p2.x; 
	}

  /**
  * @brief getICount finds the count of inversions
  */
	int getICount(int arr[]) { 
    		int iCount = 0; 
    		for (int i = 0; i < 8; i++) {
        		for (int j = i+1; j < 9; j++) {
           	 	 	if (arr[i] && arr[j]) {
           	 	 		if(arr[i] > arr[j])  iCount++; 
   	 	 		}
   	 	 	}
 	 	}
   		return iCount; 
	} 
  
  
  /**
  * @brief solvable checks if the number of inversion is even or odd
  */
	bool solvable(const puzzle& p) { 
    		int iCount = getICount((int*)p.matrix); 
 
    		bool result = (iCount % 2 == 0); 
    		return result;
	} 
	
  /**
  * @brief move recursively counts the number of moves
  */	
	int move(puzzle* p) { 
    		if (p == NULL) return -1;
    		return move(p->antecedant) + 1; 
    		return 0;
	}

  /**
  * @brief algorithm solves the puzzle
  * @see move to understand the move count
  */	
	int algorithm(puzzle* p) { 
	
    		priority_queue<puzzle*, vector<puzzle*>, pComparator> puzzles; 
    		
    		p->misplaced = tileMismatchCount(*p);
    		
    		puzzles.push(p);
    		visited.clear();
    		
    		int c[] = {0, -1, 0, 1};
    		int r[] = {1, 0, -1, 0}; 

    		while (!puzzles.empty()) { 
    		
			puzzle* low = puzzles.top();
			
			low->y = puzzles.top()->y;
			low->x = puzzles.top()->x;
 
        		puzzles.pop(); 
        		
        		if (low->misplaced == 0) return move(low);
        		for (int i = 0; i <= 3; i++) { 
            			if (isInBounds(low->x + r[i], low->y + c[i]))  { 
            				string s = toString(*low);
                			puzzle* progeny = puzzleConstructor(s, r[i] + low->x, c[i] + low->y, 1 + low->numMoves, low);
                			progeny->misplaced = tileMismatchCount(*progeny);
            				if(visited.find(toString(*progeny)) == visited.end()) {
            					visited.insert(toString(*progeny));
            					puzzles.push(progeny); 
                			}
           			 } 
        		} 
    		} 
    		
    		return 0;
	} 
	

  /**
  * @brief main to run the code
  */	
int main() {	

	string input[3];
	cout << "Enter puzzle" << endl;
	getline(cin, input[0]);
	getline(cin, input[1]);
	getline(cin, input[2]);
	
	string concat = input[0] + input[1] + input[2];
	concat.erase(remove_if(concat.begin(), concat.end(), ::isspace), concat.end()); //source to remove whitespaces: https://www.techiedelight.com/remove-whitespaces-string-cpp/#:~:text=The%20standard%20solution%20is%20to,using%20Erase%2Dremove%20idiom%20technique.
	
	puzzle* p = puzzleConstructor(concat, -1, -1, 0, NULL);
	cout << "Solving puzzle" << endl;
	if(!solvable(*p)) {
		cout << "IMPOSSIBLE";
		exit(1);
	}

	cout << algorithm(p);

	return 0;
}
