#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/**
* Class: MyVector
* 
* Description:
*      This class implements a class called MyVector which can dynamically allocate
*      new memory and insert it within a linked list. It will push a new list to an existing
*      list. This class has methods similar to a stack.
*      
* 
* Public Methods:
*       int A[];
*       MyVector();                 // Default Constructor.
*       MyVector(int [], int);  
*       MyVector(string);           // Constructor that makes a list from an input file.
*       MyVector operator=(const MyVector &); // Copy constructor.
*       ~MyVector(); // Destructor 
*       void pushFront(int); // Push to the front of the list
*       void pushFront(const MyVector&);
*
*       void pushRear(int); // Push to the rear of the list
*       void pushRear(const MyVector&);
*
*       void pushAt(int, int);              // Push a node to a certain index
*       void pushAt(int, const MyVector&); // May not be useable
*
*       void init();
*       int popFront();
*       int popRear();
*       int popAt(int); // Remove a node at a certain index.
*       int find(int);  // Find the location of a node bbased on the chosen value.
*
*       void print(); // Print the list
*       void oPrint(ofstream&);
* 
* 
*   Private Methods:
*         Node *front;
*         Node *rear;
*         string fileName;
*       int size;
* 
* Usage: 
*      bool pushAt(int,int);          // pushes a value to a subscript in the list
*      MyVector(const MyVector&);     // acts as the copy constructor
*      void sortLst();                //  sorts the list in numerical order
*      void init();                   // simple function to initialze values
*                                     // keeps from having multiple front = NULL in functions
*            
*      
*/
class MyVector
{
  struct Node
  {
    Node *next; // Connects to the next node
    Node *prev; // Connects to the previous node
    int data;   // Information stored

    Node(int x)
    {
      data = x;
      next = NULL;
      prev = NULL;
    }
  };

  private:
  Node *front;
  Node *rear;
  string fileName;
  int size; // Keep track of how big the linked list is.


  public:
  int A[];
  // Prototypes
  MyVector();                 // Default Constructor.
  MyVector(int [], int);       // Constructor that uses an array and its size to create a list.
  MyVector(string);           // Constructor that makes a list from an input file.
  MyVector operator=(const MyVector &); // Copy constructor.
  ~MyVector(); // Destructor
  
  void pushFront(int); // Push to the front of the list
  void pushFront(const MyVector&);

  void pushRear(int); // Push to the rear of the list
  void pushRear(const MyVector&);

  void pushAt(int, int);              // Push a node to a certain index
  void pushAt(int, const MyVector&); // May not be useable

  void init();
  int popFront();
  int popRear();
  int popAt(int); // Remove a node at a certain index.
  int find(int);  // Find the location of a node bbased on the chosen value.

  void print(); // Print the list
  void oPrint(ofstream&);
};