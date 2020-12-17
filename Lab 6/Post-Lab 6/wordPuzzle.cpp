/*
Drew Goldman
dag5wd
10/9/2020
wordPuzzle.cpp
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include "timer.h"
#include "hashTable.h"
using namespace std;


// We create a 2-D array of some big size, and assume that the grid
// read in will be less than this size (a valid assumption for lab 6)
#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

bool readInGrid(string filename, int& rows, int& cols);
string getWordInGrid(int startRow, int startCol, int dir, int len, int numRows, int numCols);
int solveLength(int startRow, int startCol, int dir, int numRows, int numCols) {
  int length;
  switch(dir) {
  case 0:
    length = startRow + 1;
       break; // north
  case 1:
    length = min(startRow + 1, numCols - startCol);
    break; // north-east
  case 2:
    length = numCols - startCol;
    break; // east
  case 3:
    length = min(numRows - startRow, numCols - startCol);
    break; // south-east
  case 4:
    length = numRows - startRow;
    break; // south
  case 5:
    length = min(numRows - startRow, startCol + 1);
    break; // south-west
  case 6:
    length = startCol + 1;
    break; // west
  case 7:
    length = min(startRow + 1, startCol + 1);
    break; // north-west
  }
  return length;
}

string getDirection(int dir) {
  if(dir == 0) return "N";
  else if(dir == 1) return "NE";
  else if(dir == 2) return "E";
  else if(dir == 3) return "SE";
  else if(dir == 4) return "S";
  else if(dir == 5) return "SW";
  else if(dir == 6) return "W";
  else return "NW";
}


int main(int argc, char* argv[]) {
  string dictionaryFile(argv[1]);
  string gridFile(argv[2]);
  if(argc == 3) {
  // Read in the contents of the dictionary to a Hash Table
  int size = 0;
  ifstream fileCount(dictionaryFile);
  string word;
  while(getline(fileCount, word)) {
    size++;
  }
  double lFactor = 0.1;
  HashTable set(size/lFactor);
  ifstream file(dictionaryFile);
  while (getline(file, word)) {
    for(int z = 3; z < word.size(); z++) {
      set.insert(word.substr(0, z));
    }
    set.insert("%" + word);
  }

  ifstream file2(gridFile);
  int rows;
  file2 >> rows;
  int columns;
  file2 >> columns;
  
  // Read in the contents of the grid into a grid[][] array
  readInGrid(gridFile, rows, columns);
  int counter = 0;
  // Find the words :)
  list<string> words;
  int i = 0;
  timer t;
  t.start();
  //for(int i = 0; i < rows; i++) {
  do {
    string rowNum = to_string(i);
    //for(int j = 0; j < columns; j++) {
    int j = 0;
    do {
      string colNum = to_string(j);
      //for(int k = 0; k < 8; k++) {
      int k = 0;
      do {
	int maxLength = solveLength(i, j, k, rows, columns);
	string direction = getDirection(k);
	//while(length > 2) {
	for(int length = 3; length < maxLength + 1; length++) {
	  string output = getWordInGrid(i, j, k, length, rows, columns);
	  if(set.find("%"+output) && output.length() == length) {
	      words.push_back(direction + " (" + rowNum + ", " + colNum + "): " + output);
	      counter++;
	  }
	  if(!set.find(output) && output.length() == length) break;
	  //length--;
	}
	k++;
      } while (k < 8);
      j++;
    } while (j < columns);
    i++;
  } while (i < rows);
  t.stop();
  list<string>::iterator itr;
  for(itr = words.begin(); itr != words.end(); itr++) cout << *itr << endl;
  cout << to_string(counter) + " words found" << endl;
  // cout << "Found all words in " + to_string(t.getTime()) + " seconds";
  }
  return 0;
}



/** This function will read in a grid file, as per the format in the
 * CS 2150 lab 6 document, into a global grid[][] array.  It uses C++
 * file streams, and thus requires the the <fstream> #include header.
 *
 * @return true or false, depending on whether the file was
 *         successfully opened.
 * @param filename The file name to read in -- it's assumed to be in
 *                 the file format described in the lab document.
 * @param rows The number of rows as specified in the input file;
 *             as this is a reference, it is set by the function.
 * @param cols The number of columns as specified in the input file;
 *             as this is a reference, it is set by the function.
 */
bool readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    // first comes the number of rows
    file >> rows;
    //cout << "There are " << rows << " rows." << endl;

    // then the columns
    file >> cols;
    //cout << "There are " << cols << " cols." << endl;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
            // cout << grid[r][c];
        }
        // cout << endl;
    }
    return true;
}


/** This function will retrieve a word in a grid of letters in a given
 * direction.  If the end of the grid is encountered before the length
 * of the desired string is reached, then a shorter string will be
 * returned.  The data is retrieved from a global char grid[][]
 * array, which is assumed to be defined (and in scope).  NOTE: The
 * return value is a static string variable (for efficiency
 * reasons), so a successive return value will overwrite a previous
 * return value.
 *
 * @return A STATIC string containing the letters in the provided direction.
 * @param startRow The starting (row,col) position to find the word.
 * @param startCol The starting (row,col) position to find the word.
 * @param dir The direction to move: 0 is north (upwards), 1 is
 *            northeast, and it rotates around clockwise until it
 *            reaches 7 for northwest.
 * @param len The desired length of the string to return (assuming
 *            the edge of the grid is not reached--if the edge of the
 *            grid is reached, it will return as many characters as
 *            possible up to the edge of the grid, so the returned
 *            string may not have the same length as this parameter
 *            indicates).
 * @param numRows The number of rows in the global char grid[][]
 *                array.
 * @param numCols The number of columns in the global char grid[][]
 *                array.
 */
string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;
}
