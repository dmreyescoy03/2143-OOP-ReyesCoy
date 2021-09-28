#include <iostream>
#include <fstream>
#include <vector>
#include "MyVector.h"

using namespace std;


int main() 
{ 
  //declaring list
  MyVector V1;
  MyVector V2("input.txt");                // V2 loads data from an input file
  cout << "list 2: \n" << V2 << '\n';      // prints List 2 (V2) to the screen

  V2.sortLst();                               // sorting list 2 (V2) with the sortLst method
  cout << "List 2 sorted:\n " << V2 << '\n';  // printing sorted list 2 (making sure it worked)
  
  //next 5 lines loades list 1 (V1) with integers
  V1.pushFront(56);
  V1.pushFront(42);
  V1.pushFront(30);
  V1.pushFront(48);
  V1.pushFront(0);
  
  V1.sortLst();                                // sorting list 1 (V1) using the sortLst method
  cout << "List 1: \n";                       
  cout << V1 << '\n';                         // printing the sorted list 1 (V1)

  V1.pushAt(3, 10);                         // using the pushAt method to replace
                                            // a value in list 1 at subscript 3
  //printing out list 1 (making sure pushAt worked)
  cout << "List 1 with 10 inserted at subscript 3: \n";
  cout << V1 << '\n';

  V1.sortLst();                                // sorting list 1 again
  cout << "list V1 sorted: " << V1 << '\n';

  V2.pushRear(V1);                            // pushing list 1 to the end of list 2

  cout << "Sorted both list together: " << '\n';

  V2.sortLst();                             //sorting list 2 again
                                            // printing out list 2 showing
                                            // both sorted list
  cout << V2 << '\n';
}