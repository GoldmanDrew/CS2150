/*
Drew Goldman
dag5wd
10/2/2020
Filename: TreeCalc.cpp 
*/
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Constructor
TreeCalc::TreeCalc() {
  stack<TreeNode*> expressionStack;
}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
  if(tree) {
    cleanTree(tree->left);
    cleanTree(tree->right);
    delete tree;
  }
}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
  if(!isDigit(val) && expressionStack.size() > 1) {
    TreeNode* oNode = new TreeNode(val);
    oNode->right = expressionStack.top();
    expressionStack.pop();
    oNode->left = expressionStack.top();
    expressionStack.pop();
    expressionStack.push(oNode);
  }
  else {
     TreeNode* dNode = new TreeNode(val);
     expressionStack.push(dNode);
  }
}

// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
    // print the tree in prefix format
  if(tree) {
      cout << tree->value + " ";
      printPrefix(tree->left);
      printPrefix(tree->right);
    }
}

// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
    // print tree in infix format with appropriate parentheses
  if(tree) { 
    if(isOperator(tree->value)) {
      cout << "(";
    }
    printInfix(tree->left);
    cout << tree->value + " ";
    printInfix(tree->right);
    if(isOperator(tree->value)) {
      cout << ") ";
    }
  }
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
    // print the tree in postfix form
  if(tree) {
      printPostfix(tree->left);
      printPostfix(tree->right);
      cout << tree->value + " ";
  }
}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}

// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
    // Traverse the tree and calculates the result
  int calculation = 0;
  int left = 0;
  int right = 0;
  if(tree->left == NULL && tree->right == NULL) {
    stringstream stream1;
    int result = 0;
    stream1 << tree->value;
    stream1 >> result;
    return result;
  }
  else if(isOperator(tree->value)) {
    switch(tree->value[0]){
    case '+':
      left = calculate(tree->left);
      right = calculate(tree->right);
      calculation = left + right;
      break;
    case '-':
      left = calculate(tree->left);
      right =calculate(tree->right);
      calculation=left - right;
      break;
    case '*':
      left = calculate(tree->left);
      right = calculate(tree->right);
      calculation=left *right;
      break;
    case '/':
      left = calculate(tree->left);
      right = calculate(tree->right);
      calculation=left / right;
      break;
    }
  }
return calculation;
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    // call private calculate method here
  TreeNode * node = expressionStack.top();
    int result = calculate(node);
    while(!expressionStack.empty()) expressionStack.pop();
    cleanTree(node);
    return result;
}

bool TreeCalc::isDigit(const string& val) {
  bool result = false;
  if(val.length() > 1 && val[0] == '-') return true;
  for(int i = 0; i < val.length(); i++) {
    if(val[i] <= '9' && val[i] >= '0') {
      result = true;
    }
    else {
      return false;
    }
  }
  return result;
}

bool TreeCalc::isOperator(string s) const {
  if(s.compare("+") == 0 || s.compare("-") == 0 || s.compare("*") == 0 || s.compare("/") == 0) return true;
  else return false;
}
