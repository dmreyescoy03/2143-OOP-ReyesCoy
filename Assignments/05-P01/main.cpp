/**************************************************************************                
*  Author:           David Reyes-coy
*  Email:            dmreyescoy0318@my.msutexas.edu
*  Label:            05-P01
*  Title:            Class: MyVector
*  Course:           CMPS 2143
*  Semester:         Fall 2021
* 
*  Description:
*       creates a class myvector, with functions similar to a stack(pop,push,find)
*       it can push new nodes to the list. push a list to another list. searches
*       for values
*       
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
#include "MyVector.h"

using namespace std;

int main()
{
  ofstream outfile("output.txt");
  int Value = 0;
  int A[] = {11, 25, 33, 47, 51};
  MyVector V1;
  MyVector V2(A, 5);

  V1.pushFront(18);
  V1.pushFront(20);
  V1.pushFront(25);
  V1.pushRear(18);
  V1.pushRear(20);
  V1.pushRear(25);
  cout << "List 1: ";
  outfile << "List 1: ";
  V1.print();
  V1.oPrint(outfile);
  // [25, 20, 18, 18, 20, 25]

  cout << "\nList 2: ";
  outfile << "\nList 2: ";
  V2.print();
  V2.oPrint(outfile);
  // [11, 25, 33, 47, 51]

  V2.pushFront(9);
  //V2.inOrderPush(27);
  V2.pushRear(63);
  cout << "\nUpdated List 2: ";
  outfile << "\nUpdated List 2: ";
  V2.print();
  V2.oPrint(outfile);
  // [9, 11, 25, 27, 33, 47, 51, 63]

  V1.pushRear(V2);
  cout << "\nList 1 & 2: ";
  outfile << "\nList 1 & 2: ";
  V1.print();
  V1.oPrint(outfile);
  // [25, 20, 18, 18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]

  Value = V1.popFront();
  Value = V1.popFront();
  Value = V1.popFront();
  cout << "\nUpdated List 1 & 2:";
  outfile << "\nUpdated List 1 & 2: ";
  V1.print();
  V1.oPrint(outfile);
  // [18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]
  cout << "\nValue: " << Value << '\n';
  outfile << "\nValue: " << Value << '\n';
  // 18

  Value = V1.popRear();
  Value = V1.popRear();
  Value = V1.popRear();
  cout <<"\nList Updated: ";
  outfile << "\nList Updated: ";
  V1.print();
  V1.oPrint(outfile);
  // [18, 20, 25, 9, 11, 25, 27, 33]
  cout << "\nValue: " << Value << '\n';
  outfile << "\nValue: " << Value << '\n';
  // 47

  Value = V2.popAt(3);
  cout << "\nList Updated: ";
  outfile << "\nList Updated: "; 
  V2.print();
  V2.oPrint(outfile);
  // [9, 11, 25, 33, 47, 51, 63]
  cout << "\nValue: " << Value << '\n';
  outfile << "\nValue: " << Value << '\n';
  // 27

  Value = V2.find(51);
  cout << "\nat subscript: "  << Value << '\n';
  outfile << "\nat subscript: " << Value << '\n';
  // 5

  Value = V2.find(99);
  cout << "\n(-1) means not found\n";
  cout << "at subscript: " << Value << '\n';
  outfile << "at subscript: " << Value << '\n';
  // -1

  MyVector V3(V1);
  cout <<"\nList 3: ";
  outfile << "\nList 3: ";
  V3.print();
  V3.oPrint(outfile);
  // [18, 20, 25, 9, 11, 25, 27, 33]
  
  V3.pushFront(V2);
  cout << "\nList 3 & 2: ";
  outfile << "\nList 3 & 2: "; 
  V3.print();
  V3.oPrint(outfile);
  cout << '\n';
  //[9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

  MyVector V4("input.dat");
  V4.pushRear(V3);
  cout << "\nList 4: ";
  outfile << "\nList 4: ";
  V4.print();
  V4.oPrint(outfile);
  // [56, 61, 97, 66, 83, 25, 26, 11, 53, 49, 62, 18, 10, 18, 14, 3, 4, 23, 18, 24, 26, 27, 54, 14, 12, 45, 65, 98, 56, 97, 15, 84, 98, 9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

  outfile.close();
  return 0;
}