#include <fstream>
#include <iostream>
#include "stringArr.hpp"
using namespace std;

// default constructor: initialize len to 0                                                                                                                                                                 
StringArr::StringArr() {
  len = 0;
}

// alternative constructor: call readFromFile to use your file's contents and populate our array                                                                                                            
StringArr::StringArr(string filename) {
  readFromFile(filename);
}
// populate your string array by reading through the file                                                                                                                                                   
// it will return false if it was unable to read the file, otherwise it goes through each item in the file and puts it into the array while increasing the count and len                                    
bool StringArr::readFromFile(string filename) {
  fstream file(filename);
  if (!file.is_open()) {
    return false;
  }
  int count = 0;
  while (file >> array[count]) {
    count++;
    len++;
  }
  return true;
}

// print all the strings in the array one per line in the original order                                                                                                                                    
void StringArr::print() {
  for (int i = 0; i < len; i++) {
    cout << array[i]  << endl;
  }
  cout << endl; // new line                                                                                                                                                                                 
}

// return the shortest string in the array                                                                                                                                                                  
// if it is an empty array it will return an empty string                                                                                                                                                   
string StringArr::shortest() {
  // create a variable called shortest that will store the shortest array                                                                                                                                   
  // I initialized it to the first string                                                                                                                                                                   
  string shortest = array[0];
  if (len == 0) {
    return " ";
  }
  for (int i = 0; i < len; i++) {
    // if the string we're currently at is shorter than shortest(which we initially initialize to the first string) then i becomes the new shortest                                                         
    if (array[i].length() < shortest.length()) {
      shortest = i;
    }
  }
}
// same idea as shortest just changing if the string is longer than the longest                                                                                                                             
string StringArr::longest() {
  string longest = array[0];
  if (len == 0) {
    return " ";
  }
  for (int i = 0; i < len; i++) {
    if (array[i].length() > longest.length()) {
      longest = i;
    }
  }
  return longest;
}

// Swap function will help with printSorted, it changes the position of two strings                                                                                                                         
void StringArr::Swap(string& a, string& b) {
  string s = a;
  a =b;
  b = s;
}

// prints array in alphabetical order                                                                                                                                                                       
void StringArr::printSorted() {
  // creates new array which will be used to store sorted array                                                                                                                                             
  string array2[len];
  // copies over array to new array                                                                                                                                                                         
  for (int a = 0; a < len; a++) {
    array2[a] = array[a];
  }
  // goes through each string and uses swap function to switch two strings next eachother                                                                                                                   
  for (int i = 0; i < len; i++) {
    for (int j = 1; j < len; j++) {
      if (array2[j] < array2[j + 1]) {
        Swap(array[i], array[j]);
      }
      }
  }
  // prints new sorted array each string at a time on a new line                                                                                                                                            
  for (int i = 0; i < len; i++) {
    cout << array2[i] << endl;
  }
}

//returns the length of the longest ascending sequence of strings in the file                                                                                                                               
int StringArr::longestAscending(string seq[]) {
  string longest[len];
  int longest_len = 0;
  string possible[len];
  int possible_len = 0;
  if(len == 0) {
    return 0;
  }
  longest[0] = array[0];
  longest_len++;
  for (int i = 1; i < len; i++) {
    if (array[i-1] < array[i]) {
      possible[possible_len] = array[i];
      possible_len++;
    }
    else {
      if (possible_len > longest_len) {
        for (int j = 0; j < possible_len; j++) {
          longest[j] = possible[j];
        }
      }
      possible[0] = array[i];
      possible_len = 1;

      if (possible_len > longest_len) {
        for (int i = 0; i < possible_len; i++) {
          longest[i] = possible[i];
        }
        longest_len = possible_len;
      }
      for (int i = 0; i < longest_len; i++) {
        seq[i] = longest[i];
      }
    }
  }

  return longest_len;
}
// returns the length of the longest descending sequence of strings in the file                                                                                                                             
int StringArr::longestDescending(string seq[]) {
  string longest[len];
  int longest_len = 0;
  string possible[len];
  int possible_len = 0;
  if(len == 0) {
    return 0;
  }
  longest[0] = array[0];
  longest_len++;
  for (int i = 1; i < len; i++) {
    if (array[i-1] > array[i]) {
      possible[possible_len] = array[i];
      possible_len++;
    }
    else {
      if (possible_len > longest_len) {
        for (int j = 0; j < possible_len; j++) {
          longest[j] = possible[j];
        }
      }
      possible[0] = array[i];
      possible_len = 1;

      if (possible_len > longest_len) {
        for (int i = 0; i < possible_len; i++) {
          longest[i] = possible[i];
        }
        longest_len = possible_len;
      }
      for (int i = 0; i < longest_len; i++) {
        seq[i] = longest[i];
      }
    }
  }

  return longest_len;
}

