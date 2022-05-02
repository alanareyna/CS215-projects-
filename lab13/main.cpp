#include <iostream>
#include <sstream>
#include "orderedset.hpp"
using namespace std;

bool RunListTests(OrderedSet& a);
bool RunLab12Tests();
void RunLab13Tests();
bool RunIndividualTest(string desiredOutput, string actualOutput, string testLabel);

int main( ) {
   OrderedSet a;

   cout << "*** List tests on original list: "
        << (RunListTests(a) ? "passed" : "failed") << endl;

   // TEST 8: COPY CONSTRUCTOR                                                                                                                                                                              
   OrderedSet b(a);
   b.Delete(152);
   cout << "*** List tests on version created with copy constructor: "
        << (RunListTests(b) ? "passed" : "failed") << endl;

   // TEST 9: EQUALITY COMPARISON                                                                                                                                                                           
   cout << "Testing equality comparison operator: "
        << (a == b ? "passed" : "failed") << endl;
   b.Insert(1000); // add a new element to b                                                                                                                                                                
   cout << "Retesting after modifying 1 array: "
        << (a == b ? "failed" : "passed") << endl;

   // TEST 10: ASSIGNMENT OPERATOR                                                                                                                                                                          
   b = b; // make sure this doesn't break                                                                                                                                                                   
   cout << "Testing assignment operator on self-assignment: "
        << (b == b ? "passed" : "failed") << endl;
   a = b;
   cout << "Testing assignment operator: "
        << (a == b ? "passed" : "failed") << endl;

   // LAB 13 TESTS                                                                                                                                                                                          
   RunLab13Tests();

   cout << endl;
   return 0;
}

bool RunIndividualTest(string desiredOutput, string actualOutput, string testLabel) {
    if (desiredOutput != actualOutput) {
        cout << "\nTEST FAILED: " << testLabel << endl;
        return false;
    }
    return true;
}

void RunLab13Tests() {
    OrderedSet a, b;

    for (int i = 0; i < 20; i += 2) a.Insert(i);
    for (int i = 0; i < 12; i++) b.Insert(i);
    cout << "List A is: " << a << endl;
    cout << "List B is: " << b << endl;
    cout << "Set union is: " << a + b << endl;
    cout << "Set intersection is: " << a * b << endl;
}

void Double(int& i) {
    i *= 2;
}

bool RunLab12Tests() {
   OrderedSet a;
   bool pass = true;
   int elements[] = { 313, 308, 314, 304, 305, 310, 301, 302, 307, 300, 309, 312, 311, 306, 303 };

   for (int i = 0; i < 15; i++) a.Insert(elements[i]);
   pass &= RunIndividualTest("0", a.exists(610) ? "1" : "0", "Existence test 1");

   a.apply(Double);
   pass &= RunIndividualTest("1", a.exists(610) ? "1" : "0", "Existence test 2");

   stringstream testoutput;
   testoutput << a;
   pass &= RunIndividualTest("600 602 604 606 608 610 612 614 616 618 620 622 624 626 628", testoutput.str(), "Apply");

   a.clear();
   testoutput.str("");
   testoutput << a;
   pass &= RunIndividualTest("", testoutput.str(), "Contents afer clear()");
   pass &= RunIndividualTest("0", to_string(a.Size()), "Size after clear()");

   return pass;
}

/* Run individual insert, delete, etc. tests */
bool RunListTests(OrderedSet& a){
   stringstream testoutput;
   bool pass = true;

   // TEST 1: Print contents and size of empty list                                                                                                                                                         
   testoutput << a;
   pass &= RunIndividualTest("", testoutput.str(), "Print empty array");
   pass &= RunIndividualTest("0", to_string(a.Size()), "Size of empty array");
   testoutput.str("");
   a.PrintBackwards(testoutput);
   pass &= RunIndividualTest("", testoutput.str(), "Print empty array backwards");

   // TEST 2: Add first 11 shuffled values into list                                                                                                                                                        
   int elements[] = { 212, 205, 208, 210, 203, 220, 204, 207, 209, 202, 214, 219, 216, 218, 215, 213, 201, 206, 217, 211, 200 };
   testoutput.str("");
   for (int i = 0; i < 11; i++) {
      pass &= a.Insert(elements[i]);
   }
   testoutput << a;
   pass &= RunIndividualTest("202 203 204 205 207 208 209 210 212 214 220",
      testoutput.str(), "Insert: First 11 elements");
   pass &= RunIndividualTest("11", to_string(a.Size()),
       "Size after adding 11 elements to empty array");
  
   // TEST 3: Append next 10 shuffled values                                                                                                                                                                
   testoutput.str(""); // Reset test output string                                                                                                                                                          
   for (int i = 11; i < 21; i++) {
      pass &= a.Insert(elements[i]);
   }
   testoutput << a;
   pass &= RunIndividualTest(
      "200 201 202 203 204 205 206 207 208 209 210 211 212 213 214 215 216 217 218 219 220",
      testoutput.str(), "Insert: Next 10 elements");
   pass &= RunIndividualTest("21", to_string(a.Size()),
      "Size after adding 10 elements to 11-element array");

   testoutput.str("");
   a.PrintBackwards(testoutput);
   pass &= RunIndividualTest("220 219 218 217 216 215 214 213 212 211 210 209 208 207 206 205 204 203 202 201 200",
       testoutput.str(), "Insert: Backwards traversal");

   // TEST 4: Delete last 10 elements that were added                                                                                                                                                       
   testoutput.str("");
   for (int i = 11; i < 21; i++) {
       pass &= a.Delete(elements[i]);
   }
   testoutput << a;
   pass &= RunIndividualTest(
      "202 203 204 205 207 208 209 210 212 214 220",
      testoutput.str(), "After deleting first 10 elements");
   pass &= RunIndividualTest("11", to_string(a.Size()), "Size after deleting 1st 10 elements");
   testoutput.str("");
   a.PrintBackwards(testoutput);
   pass &= RunIndividualTest("220 214 212 210 209 208 207 205 204 203 202",
       testoutput.str(), "Delete first 10 elements: Backwards traversal");
   // TEST 5: Delete next 10 elements that were added                                                                                                                                                       
   testoutput.str("");
   for (int i = 1; i < 11; i++) {
       pass &= a.Delete(elements[i]);
   }
   testoutput << a;
   cout << a;
   pass &= RunIndividualTest("212", testoutput.str(), "After Delete 10 elements");
   pass &= RunIndividualTest("1", to_string(a.Size()), "Size after deleting 10 elements");
   testoutput.str("");
   a.PrintBackwards(testoutput);
   pass &= RunIndividualTest("212", testoutput.str(), "Deleting 11th through 20th elements: Backwards traversal");

   testoutput.str("");
   pass &= a.Delete(212);
   testoutput << a;
   pass &= RunIndividualTest("", testoutput.str(), "After deleting remaining element");
   pass &= RunIndividualTest("0", to_string(a.Size()), "Size after deleting all elements");


   // TEST 6: Try to delete nonexistent element                                                                                                                                                             
   pass &= RunIndividualTest("0", to_string(a.Delete(12)), "Delete on empty list");
   pass &= RunIndividualTest("0", to_string(a.Size()), "Size after deletes on empty list");

   // TEST 7: Add one value back in                                                                                                                                                                         
   testoutput.str(""); // Reset test output string                                                                                                                                                          
   a.Insert(152);
   testoutput << a;
   pass &= RunIndividualTest("152", testoutput.str(), "Final Insert on empty list");
   pass &= RunIndividualTest("1", to_string(a.Size()), "Size after final Insert");
   testoutput.str("");
   a.PrintBackwards(testoutput);
   pass &= RunIndividualTest("152", testoutput.str(), "Backwards traversal of 1-element list");

   // LAB 12 TESTS                                                                                                                                                                                          
   pass &= RunLab12Tests();

   return pass;
}
