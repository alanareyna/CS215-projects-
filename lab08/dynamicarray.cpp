#include <iostream>
#include "dynamicarray.hpp"
using namespace std;

const int INITIAL_CAP = 10;

DynamicArray::DynamicArray() {
  capacity = INITIAL_CAP;
  arr = new int[INITIAL_CAP];
  len = 0;
}

DynamicArray::~DynamicArray() {
  delete [] arr;
}

// copy constructor                                                                                                                                                                                         
DynamicArray::DynamicArray(const DynamicArray& other) {
  capacity = other.capacity;
  len = other.len;
  arr = new int[capacity];
  for (int i = 0; i < len; i++){
    arr[i] = other.arr[i];
  }
}

// equality operator                                                                                                                                                                                        
bool DynamicArray::operator==(const DynamicArray& other) const{
  if (len == other.len) {
    for (int i = 0; i < len; i++) {
      if (arr[i] != other.arr[i]) {
        return false;
      }
    }
    return true;
  }
  return false;
}

// assignment operator                                                                                                                                                                                      
DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
  capacity = other.capacity;
  len = other.len;
  if (arr == other.arr) {
    return *this;
  }
  delete [] arr;
  arr = new int[capacity];
  for (int i = 0; i < len; i++) {
    arr[i] = other.arr[i];
  }
  return *this;
}

// output operator                                                                                                                                                                                          
ostream& operator<< (ostream &out, const DynamicArray& pt) {
  for (int i = 0; i < pt.len; i++) {
      out << pt.arr[i] << " ";
      if (i % 10 == 9) {
          out << endl; // newline every 10 elements                                                                                                                                                         
      }
   }
   out << endl;
}

void DynamicArray::append(int newVal) {
  if(capacity == len){
    capacity = capacity * 2;
    int* big_arr = new int[capacity];
    for (int i = 0; i < len; i++) big_arr[i] = arr[i];
    int* temp_pointer = arr;
    arr = big_arr;
    delete [] temp_pointer;
  }
  arr[len] = newVal;
  len++;
}

int DynamicArray::at(int index) const {
  if (index < len){
    return arr[index];
  }
  else {
    return notvalid;
  }
}
int DynamicArray::sum() const{
  int sum = 0;
  for (int i = 0; i < len; i++) {
    sum = sum + arr[i];
  }
  return sum;
}

bool DynamicArray::remove(int valToDelete) {
  for (int i = 0; i < len; i++) {
    if (arr[i] == valToDelete) {
      for (int j = i; j < len; j++) {
        arr[j] = arr[j + 1];
      }
      len--;
      if (len < (0.5 * capacity)){
        capacity = (capacity * 0.8 );
        if (capacity < 10){
          capacity = 10;
        }
        int* newarray = new int[capacity];
        for(int x = 0; x < len; x++) newarray[x] = arr[x];
        int* temp_pointer = arr;
        arr = newarray;
        delete[] temp_pointer;
      }
      return true;
    }
  }
  return false;
}
void DynamicArray::print(std::ostream& s) const{
   for (int i = 0; i < len; i++) {
      s << arr[i] << " ";
      if (i % 10 == 9) {
          s << endl; // newline every 10 elements                                                                                                                                                           
      }
   }
   s << endl;
}
