#include <iostream>
#include <vector>
using namespace std;

const int notvalid = -65342;
class DynamicArray {
public:
  DynamicArray();

  DynamicArray(const DynamicArray& other);

  ~DynamicArray();

  void append(int newVal);

  int at(int index) const;

  int sum() const;

  bool remove(int ValToDelete);

  bool operator==(const DynamicArray& other) const;

  DynamicArray& operator=(const DynamicArray& otherArray);

  friend std::ostream& operator << (std::ostream& out, const DynamicArray& other);

  int cap()const { return arr.capacity(); }

  void print(std::ostream& s) const;

private:
  vector<int> arr;

};
