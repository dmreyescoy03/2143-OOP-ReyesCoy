/*****************************************************************************
*                    
*  Author:           David Reyes-coy
*  Email:            dmreyescoy0318@my.msutexas.edu
*  Label:            05-P01
*  Title:            MyVector class
*  Course:           2143-OOP
*  Semester:         Fall-2021
* 
*  Description:
*        This program took a linked list that acted as a basic stack, and was reconstructed
*        to be a more robust stack using a MyVector class. You are capable of inserting
*        new nodes, deleting, and inserting new nodes anywhere in the list. it
*        reads an input file and creates a new list then adds it to the current list.
* 
*  Usage:
*       Can be used to implement stacks, queues, graphs.
*       Dynimcally allocate memory. 
* 
*  Files: 
*     - MyVector.cpp: class implementation
*     - MyVector.h: Header file(containts list definitions)
*     - main.cpp: main driver of the program
*     - input.dat: Read data from file
*****************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include "MyVector.h"

using namespace std;
ofstream MyVector::fout;

int main() 
{

  MyVector V1; // declaring MyVector V1 as a list
  MyVector V2("input.dat"); //declaring a second list 
                            //loading it with data from a file

  V2.sortLst(); //calling the sort list fucntion 
  cout << "List 1: \n";

  //next 4 lines load list V1
  V1.pushFront(56);
  V1.pushFront(42);
  V1.pushFront(30);
  V1.pushFront(48);

  V1.sortLst(); // calling sort list command to sort V1
  cout << V1 << "\n"; //printing list V1 to the screen

  V1.pushAt(3, 100); // inserting a new value in V1 at subscript 3
  cout << V1 << "\n";// resorting the list
  cout << V1 << "\n"; // printing list V1 again

  V2.pushRear(V1); //pushing list V2 to the rear of V1
  cout << V2 << "\n"; //printng out list V2

  cout << "Sorted: " << "\n";

  V2.sortLst(); // sorting V2 
  cout << V2 << "\n"; // printing V2 once more
}