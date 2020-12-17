/*
Drew Goldman
dag5wd
10/2/2020
Filename: TreeNode.cpp
*/
// TreeNode.cpp:  Tree Node method implementations
// CS 2150: Lab 5

#include "TreeNode.h"

// Default Constructor - left and right are NULL, value '?'
TreeNode::TreeNode() {
    value = "?";
    left = NULL;
    right = NULL;
}

// Constructor - sets value to val
TreeNode::TreeNode(const string& val) {
    value = val;
    left = NULL;
    right = NULL;
}
