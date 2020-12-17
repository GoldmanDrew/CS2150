/*
Drew Goldman
dag5wd
9/15/2020
List.cpp
*/

#include <iostream>
#include <string>
#include <cctype>
#include "List.h"
using namespace std;

    // The default constructor.
    // It should initialize all private data members
    // and set up the basic list structure with the dummy head and tail nodes.
List::List() {
  count = 0;
  head = new ListNode();
  tail = new ListNode();
  head->next = tail;
  tail->previous = head;
}


// Copy constructor
// Called when the code looks something like List list2 = list1;
// (In other words, it is called when you are trying to construct a **new** list from an existing one)
List::List(const List& source) {
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

   // The destructor.
    // It should empty the list and reclaim the memory allocated in the constructor for head and tail.
List::~List() {
  makeEmpty();
  delete head;
  delete tail;
}


// Copy assignment operator
// Called when the code looks something like list2 = list1;
// (In other words, it is called when you are trying to set an **existing** list equal to another one)
List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
    }

    // Returns true if empty, else false
bool List::isEmpty() const {
  if(head->next == tail && tail->previous == head) return true;
  else return false;
}

    // Removes (deletes) all items except the dummy head/tail.
    // The list should be a working empty list after this.
void List::makeEmpty() {
  bool notEmpty = !isEmpty();
  while(notEmpty) {
    remove(first().retrieve());
    notEmpty = !isEmpty();
  }
}

    // Returns an iterator that points to the first ListNode **after** the dummy head node (even on an empty list!)
ListItr List::first() {
  return ListItr(head->next);
}
    // Returns an iterator that points to the last ListNode **before** the dummy tail node (even on an empty list!)
ListItr List::last() {
  return ListItr(tail->previous);
}

    // Inserts x after current iterator position
void List::insertAfter(int x, ListItr position) {
  ListNode* nNode = new ListNode();
  (*nNode).value = x;
  (*nNode).next = position.current->next;
  nNode->previous = position.current;
  (position).current->next->previous = nNode;
  (position).current->next = nNode;
  count++;
     
}

    // Inserts x before current iterator position
void List::insertBefore(int x, ListItr position) {
  ListNode* nNode = new ListNode();
  (*nNode).value = x;
  (*nNode).next = position.current;
  nNode->previous = position.current->previous;
  (position).current->previous->next = nNode;
  (position).current->previous = nNode;
  count++;
}

    // Inserts x at tail of list
void List::insertAtTail(int x) {
      ListNode* nNode = new ListNode();
      (*nNode).value = x;
      (*nNode).next = tail;
      (*nNode).previous = (*tail).previous;
      (*tail).previous->next = nNode;
      (*tail).previous = nNode;
      count++;
}

    // Returns an iterator that points to the first occurrence of x.
    // When the parameter is not in the list, return a ListItr object that points to the dummy tail node.
    // This makes sense because you can test the return from find() to see if isPastEnd() is true.
ListItr List::find(int x) {
  bool found = false;
  ListItr itr(first());
  while(!itr.isPastEnd()){
    if(itr.retrieve() == x) found = true;
    if(found) return itr;
    itr.moveForward();
  }
  ListItr *itrTail = new ListItr(tail);
  return  *itrTail;
}

    // Removes the first occurrence of x
void List::remove(int x) {
  ListItr itr(find(x));
  itr.current->previous->next = itr.current->next;
  itr.current->next->previous = itr.current->previous;
  delete itr.current;
  count--;
}

    // Returns the number of elements in the list
int List::size() const {
  return count;
}

// printList: non-member function prototype
// prints list forwards (head -> tail) when forward is true
// or backwards (tail -> head) when forward is false
// You **must** use your ListItr class to implement this function!
void printList(List& source, bool forward) {
  if(forward) {
    ListItr itr(source.first());
    int counter = 0;
    while (counter < source.size()) {
       cout << itr.retrieve() << " ";
       itr.moveForward();
       counter++;
    }
    cout << endl;
  }
  else {
    ListItr itr(source.last());
    int counter = source.size();
    while (counter > 0) {
       cout << itr.retrieve() << " ";
       itr.moveBackward();
       counter--;
    }
    cout << endl;
  }
}
