#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* prev;
    Node* next;
};

class OrderedSet {

    public:
  OrderedSet(); //                                                                                                                                                                                          
  OrderedSet(const OrderedSet& other); //copy constructor                                                                                                                                                   
  ~OrderedSet(); // destructor                                                                                                                                                                              

  void apply(void function(int& param)); // applies a function to every element of list                                                                                                                     
  bool Insert(int v); // inserts specified value in numerical order                                                                                                                                         
  bool Delete(int v); // deletes specified value in the list if it exists                                                                                                                                   
  int Size() const { return size; } //                                                                                                                                                                      

  void PrintBackwards(ostream& out); // prints list in reverse order                                                                                                                                        
  void clear(); // deletes all elements in the list                                                                                                                                                         
  bool exists(int v); // returns true if int v is a value in the list                                                                                                                                       

  OrderedSet& operator=(const OrderedSet& other); // assignment operator                                                                                                                                    
        OrderedSet operator+(const OrderedSet& other) const;
        OrderedSet operator*(const OrderedSet& other) const;
  bool operator==(const OrderedSet& other) const; // equality operator                                                                                                                                      
  friend ostream& operator<< (ostream& out, const OrderedSet& LL); //                                                                                                                                       

    private:
        Node* first;
        Node* last;
        int size;

  bool InsertFirst(int v); // inserts int v at the beginning of list                                                                                                                                        
  bool InsertLast(int v); // inserts int v at the end of the list                                                                                                                                           
  bool DeleteFirst(); // deletes first element of list                                                                                                                                                      
  bool DeleteLast(); //deletes last element of the list                                                                                                                                                     
};
