/*****************************************************************************
*                    
*  Author:           David Reyes-coy
*  Email:            dmreyescoy0318@my.msutexas.edu
*  Label:            06-P02
*  Title:            Class: MyVector
*  Course:           CMPS 2143
*  Semester:         Fall 2021
* 
*  Description:
*        This code contains a class called MyVector creating a doubly linked list.
*        making a more robust stack based linked list using overloaded operators.
* 
*  Usage:
*        N/A.
* 
*  Files:            main.cpp:    |driver file|
*                    MyVector.cpp |class driver file|
*                    MyVector.h   |header file for MyVector.cpp|
*                    input.txt    |file for input|
*****************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "MyVector.h"

using namespace std;

int main() 
{ 
  ofstream magic;
  magic.open("thisfile.txt");
  
  int a1[] = {1, 2, 3, 4, 5};
  int a2[] = {10, 20, 30};

  MyVector V1(a1, 5);
  MyVector V2(a2, 3); 
  
  cout << "List 1->  "<< V1 << '\n';
  cout << "List 2->  "<< V2 << '\n';

  V1[4] = 9;
  //V1 now = [1,2,3,4,9]
  cout << "List 1-> with subscript 4 replaced with int 9\n";
  cout << V1 << '\n';
  // // writes out [1,2,3,4,9] to console.

  magic << V1 << '\n';
  // writes out [1,2,3,4,9] to your output file.

  MyVector V3 = V1 + V2;
  cout << V3 << '\n';
  // writes out [11,22,33,4,9] to console.\

  V3 = V1 - V2;
  cout << V3 << '\n';
  magic << "V3 = V1-V2 -> ";
  magic << V3;
  // writes out [-9,-18,-27,4,9] to console.

  V3 = V2 - V1;
  magic << "V3 = V2-V1 -> ";
  cout << V3 << '\n';
  magic << V3 << '\n';
  // // writes out [9,18,27,4,9] to console.

  V3 = V2 * V1;
  magic << "V3 = V2*V1 -> ";
  cout << V3 << '\n';
  magic << V3 << '\n';
  // // writes out [10,40,90,4,9] to console.

  V3 = V1 * V2;
  magic << "V3 = V1*V2 -> ";
  cout << V3 << '\n';
  magic << V3 << '\n';
  // // writes out [10,40,90,4,9] to console.

  V3 = V1 / V2;
  magic << "V3 = V1/V2 -> ";
  cout << V3 << '\n';
  magic << V3 << '\n';
  // // writes out [0,0,0,4,9] to console.

  V3 = V2 / V1;
  magic << "V3 = V2/V1 -> ";
  cout << V3 << '\n';
  magic << V3 << '\n';
  // // writes out [10,10,10,4,9] to console.
  
  magic << "0 is false and 1 is true: \n";
  magic << "(V2==V1) -> ";
  cout << (V2 == V1) << '\n';
  magic << (V2==V1) << '\n';
  
  // // writes 0 to console (false) .

  magic << "(V4 = V1) -> ";
  MyVector V4 = V1;
  cout << (V4 == V1) << '\n';
  magic << (V4==V1);
  // writes 1 to console (true) .

  return 0;
}