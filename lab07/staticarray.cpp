#include <iostream>
#include "staticarray.hpp"
using namespace std;

StaticArray::StaticArray(){
  int len = 0;
}
bool StaticArray::append(int value){
  if(MAX>len){
    arr[len] = value;
    len++;
    return true;
  }
  else{
    return false;
  }
}
int StaticArray::at(int index){
  if (index < len){
    return arr[index];
  }
  else{
    return notvalid;
  }
}
// Print all array elements                                                                                                                                                                                 
void StaticArray::print() {
   for (int i = 0; i < len; i++) {
      cout << arr[i] << " ";
      if (i % 10 == 9) {
          cout << endl; // newline every 10 elements                                                                                                                                                        
      }
   }
}

int StaticArray::sum(){
  int sum = 0;
  for (int i=0; i < len; i++){
    sum = sum + arr[i];
  }
  return sum;
}

bool StaticArray::remove(int value){
  for (int i = 0; i < len; i++){
    if (arr[i] == value){
      len--;
      for (int j = i; j < len; j++){
        arr[j] = arr[j + 1];
      }
      return true;
    }
  }
  return false;
}
