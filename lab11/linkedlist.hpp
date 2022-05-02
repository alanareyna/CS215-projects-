#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
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

        int Size() const { return size; }

          LinkedList& operator=(const LinkedList& other);
          bool operator==(const LinkedList& other) const;
        friend ostream& operator<< (ostream& out, const LinkedList& LL);

    private:
        Node* first;
        Node* last;
        int size;
};
