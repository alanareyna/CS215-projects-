const int MAX = 10;
const int notvalid = -65342;

class StaticArray {
   public:
       StaticArray();
       bool append(int value);
  int at(int index);
  int sum();
  bool remove(int value);
  ~StaticArray() { } // destructor - ignore for now                                                                                                                                                         
      void print();

   private:
      int arr[MAX];
  int len = 0;

};
