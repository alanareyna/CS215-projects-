// CS215 lab 3                                                                                                                                                                                              
// Alana Reyna                                                                                                                                                                                              
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;

void printReport(int v, int con, int d, int sc, string s);
bool isVowel(char c);
void Swap(string& a, string& b);
void Sort(string W[], int N);

int main(){
  int count = 0;
  ifstream inFile("words.txt");
  string s[1000];

  while (inFile >> s[count]){
    count++;
  }
  Sort(s, count);

  for(int i = 0; i < count; i++){
    int v = 0;
  int d = 0;
  int sc = 0;
  int con = 0;
    for(int j = 0; j < s[i].length(); j++){

      if(isalpha(s[i][j])){
        if (isVowel(s[i][j]))
          v++;
        else
          con++;
      }
      else if (isdigit(s[i][j])){
        d++;
      }
      else
        sc++;
    }// end of inner loop()                                                                                                                                                                                 
    printReport(v, con, d, sc, s[i]);
  }  //end of outer loop()                                                                                                                                                                                  

  inFile.close();

   return 0;
}
// prints how many vowels, consonants, digits, and special characters are in the string                                                                                                                     
void printReport(int v, int con, int d, int sc, string s){
  cout<<s<<"  V="<<v<<"  C="<<con<<"  D="<<d<<"  S="<<sc<<endl;
}
// returns true if the the character is a vowel and false otherwise.                                                                                                                                        
 bool isVowel(char c){
   c = toupper(c);
   if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
     return true;
   }
   else{
     return false;
   }
 }
// swaps string a and b                                                                                                                                                                                     
void Swap(string& a, string& b) {
    string s = a;
    a = b;
    b = s;
}
// sorts through your array                                                                                                                                                                                 
void Sort(string W[], int N) {
    for (int i = 1; i < N; i++) {
        int j = i;
        while (j >0 and W[j] < W[j - 1]) {
            Swap(W[j], W[j-1]);
            j--;
        }
    }
}
