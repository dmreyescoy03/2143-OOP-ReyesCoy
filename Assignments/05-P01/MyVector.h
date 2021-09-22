#pragma once
#include <iostream>
#include <string>
#include <fstream>

#define INF 100000000
using namespace std;

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
  
  void init();

  MyVector(); // default constructor
  MyVector(int [], int); //create a linked list array
  MyVector(const MyVector&);
  MyVector(string);

  void sortLst();

  void inOrdTwo(int);
  void pushRear(int);
  void pushRear(const MyVector&);
  void pushFront(const MyVector&);
  void pushFront(int);
  bool pushAt(int,int);

  ~MyVector();
  
};
