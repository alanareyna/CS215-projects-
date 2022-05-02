const int notvalid = -65342;

class DynamicArray {
   public:
  // default constructor: initialize capacity to INITIAL_CAP, len to 0, and allocate capacity to arr                                                                                                        
      DynamicArray();
  // destructor: deallocates any memory that was dynamically allocated                                                                                                                                      
      ~DynamicArray();
  // append: if the array is at max capacity, it will allocate a new array with twice the capacity                                                                                                          
      void append(int newVal);
  // at: returns the value at the index given and if that index does not exist, return notvalid value                                                                                                       
      int at(int index);
  // sum: returns the sum of all the current array elements                                                                                                                                                 
      int sum();
  // remove: pass the value you want to remove and delete the element equal to that value. If the user has deleted a lot of elements, resize array to 80% of the capacity.                                  
      bool remove(int valToDelete);
// Print all array elements                                                                                                                                                                                 
      void print();
      int cap() { return capacity; }

   private:
      int* arr;
      int len; // Number of elements actually populated                                                                                                                                                     
      int capacity; // New variable - this is the current capacity of the array                                                                                                                             

};
