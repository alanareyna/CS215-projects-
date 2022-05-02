#include <cstddef>
#include "linkedlist.hpp"

LinkedList::LinkedList() {
  first = last = NULL;
  size = 0;
}

LinkedList::~LinkedList() {
  Node* walkPtr = first;
  while (walkPtr != NULL) {
    DeleteFirst();
    walkPtr = walkPtr->next;
  }
}

LinkedList::LinkedList(const LinkedList& other) {
  first = last = NULL;
  size = 0;
  Node* tempPtr = other.first;
  for (int i = 0; i < other.size; i++) {
    InsertLast(i);
    tempPtr = first;
    first = first->next;
  }
}

LinkedList& LinkedList::operator=(const LinkedList& other) {
  if (this == &other) return *this;
  Node* walkingPtr = first;
  while (walkingPtr != NULL) {
    DeleteFirst();
    walkingPtr = walkingPtr->next;
  }
  Node* tempPtr = other.first;
  for (int i = 0; i < other.size; i++) {
    InsertLast(tempPtr->value);
    tempPtr = tempPtr->next;
  }
  return *this;
}

bool LinkedList::operator==(const LinkedList& other) const {
  if (size != other.size) {
    return false;
  }
  Node* WPtr = first;
  Node* OtherWPtr = other.first;
  while (WPtr != NULL) {
    if (WPtr->value != OtherWPtr->value){
      return false;
    }
    WPtr = WPtr->next;
    OtherWPtr = OtherWPtr->next;
  }
  return true;
}
ostream& operator<< (ostream& out, const LinkedList& LL) {
  Node* walkingPtr = LL.first;
  for (int i = 0; i < LL.size; i++) {
    if (LL.size == 1) {
      out << walkingPtr->value;
      break;
    }
    out << walkingPtr->value << " ";
    walkingPtr = walkingPtr->next;
    if (i == LL.size - 2) {
      out << walkingPtr->value;
      break;
    }
  }
  return out;
}

bool LinkedList::InsertFirst(int v) {
  Node* newNode = new Node;
  if (newNode == NULL) {
    return false;
  }
  newNode->value = v;
  if (size == 0) {
    first = newNode;
    last = newNode;
  }
  else {
    newNode->next = first;
    first = newNode;
  }
  size++;
  return true;
}

bool LinkedList::InsertLast(int v) {
  if (size == 0) {
    return InsertFirst(v);
  }
  Node* newNode = new Node;
  if (newNode == NULL) {
    return false;
  }
  newNode->value = v;
  last->next = newNode;
  last = newNode;
  size++;
  return true;
}

bool LinkedList::DeleteFirst() {
  if (size == 0) {
    return false;
  }
  else if (size == 1) {
    last = first = NULL;
    size--;
    return true;
  }
  Node *temp = first;
  first = first->next;
  temp = NULL;
  size--;
  return true;
}

bool LinkedList::DeleteLast() {
  if (size == 0){
    return false;
  }
  else if (size == 1) {
    DeleteFirst();
    return true;
  }
  Node* walkingPtr;
  walkingPtr = first;
  while (walkingPtr != NULL) {
    if (walkingPtr->next == last) {
      size--;
      last = walkingPtr;
      delete walkingPtr->next;
      walkingPtr->next = NULL;
      return true;
    }
    walkingPtr = walkingPtr->next;
  }
}
