// Alana Reyna: Lab13 (ordered sets)                                                                                                                                                                        
#include <cstddef>
#include "orderedset.hpp"

OrderedSet::OrderedSet() {
  first = last = NULL;
  size = 0;
}

// copy constructor                                                                                                                                                                                         
OrderedSet::OrderedSet(const OrderedSet& other) {
  first = last = NULL;
  size = 0;
  Node* tempPtr = other.first;
  for (int i = 0; i < other.size; i++) {
    InsertLast(tempPtr->value);
    tempPtr = tempPtr->next;
    // first = first->next;                                                                                                                                                                                 
  }
}
// output operator                                                                                                                                                                                          
ostream& operator<< (ostream& out, const OrderedSet& LL) {
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

void OrderedSet::PrintBackwards(ostream& out) {
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
    out << walkingPtr->value << " ";
    walkingPtr = walkingPtr->prev;
    if (i == size - 2) {
      out << walkingPtr->value;
      break;
    }
  }
}

bool OrderedSet::Insert(int v) {
  Node* newNode = new Node;
  if (newNode == NULL) {
    return false;
  }
  newNode->value = v;
  newNode->prev = NULL;
  newNode->next = first;

  while (newNode->next != NULL) {
    if (newNode->value == (newNode->next)->value) {
      return false;
    }
    if (newNode->value < (newNode->next)->value) {
      break;
    }
    newNode->prev = newNode->next;
    newNode->next = newNode->next->next;
  }
  Node* predecessor = newNode->prev;
  if (predecessor == NULL) {

    first = newNode;
  }
else {
    predecessor->next = newNode;
  }
  if (newNode->next == NULL) {
    last = newNode;
  }
  else {
    (newNode->next)->prev = newNode;
  }

  size++;
  return true;
}

bool OrderedSet::InsertFirst(int v) {
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

bool OrderedSet::InsertLast(int v) {
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
bool OrderedSet::Delete(int v) {
  if(size == 0)
    return false;
  if (!exists(v))
    return false;

  Node* looking = first;
  if (v == first->value) {
    return DeleteFirst();
  }
  if (v == last->value) {
    return DeleteLast();
  }
  while (looking != NULL) {
    if (looking->value == v) {
      /*                                                                                                                                                                                                    
      looking->prev->next = looking->next;                                                                                                                                                                  
      looking->next->prev = looking->prev;                                                                                                                                                                  
      looking = NULL;                                                                                                                                                                                       
      size--;                                                                                                                                                                                               
      */
      Node* prevNode = looking->prev;
      Node* nextNode = looking->next;
      prevNode->next = nextNode;
      nextNode->prev = prevNode;
      size--;
      looking = NULL;
      return true;
    }
    looking = looking->next;
  }
  return false;
}
bool OrderedSet::DeleteFirst() {
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

bool OrderedSet::DeleteLast() {
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
OrderedSet& OrderedSet::operator=(const OrderedSet& other) {
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

OrderedSet::~OrderedSet() {
  while (size != 0) {
    DeleteFirst();
  }
}
bool OrderedSet::operator==(const OrderedSet& other) const {
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

void OrderedSet::apply(void function(int& param)) {
  for (Node* n = last; n != NULL; n = n->prev) {
    function(n->value);
  }
}

void OrderedSet::clear() {
  while(size != 0) {
    DeleteFirst();
  }
}

bool OrderedSet::exists(int v) {
  Node* looking = first;
  while (looking != NULL) {
    if (looking->value == v) {
      return true;
    }
    looking = looking->next;
  }
  return false;
}
OrderedSet OrderedSet::operator* (const OrderedSet& other) const {
  OrderedSet intersection;
  Node* list1 = first;
  Node* list2 = other.first;

  while (list1 != NULL && list2 != NULL) {
    if (list1->value == list2->value) {
      intersection.Insert(list1->value);
      list1 = list1->next;
      list2 = list2->next;
    }
    else if (list1->value > list2->value) {
      list2 = list2->next;
    }
    else {
      list1 = list1->next;
    }
  }
  return intersection;
}
OrderedSet OrderedSet::operator+ (const OrderedSet& other) const {
  OrderedSet set;
  Node* list1 = first;
  Node* list2 = other.first;

  while (list1 != NULL) {
    set.Insert(list1->value);
    list1 = list1->next;
  }
  while (list2 != NULL) {
    set.Insert(list2->value);
    list2 = list2->next;
  }
  return set;
}
