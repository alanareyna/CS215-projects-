// CS215 lab 3                                                                                                                                                                                              
// Alana Reyna                                                                                                                                                                                              
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void printReport(int v, int con, int d, int sc);
string getUserInput();
bool isVowel(int i, char c);

int main(){

  int i = 0;
  char c;
  int v = 0;
  int d = 0;
  int sc = 0;
  int con = 0;
  string s = getUserInput();
  while (i < s.length())
    {
      c = s[i];
      if(isalpha(c)) {
          if (isVowel(i, c))
            v++;
          else
            con++;
      }
      else if (isdigit(c)){
        d++;
      }
      else
        sc++;
      i++;
    }
  cout << "Past Input.\n";

  printReport(v, con, d, sc);
  return 0;
}
// prints how many vowels, consonants, digits, and special characters are in the string                                                                                                                     
void printReport(int v, int con, int d, int sc){
  cout<<"Vowels: "<<v<<endl;
  cout<<"Consonants: "<<con<<endl;
  cout<<"Digits: "<<d<<endl;
  cout<<"Special Characters: "<<sc<<endl;
}
// prints the prompt and gets the user's input, then returns that input                                                                                                                                     
 string getUserInput(){
   string s;
   cout<<"Enter a string: ";
   getline(cin, s);
   return s;
}
// returns true if the the character is a vowel and false otherwise.                                                                                                                                        
bool isVowel(int i, char c){
   c = toupper(c);
   if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
     return true;
   }
   else{
     return false;
   }
}
