#include <string>
const int MAXSIZE = 1000;

using namespace std;

class StringArr {
    public:
        StringArr(); // default constructor                                                                                                                                                                 
        StringArr(std::string filename); // alternate constructor: read strings from file                                                                                                                   
        ~StringArr() { } // shouldn't need to change this                                                                                                                                                   

        bool readFromFile(std::string filename);
        void print(); // Print all strings in the file, one per line                                                                                                                                        
        std::string shortest(); // return the shortest string in the array. Can break ties however you want.                                                                                                
        std::string longest(); // return the longest string in the array. Can break ties however you want.                                                                                                  

        void printSorted(); // Print strings in ascending order, but don't actually change the array                                                                                                        
        int longestAscending(std::string seq[]); // Populate seq with the longest sequence of alphabetically ascending strings (A-Z), and return the length of the sequence                                 
        int longestDescending(std::string seq[]);


    private:
  string array[MAXSIZE];
  int len;
  void Swap(string& a, string& b);
        /* Whatever you use to store data, along with any helper functions,                                                                                                                                 
 *         go here */
};
