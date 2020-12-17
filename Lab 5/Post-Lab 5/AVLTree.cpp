/*
Drew Goldman
dag5wd
10/8/2020
AVLTree.cpp
 */

#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
  if(!root) {
      root = insert(root, x);
      nodeCount++;
    }
  if(!find(x)) {
    root = insert(root,x);
    nodeCount++;
  }
}

AVLNode* AVLTree::insert(AVLNode* node, const string& x) {
  if(!node) {
    node = new AVLNode();
    node->value = x;
    node->height = 0;
    return node;
  }
  if(node->value.compare(x) > 0) node->left = insert(node->left, x);
  else if(node->value.compare(x) < 0) node->right = insert(node->right, x);
  node->height = 1 + max(height(node->right), height(node->left));
  balance(node);
  return node;
}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
  nodeCount--;
  root = remove(root, x);
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
  if(find(x)) return pathTo(root, x);
  return "";
}

string AVLTree::pathTo(AVLNode* node, const string& x) const{
  if(node && node->value.compare(x) == 0) {
      return node->value;
    }
    if(node->left && node->value.compare(x) > 0) {
      return node->value + " " +  pathTo(node->left, x);
    }
    if(node->right && node->value.compare(x) < 0) {
      return node->value + " " +  pathTo(node->right, x);
    }
  return "";
}

// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
  return find(root, x);
}

bool AVLTree::find(AVLNode* node, const string& x) const {
  if(node) {
    if (node->value.compare(x) == 0) {
      return true;
    }
    if(node->value.compare(x) > 0) {
      return find(node->left, x);
    }
    if(node->value.compare(x) < 0) {
      return find(node->right, x);
    }
  }
  return false;
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
    // YOUR IMPLEMENTATION GOES HERE
  return nodeCount;
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
    AVLNode* r = n->right;
    AVLNode* l = n->left;
    int balanceFactor = 0;
    if(n) balanceFactor = height(r) - height(l);
    if(balanceFactor > 1) {
      int rightBalanceFactor = height(r->right) - height(r->left);
      if(rightBalanceFactor < 0) n->right = rotateRight(n->right);
      n = rotateLeft(n);
    }
    else if(balanceFactor < -1) {
      int leftBalanceFactor = height(l->right) - height(l->left);
      if(leftBalanceFactor > 0) n->left = rotateLeft(n->left);
      n = rotateRight(n);
    }
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  AVLNode* r = n->right; 
  AVLNode* rl = r->left;  
  r->left = n;  
  n->right = rl;
  n->height = max(height(n->right), height(n->left)) + 1;
  r->height = max(height(r->right), height(r->left)) + 1;
  return r;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  AVLNode* l = n->left;  
  AVLNode* lr = l->right;  
  l->right = n;  
  n->left = lr;
  n->height = max(height(n->right), height(n->left)) + 1;
  l->height = max(height(l->right), height(l->left)) + 1;
  return l;
}

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
