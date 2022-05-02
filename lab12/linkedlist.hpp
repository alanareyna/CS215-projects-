#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
  Node* prev;
};

class LinkedList {

    public:
        LinkedList();
          LinkedList(const LinkedList& other);
          ~LinkedList();

          bool InsertFirst(int v);
          bool InsertLast(int v);
          bool DeleteFirst();
          bool DeleteLast();
          void PrintBackwards(ostream& out);
          int Size() const { return size; }

          LinkedList& operator=(const LinkedList& other);
          bool operator==(const LinkedList& other) const;
          friend ostream& operator<< (ostream& out, const LinkedList& LL);
          void apply(void function(int& (param)));
          void clear();
          bool exists(int v);
    private:
        Node* first;
        Node* last;
        int size;
};
