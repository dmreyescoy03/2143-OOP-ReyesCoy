#include <iostream>
#include <fstream>
#include <vector>
#include "MyVector.h"

using namespace std;


int main() 
{ 
  MyVector V1;
  MyVector V2("input.txt");
  cout << "list 2: \n" << V2 << '\n';

  V2.sortLst();
  cout << "List 2 sorted:\n " << V2 << '\n';
  
  V1.pushFront(56);
  V1.pushFront(42);
  V1.pushFront(30);
  V1.pushFront(48);
  V1.pushFront(0);
  
  V1.sortLst();
  cout << "List 1: \n";
  cout << V1 << '\n';

  V1.pushAt(3, 10);
  cout << "List 1 with 10 inserted at subscript 3: \n";
  cout << V1 << '\n';
  V1.sortLst();
  cout << "list V1 sorted: " << V1 << '\n';

  V2.pushRear(V1);

  cout << "Sorted both list together: " << '\n';

  V2.sortLst();
  cout << V2 << '\n';
}