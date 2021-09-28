#pragma once
#include <iostream>
#include <string>
#include <fstream>

#define INF 100000000
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
 *     friend ostream& operator<<(ostream&, const MyVector&);
 *     friend fstream& operator<<(fstream&, const MyVector&);
 *     MyVector(); 
 *     MyVector(int [], int);
 *     MyVector(string);
 *     MyVector(const MyVector&);
 * 
 *     friend MyVector operator-(const MyVector&);
 *     bool operator==(const MyVector&);
 *     MyVector &operator=(const MyVector&);
 *     void operator+(int);
 *     void operator+(const MyVector&);
 *     MyVector operator+=(const int);
 * 
 *     void sortLst();
 *     void init();
 *     void inOrdTwo(int);
 *     void pushRear(int);
 *     void pushRear(const MyVector&);
 *     void pushFront(const MyVector&);
 *     void pushFront(int);
 *     bool pushAt(int,int);
 *     ~MyVector();
 * 
 * 
 * Private Methods:
 *      Node* front;  
 *      Node* rear;
 *      int size;
 *      static ofstream fout;
 *      string fileName;
 *      bool sorted;
 *      void inOrder(int);
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
    int data;
    Node* next;
    Node(int x)
    {
      data = x;
      next = NULL;
    }
  };
  private:
  Node* front;
  Node* rear;
  int size;
  static ofstream fout;
  string fileName;
  bool sorted;
  void inOrder(int);
  
  public:
  friend ostream& operator<<(ostream&, const MyVector&);
  friend fstream& operator<<(fstream&, const MyVector&);
  friend MyVector operator-(const MyVector&);
  bool operator==(const MyVector&);
  MyVector &operator=(const MyVector&);
  void operator+(int);
  void operator+(const MyVector&);
  MyVector operator+=(const int);
  MyVector(); // default constructor
  MyVector(int [], int); //create a linked list array
  MyVector(const MyVector&);
  MyVector(string);

  void init();
  void sortLst();
  void Print();
  void inOrdTwo(int);
  void pushRear(int);
  void pushRear(const MyVector&);
  void pushFront(const MyVector&);
  void pushFront(int);
  bool pushAt(int,int);

  ~MyVector();
  
};
