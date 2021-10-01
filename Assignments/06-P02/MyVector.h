#pragma once
#include <iostream>
#include <string>
#include <fstream>

#define INF 10000;
using namespace std;
/**
* Class: MyVector
* 
* Description:
*      This class implements a class called MyVector which can dynamically allocate
*      new memory and insert it within a linked list. The list can start empty.
*      
* 
* Public Methods:
*     int size;
*      static ofstream fout;
*      string fileName;
*      bool sorted;
*
*     friend ostream& operator<<(ostream&, const MyVector&);
*     friend fstream& operator<<(fstream&, const MyVector&);
*
*     MyVector();                 // default constructor
*     MyVector(int [], int);      //create a linked list array
*     MyVector(string);           //method for opening fileName
*     MyVector(const MyVector&);  //copy constructor 
* 
*     int &operator[](const int index);     //overloading [] 
*     bool operator==(const MyVector&);     //overloading == 
*     MyVector operator=(const MyVector&);  //overloading = 
*     MyVector operator+(const MyVector&);  //overloading + 
*     MyVector operator-(const MyVector&);  //overloading - 
*     MyVector operator/(const MyVector&);  //overloading / 
*     MyVector operator*(const MyVector&);  //overloading * 
*
*     int find(int);       //method for finding subscript 
*     void sortLst();      //method for sorting list smallest to largest
*     void init();         //method for quick initialization
*     void inOrdTwo(int);  //method for pushing single node 
*     void pushRear(int);  //method for pushing single node to list
*     void pushRear(const MyVector&);   //method for pushing whole list to rear
*     void pushFront(const MyVector&);  //method for pushing whole list to front   
*     void pushFront(int);     //method for pushing single node to list
*     bool pushAt(int,int);    // method for pushing node at given subscript
*     void Print();     //method for printing to console
* 
* Private Methods:
*      Node* front;  
*      Node* rear;
*      void inOrder(int);
* 
* Usage: 
*      bool pushAt(int,int);          // pushes a value to a subscript in the list
*      MyVector(const MyVector&);     // acts as the copy constructor
*      void sortLst();                //  sorts the list in numerical order
*      void init();             // simple function to initialze values
*                           // keeps from having multiple front = NULL in functions
*            
*      
*/
  struct Node
  {
    int data;
    Node* next;
    Node(int x)
    {
      data = x;
      next = NULL;
    }
  };
  
class MyVector
{
  private:
  Node* front;
  Node* rear;
  void inOrder(int);
  
  public:
  int size;
  string fileName;
  bool sorted;

  friend ostream& operator<<(ostream&, const MyVector&);
  friend fstream& operator<<(fstream&, const MyVector&);
  
  int &operator[](const int index);     //overloading [] 
  bool operator==(const MyVector&);     //overloading == 
  MyVector operator=(const MyVector&);  //overloading = 
  MyVector operator+(const MyVector&);  //overloading + 
  MyVector operator-(const MyVector&);  //overloading - 
  MyVector operator/(const MyVector&);  //overloading / 
  MyVector operator*(const MyVector&);  //overloading * 
  
  MyVector();                 // default constructor
  MyVector(int [], int);      //create a linked list array
  MyVector(const MyVector&);  //copy constructor
  MyVector(string);           //method for opening fileName

  int find(int);   //method for finding subscript 
  void init();      //method for quick initialization
  void sortLst();   //method for sorting list smallest to largest
  void Print();     //method for printing to console
  void inOrdTwo(int); //method for pushing single node 
  void pushRear(int); //method for pushing single node to list
  void pushRear(const MyVector&);   //method for pushing whole list to rear
  void pushFront(const MyVector&);  //method for pushing whole list to front
  void pushFront(int);    // method for pushing single node to front
  bool pushAt(int,int);   // method for pushing node at given subscript

};
