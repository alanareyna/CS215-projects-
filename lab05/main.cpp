#include <iostream>
#include "staticarray.hpp"
using namespace std;

int main( ) {
   StaticArray a;

   cout << "Printing empty array -- next line should be blank\n";
   a.print();

   // Loop to append 100 through 110 to a and check return value                                                                                                                                            
   // Should print "Couldn't append 110"                                                                                                                                                                    
   cout << "\nTesting append: Should print error message for 110 only\n";

   for (int i = 100; i < 111; i++) {
      if (!(a.append(i))) {
         cout << "Couldn't append " << i << endl;
      }
   }

   cout << "\nShould print 100 through 109 below:\n";
   a.print();

   int indices[] = { 9, 3, 5, 0 };
   // Loop to access some arbitrary elements of a                                                                                                                                                           
   cout << "\nTesting at:\n";
   cout << "Should print 109, 103, 105, 100\n";
   for (int i = 0; i < 4; i++) {
       cout << a.at(indices[i]) << " ";
   }
   cout << endl;

   // Save me from myself                                                                                                                                                                                   
   cout << "Should print your chosen value and not crash:\n";
   cout << a.at(10000000) << endl;

   // Print sum                                                                                                                                                                                             
   cout << "\nTesting sum: Should print 1045\n";
   cout << a.sum() << endl;

   // Test remove:                                                                                                                                                                                          
   //   Remove (a) 102                                                                                                                                                                                      
   //          (b) 111 (should return false)                                                                                                                                                                
   cout << "\nTesting remove. If you don't see 'Uh-oh,' that's a good sign.\n";
   if (!a.remove(102)) cout << "Uh-oh, can't remove 102\n";
   if (a.remove(111)) cout << "Uh-oh, shouldn't be able to remove 111\n";


   cout << "Final print: should print 100 101 103 ... 109\n";
   a.print();
   cout << endl;

   return 0;

}
