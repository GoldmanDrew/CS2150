/*
Drew Goldman
dag5wd
9/15/2020
ListItr.cpp
*/

#include <iostream>
#include "ListItr.h"
#include <string>
#include <cctype>
using namespace std;

// Constructors
ListItr::ListItr() {
  current = NULL;
}
ListItr::ListItr(ListNode* theNode) {
  current = theNode;
}

    // Returns true if the iterator is currently pointing past the end position
    // in the list (i.e., it's pointing to the dummy tail), else false
bool ListItr::isPastEnd() const {
  if(current == NULL) return true;
  else if(current->next == NULL) return true;
  else return false;
}

    // Returns true if the iterator is currently pointing past (before) the first position
    // in list (i.e., it's pointing to the dummy head), else false
bool ListItr::isPastBeginning() const {
  if(current == NULL) return true;
  if(current->previous == NULL) return true;
  else return false;
}

    // Advances `current` to the next position in the list (unless already past the end of the list)
void ListItr::moveForward() {
  if(!(isPastEnd())) current = current->next;
}

    // Moves `current` back to the previous position in the list (unless already past the beginning of the list)
void ListItr::moveBackward() {
  if(!(isPastBeginning())) current = current->previous;
}

    // Returns the value of the item in the current position of the list
int ListItr::retrieve() const {
  return current->value;
}
