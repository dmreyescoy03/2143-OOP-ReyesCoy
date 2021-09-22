#include <iostream>
#include <fstream>
#include <vector>
#include "MyVector.h"

using namespace std;
ofstream MyVector::fout;

int main() 
{

  MyVector V1;
  MyVector V2("input.dat");

  V2.sortLst();
  cout << "List 1: \n";
  V1.pushFront(56);
  V1.pushFront(42);
  V1.pushFront(30);
  V1.pushFront(48);

  V1.sortLst();
  cout << V1 << endl;

  V1.pushAt(3, 100);
  cout << V1 << endl;
  V1.sortLst();
  cout << V1 << endl;

  V2.pushRear(V1);
  cout << V2 << endl;

  cout << "Sorted: " << endl;

  V2.sortLst();
  cout << V2 << endl;
}