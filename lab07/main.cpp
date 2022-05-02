#include <iostream>
#include "dynamicarray.hpp"
using namespace std;

int main( ) {
   DynamicArray a;

   cout << "Printing empty array -- next line should be blank\n";
   a.print();


   // Loop to append 100 through 110 to a (11 elements total)                                                                                                                                               
   cout << "\nTesting append: Shouldn't crash!\n";

   for (int i = 100; i < 111; i++) {
      a.append(i);
   }

   cout << "\nShould print 100 through 110 below, with 110 on a new line:\n";
   a.print();

   cout << "\nChecking capacity of new array:\n";
   if (a.cap() == 20) cout << "OK\n";
   else cout << "Error: cap is " << a.cap() << ", should be 20\n";


   // Loop to append 111 through 120 (21 elements total):                                                                                                                                                   
   cout << "\nAppend test #2:\n";

   for (int i = 111; i < 121; i++) {
      a.append(i);
   }
   cout << "\nShould print 100 through 120 below, on 3 separate lines:\n";
   a.print();


   cout << "\nChecking capacity of new array:\n";
   if (a.cap() == 40) cout << "OK\n";
   else cout << "Error: cap is " << a.cap() << ", should be 40\n";


   int indices[] = { 9, 3, 5, 0, 18 };
   // Loop to access some arbitrary elements of a                                                                                                                                                           
   cout << "\nTesting at:\n";
   cout << "Should print 109, 103, 105, 100, 118\n";
   for (int i = 0; i < 5; i++) {
       cout << a.at(indices[i]) << " ";
   }
   cout << endl;

   // Save me from myself                                                                                                                                                                                   
   cout << "Should print your chosen value and not crash:\n";
   cout << a.at(10000000) << endl;

   // Print sum                                                                                                                                                                                             
   cout << "\nTesting sum: Should print 2310\n";
   cout << a.sum() << endl;
// Test remove:                                                                                                                                                                                          
   //   Remove (a) 102                                                                                                                                                                                      
   //          (b) 122 (should return false)                                                                                                                                                                
   cout << "\nTesting remove. If you don't see 'Uh-oh,' that's a good sign.\n";
   if (!a.remove(102)) cout << "Uh-oh, can't remove 102\n";
   if (a.remove(122)) cout << "Uh-oh, shouldn't be able to remove 111\n";

   // More tests: first, add 102 back in                                                                                                                                                                    
   a.append(102);
   cout << "\nChecking capacity of new array:\n";
   if (a.cap() == 40) cout << "OK\n";
   else cout << "Error: cap is " << a.cap() << ", should be 40\n";

   cout << "\nEliminating elements, one by one, from array, and testing resize.\n";
   int capacities[] = {40,             // len is 20                                                                                                                                                         
                       32, 32, 32, 32, // len is 19, 18, 17, 16                                                                                                                                             
                       25, 25, 25,     // len is 15, 14, 13                                                                                                                                                 
                       20, 20, 20,     // len is 12, 11, 10,                                                                                                                                                
                       16, 16, 12, 12, 10, // len is 9, 8, 7, 6, 5                                                                                                                                          
                       10, 10, 10, 10, 10 // 4, 3, 2, 1, 0                                                                                                                                                  
                      };
   for (int i = 0; i < 21; i++) {
      a.remove(100 + i);
      if (a.cap() != capacities[i]) {
         cout << "Resize error! Removed " << 100 + i << ", capacity is " << a.cap()
              << ", should be " << capacities[i] << endl;
      }
   }
   cout << "\nRemove and resize test passed if no errors reported above.\n";


   cout << "\nAdding 152 to array. Final print should print just 152.\n";
   a.append(152);
   a.print();
   cout << endl;


   return 0;

}
