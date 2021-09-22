#include "MyVector.h"


/**
 * Public : MyVector
 * 
 * Description:
 *      Default constructor, initializes front, rear, size, sort 
 * 
 * 
 * Params:
 *      None:
 * 
 * Returns:
 *      nothing:
 */
MyVector::MyVector()
{
  init(); // calling init to set variables to NULL
          // size/sorted set to the int value zero
          // NULL being empty space "Zero" 
}
/**
 * Public : MyVector
 * 
 * Description:
 *      Constructor that creates the array
 * 
 * 
 * Params:
 *      int A[]:     creating array of ints
 *      int arrS:    keeps track of array size
 * 
 * Returns:
 *      nothing:
 */
MyVector::MyVector(int A[], int arrS) 
{
  init(); // calling init function

  for (int i = 0; i < size; i++)
  {
    pushRear(A[i]); // loading the array
  }
}
/**
 * Public : init
 * 
 * Description:
 *      Simple function that initializes declared variables to 0;
 *      also initializes pointers front and rear to NULL (empty space);
 * 
 * 
 * Params:
 *      None:
 * 
 * Returns:
 *      nothing:
 */
void MyVector::init()
{
  front = rear = NULL; // initializing front(head) and rear(tail) to
                       // NULL ("zero") empty space.
  fileName = ""; //declaring fileName, setting it equal to an empty string

  //declaring size and sorted, setting values to 0
  size = 0;
  sorted = 0;
}

/**
 * Private : inOrder
 * 
 * Description:
 *       Declares a new node, and allows you to insert it at a location.
 *       allows you to relink the list as well.
 * 
 * 
 * Params:
 *      int:     declaring a variable z to hold a new node value.
 * 
 * Returns:
 *      nothing:
 */
void MyVector::inOrder(int z)
{
  Node* tPtr = new Node(z); // declaring a new temp pointer, setting it equal
                           // to a new node (new value)

 // these two lines allow us to insert a new node and reconnect the list
  Node* prev = front; // previous pointer equal to front
  Node* curr = front; // current * value equal to front

  while(curr->data >  z) // loops to the location
  {
    prev = curr;
    curr = curr->next;
  }
  tPtr->next = prev->next; // re-links the linked list
  prev->next = tPtr;

  size++;
}
/**
 * Public : MyVector
 * 
 * Description:
 *      Default constructor, initializes front, rear, size, sort 
 * 
 * 
 * Params:
 *      int:
 *      int:
 * 
 * Returns:
 *      true;
 */
bool MyVector::pushAt(int x, int i) 
{
  Node* tPtr = new Node(x);
  Node* prev = front;
  Node* curr = front;

  if(i >= size)
  {
    return false;
  }
  while(i > 0)
  {
    prev = curr;
    curr = curr->next;
    i--;
  }

  tPtr->next = prev->next;
  prev->next = tPtr;

  size++;

  return true;
}

MyVector::MyVector(const MyVector& oldObj)
{
  init();
  Node* tPtr = oldObj.front;

  while(tPtr)
  {
    pushRear(tPtr->data);
    tPtr = tPtr->next;
  }
}
void MyVector::inOrdTwo(int x)
{
  if(!sorted)
  {
    sortLst();
  }

  if(!front)
  {
    pushFront(x);
  }
  else if(x < front->data)
  {
    pushFront(x);
  }
  else if(x > rear->data)
  {
    pushRear(x);
  }
  else
  {
    inOrdTwo(x);
  }
}

void MyVector::sortLst()
{
  Node* frontTwo = front;

  while(frontTwo->next)
  {
    Node* little = frontTwo;
    Node* present = frontTwo;

    int min = INF;

    while(present)
    {
      if(present->data < min)
      {
        little = present;
        min = present->data;
      }
      present = present->next;
    }
    little->data = frontTwo->data;
    frontTwo->data = min;
    frontTwo = frontTwo->next;
  }
  sorted = true;
}

void MyVector::pushFront(const MyVector & oldObj)
{
  Node* otherPtr = oldObj.front;

  int* tData = new int[oldObj.size];

  int i = 0;

  while(otherPtr)
  {
    tData[i] = otherPtr->data;
    otherPtr = otherPtr->next;
    ++i;
  }

  for(int i = oldObj.size - 1; i >= 0; i--)
  {
    pushFront(tData[i]);
  }
}
void MyVector::pushFront(int z)
{
  Node* tPtr = new Node(z);

  if(!front)
  {
    front = rear = tPtr;
  }
  else
  {
    tPtr->next = front;
    front = tPtr;
  }
  size++;
}
void MyVector::pushRear(const MyVector& oldObj)
{
  Node* opPtr = oldObj.front;

  while(opPtr)
  {
    pushRear(opPtr->data);
    opPtr = opPtr->next;
  }
}
void MyVector::pushRear(int z)
{
  Node* tPtr = new Node(z);

  if(!front)
  {
    front = rear = tPtr;
  }
  else
  {
    rear->next = tPtr;
    rear = tPtr;
  }
}
MyVector::MyVector(string fileName)
{
  init();
  ifstream fin;

  double num = 0;
  while (!fin.eof())
  {
    fin >> num;
    pushRear(num); 
  }
}

MyVector::~MyVector()
{
  Node* curr = front;
  Node* prev = front;

  while(curr)
  {
    prev = curr;
    curr = curr->next;
    delete prev;
  }
}
ostream& operator<<(ostream& oStr, const MyVector& rhs)
{
  MyVector::Node* tPtr = rhs.front;

  while(tPtr)
  {
    oStr << tPtr->data;
    if(tPtr->next)
    {
      oStr << "->";

    }
    tPtr = tPtr->next;
  }
  oStr << "\n";
  return oStr;
}
ofstream MyVector::fout;