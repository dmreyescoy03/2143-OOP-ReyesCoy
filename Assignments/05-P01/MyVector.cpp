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

  for (int i = 0; i < arrS; i++)
  {
    pushRear(A[i]); // loading the array
  }
}
/**
 * Public : MyVector // copy constructor
 * 
 * Description:
 *       Declares a new node, and allows user to insert it at a location.
 *       allows you to relink the list as well.
 * 
 * 
 * Params:
 *      const MyVector&
 * 
 * Returns:
 *      nothing:
 */
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
/**
 * Public : MyVector // reads from file
 * 
 * Description:
 *      method reads until end of file(eof). num holds the current value read in 
 *      then pushRear is called, and that value is added to the end of the list.
 * 
 * 
 * Params:
 *      String: // for file name
 * 
 * Returns:
 *      nothing:
 */
MyVector::MyVector(string fileName)
{
  init();
  ifstream fin;
  fin.open(fileName);

  int num = 0;
  while (!fin.eof())
  {
    fin >> num;
    pushRear(num); 
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
 *       Declares a new node, then loops through list comparing it to the current
 *       value in the list, if less then current data place it at that subscript location
 *       after z (new node) is inserted the list is then re-linked. 
 * 
 * 
 * Params:
 *      int: 
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
  Node* curr = front; // current pionter value equal to front

  while(curr->data >  z) // loops through list, compares current value
                         // to z (new node) if curr is larger then it places z behind it
  {
    prev = curr;
    curr = curr->next;
  }
  tPtr->next = prev->next; // re-links the linked list
  prev->next = tPtr;

  size++;
}
/**
 * Public : inOrderTwo
 * 
 * Description:
 *       test to see if list is sorted, checks for front if not then pushes x to front.
 *       if the new value is less than front then pushFront is called, else if 
 *       x is greater then rear then pushRear is called.
 * 
 * 
 * Params:
 *      int:
 * 
 * Returns:
 *      nothing:
 */
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
/**
 * Public : sortLst
 * 
 * Description:
 *      method that declares a temp pointer that points to front. frontTwo pointer
 *      keeps track of front as we travers the list, comparing new values to front.
 *      if present data is smaller then min, then little (pointer) holds that value
 *      as present gets the next value. continues until list is sorted.
 * 
 * 
 * Params:
 *      None:
 * Returns:
 *      nothing:
 */
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
/**
 * Public : pushAt
 * 
 * Description:
 *      bool type method that allows user to insert a new node into the list at a specific
 *      subscript location. i being the position, and x being the new value.
 *      if the subscript value it goes out of range then it return false (does not)
 *      update the list. (0 is put in place of the out value). 
 * 
 * 
 * Params:
 *      int:
 *      int:
 * 
 * Returns:
 *      returns true;
 */
bool MyVector::pushAt(int i, int x) 
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
/**
 * Public : pushFront //pushes new vector to front of list
 * 
 * Description:
 *      A method that pushes another list to the front of a current list.
 * 
 * 
 * Params:
 *      const MyVector&:
 * 
 * Returns:
 *      Nothing:
 */
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
/**
 * Public : pushFront //pushes a new value to list
 * 
 * Description:
 *      a temporary pointer is created and set equal to a new node. if list is empty
 *      then rear and front are set equal to the temp pointer. else the temp pointer
 *      gets added to the list and points front. size is then incremented. 
 * 
 * 
 * Params:
 *      int:
 * 
 * Returns:
 *      Nothing;
 */
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
/**
 * Public : pushRear //another method similar to pushFront
 * 
 * Description:
 *      pushes data from another list to the current list that was first created.
 *      uses a temporary pointer to point to head of old list then traverses the list
 *      adding the next value to the rear.
 * 
 * 
 * Params:
 *      const MyVector&
 * 
 * Returns:
 *      Nothing;
 */
void MyVector::pushRear(const MyVector& oldObj)
{
  Node* opPtr = oldObj.front;

  while(opPtr)
  {
    pushRear(opPtr->data);
    opPtr = opPtr->next;
  }
}
/**
 * Public : pushRear // similar to pushFront(int);
 * 
 * Description:
 *     A method that allows a new node to be pushed to the end of the list. declares
 *     a temp pointer that points to a new Node. if list is empty front and rear are
 *     set to point to it. else the temp pointer is added to the rear of the list.
 * 
 * 
 * Params:
 *      int:
 * 
 * Returns:
 *      Nothing;
 */
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
/**
 * Public : operator<< // overloads the << (print to console operator)
 * 
 * Description:
 *      A method that is similar to Print. except it overloads the << operator
 *      allowing multiple things to be printed.
 * 
 * 
 * Params:
 *      ostream&:
 *      const MyVector&:
 * 
 * Returns:
 *      returns oStr; //user name for ostream
 */
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
/**
 * Public : ~MyVector // destructor one of 3 constructors in a class
 * 
 * Description:
 *      a method that deallocates memory, and cleans up the class. 
 * 
 * 
 * Params:
 *      None:
 * 
 * Returns:
 *      Nothing;
 */
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
// creates an outfile with a filename chosen by the user
//takes the output envoirment path and passes that to the object of output stream.
ofstream MyVector::fout;
