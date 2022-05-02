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

int DynamicArray::at(int index) {
  if (index < len){
    return arr[index];
  }
  else {
    return notvalid;
  }
}

int DynamicArray::sum() {
  int sum = 0;
  for (int i = 0; i < len; i++) {
    sum = sum + arr[i];
  }
  return sum;
}
bool DynamicArray::remove(int valToDelete) {
  for (int i = 0; i < len; i++) {
    if (arr[i] == valToDelete) {
      len--;
      for (int j = i; j < len; j++) {
        arr[j] = arr[j + 1];
      }
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

void DynamicArray::print() {
   for (int i = 0; i < len; i++) {
      cout << arr[i] << " ";
      if (i % 10 == 9) {
          cout << endl; // newline every 10 elements                                                                                                                                                        
      }
   }
   cout << endl;
}
