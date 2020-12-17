/*
Drew Goldman
dag5wd
10/2/2020
Filename: TreeCalc.h
*/
// TreeCalc.h: Tree Calculator class definition
// CS 2150: Lab 5
// You must submit ALL code to make your project build correctly


#ifndef TREECALC_H
#define TREECALC_H

#include <stack>

#include "TreeNode.h"
using namespace std;

class TreeCalc {
public:
    TreeCalc();                     // Constructor
    ~TreeCalc();                    // Destructor

    void cleanTree(TreeNode* tree);  // Deletes tree/frees memory
    void readInput();               // Gets data from user
    void insert(const string& val); // Puts value in tree

    // print methods
    void printPrefix(TreeNode* tree) const;  // Prints data in prefix form
    void printInfix(TreeNode* tree) const;   // Prints data in infix form
    void printPostfix(TreeNode* tree) const; // Prints data in postfix form
    void printOutput() const;                // Prints in post, in, pre form
    int calculate();                         // Calls private calculate method
    bool isDigit(const string& val);
    bool isOperator(string s) const;
    

private:
    stack<TreeNode*> expressionStack;   // Stack to hold the expression

    int calculate(TreeNode* tree) const; // Evaluates tree, returns value

};

#endif
