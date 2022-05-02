#include <cstddef>
#include "linkedlist.hpp"

LinkedList::LinkedList() {
  first = last = NULL;
  size = 0;
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

void LinkedList::PrintBackwards(ostream& out) {
  /*                                                                                                                                                                                                        
  Node* temp = last;                                                                                                                                                                                        
  while (temp != NULL) {                                                                                                                                                                                    
    out << temp->value;                                                                                                                                                                                     
    temp = temp->prev;                                                                                                                                                                                      
    if (temp != NULL) {                                                                                                                                                                                     
      out << " ";                                                                                                                                                                                           
    }                                                                                                                                                                                                       
    }*/

  Node* walkingPtr = last;
  for (int i = 0; i < size; i++) {
    if (size == 1) {
      out << walkingPtr->value;
      break;
    }
    out << walkingPtr->value << " ";
    walkingPtr = walkingPtr->prev;
    if (i == size - 2) {
      out << walkingPtr->value;
      break;
    }
  }
}

bool LinkedList::InsertFirst(int v) {
  Node* n = new Node;
  if (n == NULL) {
    return false;
  }
  n->value = v;
  n->prev = NULL;
  n->next = first;
  if (size != 0) {
    first->prev = n;
  }
  first = n;
  if (size == 0) {
    last = n;
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
  newNode->prev = last;
  newNode->next = NULL;
  if (size != 0) {
    last->next = newNode;
  }
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
  temp->prev = NULL;
  first = first->next;
  temp = NULL;
  size--;
  return true;
}
bool LinkedList::DeleteLast() {
  if (size <= 1){
    return DeleteFirst();;
  }
  Node* lastDel = last;
  last = last->prev;
  if (size != 1) {
    last->next = NULL;
  }
  lastDel = NULL;
  size--;
  return true;
}

LinkedList& LinkedList::operator=(const LinkedList& other) {
  if (this == &other) {
    return *this;
  }
  while (size != 0) {
    DeleteFirst();
  }
  Node* tempNode = other.first;
  while (tempNode != NULL) {
    InsertLast(tempNode->value);
    tempNode = tempNode->next;
  }
  return *this;
}
LinkedList::~LinkedList() {
  while (size != 0) {
    DeleteFirst();
  }
}

bool LinkedList::operator==(const LinkedList& other) const {
  if (size != other.size) {
    return false;
  }
  Node* list1 = first;
  Node* list2 = other.first;
  while (list1 != NULL) {
    if (list1->value != list2->value) {
      return false;
    }
    list1 = list1->next;
    list2 = list2->next;
  }
  return true;
}

void LinkedList::apply(void function(int& param)) {
  for (Node* n = last; n != NULL; n = n->prev) {
    function(n->value);
  }
}

void LinkedList::clear() {
  while(size != 0) {
    DeleteFirst();
  }
}

bool LinkedList::exists(int v) {
  Node* looking = first;
  while (looking != NULL) {
    if (looking->value == v) {
      return true;
    }
    looking = looking->next;
  }
  return false;
}
