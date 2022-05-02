#include <iostream>
#include "dynamicarray.hpp"
using namespace std;


DynamicArray::DynamicArray() {}

DynamicArray::~DynamicArray() {}

// copy constructor                                                                                                                                                                                         
DynamicArray::DynamicArray(const DynamicArray& other) : arr(other.arr) {}

// equality operator                                                                                                                                                                                        
bool DynamicArray::operator==(const DynamicArray& other) const{
  if (arr.size() != other.arr.size()) {
    return false;
  }
  for (int i = 0; i < arr.size(); i++) {
    if (arr.at(i) != other.arr.at(i)) {
      return false;
    }
  }
  return true;
}

// assignment operator                                                                                                                                                                                      
DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
  arr = other.arr;
  return *this;
}

// output operator                                                                                                                                                                                          
ostream& operator<< (ostream &out, const DynamicArray& other) {
  for (int i = 0; i < other.arr.size(); i++) {
    out << other.arr.at(i) << " ";
      if (i % 10 == 9) {
          out << endl; // newline every 10 elements                                                                                                                                                         
      }
   }
   out << endl;
}

void DynamicArray::append(int newVal) {
  arr.push_back(newVal);
}

int DynamicArray::at(int index) const {
  return arr.at(index);
}

int DynamicArray::sum() const{
  int sum = 0;
  for (int i = 0; i < arr.size(); i++) {
    sum = sum + arr.at(i);
  }
  return sum;
}

bool DynamicArray::remove(int valToDelete) {
  int index = -1;
  for (int i = 0; i < arr.size(); i++) {
    if(arr[i] == valToDelete) {
      index = i;
    }
  }
  if (index == -1) {
    return false;
  }
  arr.erase(arr.begin() + (index));
  return true;
}

void DynamicArray::print(std::ostream& s) const{
  for (int i = 0; i < arr.size(); i++) {
     s << arr.at(i) << " ";
      if (i % 10 == 9) {
          s << endl; // newline every 10 elements                                                                                                                                                           
      }
   }
   s << endl;
}
