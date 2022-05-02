#include <iostream>
using namespace std;
const int notvalid = -65342;
class DynamicArray {
   public:
  // default constructor: initialize capacity to INITIAL_CAP, len to 0, and allocate capacity to arr                                                                                                        
      DynamicArray();
  // destructor: deallocates any memory that was dynamically allocated                                                                                                                                      
      ~DynamicArray();
  //                                                                                                                                                                                                        
      DynamicArray(const DynamicArray& other);
      bool operator==(const DynamicArray& other) const;
      DynamicArray& operator=(const DynamicArray& other);
  friend ostream& operator << (ostream& out, const DynamicArray& pt);
  // append: if the array is at max capacity, it will allocate a new array with twice the capacity                                                                                                          
      void append(int newVal);
  // at: returns the value at the index given and if that index does not exist, return notvalid value                                                                                                       
      int at(int index) const;
  // sum: returns the sum of all the current array elements                                                                                                                                                 
      int sum() const;
  // remove: pass the value you want to remove and delete the element equal to that value. If the user has deleted a lot of elements, resize array to 80% of the capacity.                                  
      bool remove(int valToDelete);
// Print all array elements                                                                                                                                                                                 
  void print(std::ostream& s) const;
      int cap() const { return capacity; }

   private:
      int* arr;
      int len; // Number of elements actually populated                                                                                                                                                     
      int capacity; // New variable - this is the current capacity of the array                                                                                                                             

};
