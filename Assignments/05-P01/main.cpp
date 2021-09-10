/*****************************************************************************
*                    
*  Author:           David Reyes-coy
*  Email:            dmreyescoy0318@my.msutexas.edu
*  Label:            05-P1
*  Title:            Class: Vectors
*  Course:           CMPS 2143
*  Semester:         Fall 2021
* 
*  Description:
*        -
* 
*  Usage:
*        -
* 
*  Files:            main.cpp:  |driver file|
                    
*****************************************************************************/
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
struct Node{
  int val= 0; // holds values

  Node* next; // traversing a list (links list together)
  Node* prev = NULL;

  Node(int x){ //function that adds values to the list
    val = x;
    next = NULL;
  }

};
class MyVector{
  private:
  Node* front; // start of the list
  Node* rear;
  int* A;
  int val;
  
  public:
  MyVector(){ // default constructor
  front = rear = NULL;

  }
  MyVector(int A[], int size){ //param constructor
    for(int i = 0; i < size; i++){
      size = A[1];
    }
  
  }
  MyVector(const MyVector &other){ //copy constructor
    val = other.val;
    A = new int[val];
    for(int i = 0; i < val; i++){
      A[i] = other.A[i];
    }
  }
  MyVector &operator=(const MyVector &other){ //overloading the = operator
    this->val = other.val;
    for(int i = 0; i < this->val; i++){
      this->A[i] = other.A[i];
    }
    return*this;
  }
  

  void getArr(string filename, int*& arr, int& size){
    ifstream fin; // stream reference
    filename[40];
    fin.open(filename); //opening file

    fin >> size; //gets size of the file

    arr = new int[size]; //setting the array size
    
    int i = 0; //declaring/setting i to zero 

    while(!fin.eof()){ //flags end of file
      fin >> arr[i]; //reads everything in the file
      i++; //increments 
    }

  }
  
  MyVector(const MyVector &v1){
      front = rear = NULL;
      Node *tPtr = v1.front;
      while (tPtr)
      { 
        pushRear(tPtr->val);
        tPtr = tPtr->next;
      }
  }
 void pushFront(MyVector v2)
    {
        Node *tPtr = v2.rear;

        while (tPtr)
        {
            pushRear(tPtr->val);
            tPtr = tPtr->prev;
        }
    }
    void PushAt(int loc, int val)
    {
        Node *tPtr = front;
        Node *newNode;
        newNode->val = val;

        int pos = 0; // Traverses through the list

        tPtr = front; // Initialize tempent to head;
        if (front!= NULL)
        {
            while (tPtr->next != NULL && pos != loc)
            {
                tPtr->prev = tPtr;
                tPtr = tPtr->next;
                pos++;
            }
            if (loc == 0)
            {
                pushFront(val);
            }
            else if (tPtr->next == NULL && loc == pos + 1)
            {
                pushRear(val);
            }
            else if (loc > pos + 1)
                cout << "location does not exist" << endl;
            else
            {
                tPtr->next = newNode;
                newNode->next = tPtr;
            }
        }
    }

 void pushFront(int x) {
  Node* tPtr = new Node(x);  // create a new node and
                            // add data to it

      if (!front) {
           

        front = rear = tPtr;  // `head = tempPtr` places addrress of
        

      } else {                 
        tPtr->next = front;  
        front = tPtr;        
      }
    } 
   void pushRear(MyVector v2)
    {
        Node *tPtr = v2.front;

        while (tPtr)
        {
            pushRear(tPtr->val); // print data from node
            tPtr = tPtr->next;    // move to next node
        }
    }
  void pushRear(int x){
    Node* tPtr = new Node(x);
    if(!front){
      front = rear = tPtr;
    }
    else{
      rear->next= tPtr;
      rear=tPtr;
    }


  }
      int popAt(int loc)
    {
        Node *tPtr = front;
        int remove;

        int pos = 0; // Traverses through the list

        // Initialize tempent to head;
        if (front != NULL)
        {
            while (tPtr->next != NULL && pos != loc)
            {
                tPtr->prev = tPtr;
                tPtr = tPtr->next;
                pos++;
            }
            if (loc > pos + 1)
                cout << "location does not exist\n";
            else
            {
                remove = tPtr->val;
                Node *temp2 = tPtr;
                tPtr = tPtr->prev;
                delete tPtr;
                return remove;
            }
        }
    }
    int popFront()
    {
        int pf = front->val;
        Node *tPtr = front;
        front = front->next;
        delete tPtr;
        return pf;
    }
    int popRear()
    {
        int pr = rear->val;
        Node *tPtr = rear;
        rear = rear->prev;
        delete tPtr;
        return pr;
    }
    int find(int val)
    {
        Node *tPtr = front;
        int i = 0;

        while (tPtr)
        {
            if (val == tPtr->val)
            {
                return i;
            }

            tPtr = tPtr->next;
            i++;
        }
        return -1;
    }
  void print(){
    Node* tPtr = front;

    while(tPtr){
      cout << tPtr->val << "->";
      tPtr = tPtr->next;
    }
  }

  ~MyVector(){ //deconstructor

  }

};

int main(){
int A[] = {11,25,33,47,51};
MyVector v2(A,5);
  
int x = 0;

MyVector v1;
v1.pushFront(18);
v1.pushFront(20);
v1.pushFront(25);
v1.pushRear(18);
v1.pushRear(20);
v1.pushRear(25);
v1.print();
// [25, 20, 18, 18, 20, 25]


v2.print();
// [11, 25, 33, 47, 51]

v2.pushFront(9);
//v2.inorderPush(27);
v2.pushRear(63);
v2.print();
// [9, 11, 25, 27, 33, 47, 51, 63]

v1.pushRear(v2);
v1.print();
// [25, 20, 18, 18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]

x = v1.popFront();
x = v1.popFront();
x = v1.popFront();
v1.print();
// [18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]
cout<<x<<endl;
// 18

x = v1.popRear();
x = v1.popRear();
x = v1.popRear();
v1.print();
// [18, 20, 25, 9, 11, 25, 27, 33]
cout<<x<<endl;
// 47

x = v2.popAt(3);
v2.print();
// [9, 11, 25, 33, 47, 51, 63]
cout<<x<<endl;
// 27

x = v2.find(51);
cout<<x<<endl;
// 5

x = v2.find(99);
cout<<x<<endl;
// -1

MyVector v3(v1);
v3.print();
// [18, 20, 25, 9, 11, 25, 27, 33]

v3.pushFront(v2);
v3.print();
//[9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

// MyVector v4("input.dat");
// v4.pushRear(v3);
// v4.print();
// // [56, 61, 97, 66, 83, 25, 26, 11, 53, 49, 62, 18, 10, 18, 14, 3, 4, 23, 18, 24, 26, 27, 54, 14, 12, 45, 65, 98, 56, 97, 15, 84, 98, 9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

  
  return 0;
}