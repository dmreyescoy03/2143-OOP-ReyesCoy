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
  init(); // init method to set variables to 0 or NULL/nullptr

  //start of loop
  for (int i = 0; i < arrS; i++)    //allocating memory for array
  {
    pushRear(A[i]);   //pushing values to rear of array
    size++;
  }
  //end of loop
}
/**
* Public : init 
* 
* Description:
*      Simple method that initializes declared variables to 0;
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
  front = rear = nullptr;   //init points to null or empty spaces
  fileName = "";        // filename equal to empty string
  
  // setting size and sorted to 0
  size = 0; 
  sorted = 0;
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
  init();         // init method to set variables to 0 or NULL/nullptr
  ifstream fin;   //decarling ifstream infile or fin(filein)
  int num = 0;    //init num to 0
  fin.open("input.txt");  //opening input file

  //start of loop
  while (!fin.eof())    //loop that reads to end of file and flags it
  { 
    fin >> num;       //reads in from file and num holds the value
    pushRear(num);    //pushes num to rear of list
  } 
  //end of loop
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
  init();     // init method to set variables to 0 or NULL/nullptr
  Node* tPtr = oldObj.front;  //temp pointer to hold otherlist head(front)

  //start of loop
  while(tPtr)     //while temp pointer(travers list)
  {
    pushRear(tPtr->data); //pushing next node to rear of list
    tPtr = tPtr->next;    //setting temp pointer to next node
  }
}
/**
* Private : inOrder
* 
* Description:
*       Declares a new node, then loops through list comparing it to the current
*       value in the list, if less then current data place it at that subscript      *       location after z (new node) is inserted the list is then re-linked. 
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
  Node* tPtr = new Node(z);   //temp pointer for new node (x)
  Node* prev = front;         //temp pointer for prev
  Node* curr = front;         //temp pointer for curr

  //start of loop
  while(curr->data >  z)  //traversing list
  { 
    prev = curr;  //prev pointer equals curr pointer (keep list linked)
    curr = curr->next; //pushing curr to next node in list
  } 
  //end of loop

  tPtr->next = prev->next; //linking temp node(new node) to prev
  prev->next = tPtr;       //linking curr(prev) to new node

  size++;
}
/**
* Public : inOrderTwo
* 
* Description:
*       test to see if list is sorted, checks for front if not then pushes x to 
*       front. if the new value is less than front then pushFront is called, 
*       else if x is greater then rear then pushRear is called.
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
  if(!sorted) //if list is not sorted call sortLst
  {
    sortLst(); //method to sort list 
  }

  if(!front) //if front is null push new node
  {
    pushFront(x); //pushes node (x) to front of list
  }
  else if(x < front->data) //if x is larger then front 
  {
    pushFront(x); //pushes node(x) to front of the list
  }
  else if(x > rear->data) //if x is less than rear of list
  {
    pushRear(x); // push node(x) to the rear
  }
  else
  {
    inOrdTwo(x); // else insert node(x) in the list
  }
}
/**
* Public : sortLst 
* 
* Description:
*      a method that allows list to be sorted from smallest to largest.
* 
* 
* Params:
*      None:
* 
* Returns:
*      true:
*/
void MyVector::sortLst()
{
  Node* frontTwo = front; //temp pointer for 2nd front

  //start of loop
  while(frontTwo->next)
  {
    Node* little = frontTwo;    //temp pointer for little 
    Node* present = frontTwo;   //temp pointer for curr position/head

    int min = INF; //declaring min and setting equal to inf

    //start of inner loop
    while(present)
    {
      if(present->data < min) //if current data is lass then min
      {
        little = present; //pointer little pointing to front to present
        min = present->data; //min goes to next current node
      }
      present = present->next; //moving pressent or current down the list
    }
    //end of loop

    //relinking the list 
    little->data = frontTwo->data; 
    frontTwo->data = min;
    frontTwo = frontTwo->next;
  }
  //returns true for sorted
  sorted = true;
}
/**
* Public : pushAt
* 
* Description:
*      bool type method that allows user to insert a new node into the list at a
*      specific subscript location. i being the position, and x being the new value.
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
  Node* tPtr = new Node(x); //temp pointer for new node(x)
  Node* prev = front;       //prev temp pointer 
  Node* curr = front;       //curr temp pointer

  if(i >= size)
  {
    return false;
  }
  //start of loop
  while(i > 0)
  {
    prev = curr;
    curr = curr->next;
    i--;
  }
  //end of loop
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
  Node* otherPtr = oldObj.front; //temp pointer for 2nd list head(front)

  int* tData = new int[oldObj.size]; //temp pointer for 2nd list data

  int i = 0;

  //start of loop
  while(otherPtr)
  {
    tData[i] = otherPtr->data;
    otherPtr = otherPtr->next;
    ++i;
  }
  //end of loop

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
  Node* tPtr = new Node(z); //temp pointer for node(z)
  
  //if front equals nullptr
  if(!front)
  {
    front = rear = tPtr; //set front and rear to new node(z)
  }
  else
  {
    tPtr->next = front; // else link front to next node(z)
    front = tPtr;
  }
  //increment size
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
  Node* opPtr = oldObj.front; //temp pointer for 2nd list

  //start of loop
  while(opPtr)
  {
    pushRear(opPtr->data);  //pushing 2nd list to rear
    opPtr = opPtr->next;
  }
  //end of loop
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
  Node* tPtr = new Node(z);//temp pointer for new node(z) rear data

  //if front is nullptr
  if(!front)
  {
    front = rear = tPtr;  //set rear and front to new node(z)
  }
  else
  {
    rear->next = tPtr; //push new node(z) to rear (single node)
    rear = tPtr;
  }
}
/**
 * Public : Print // simple print method to print to console
 * 
 * Description:
 *      A method that prints out data to the console. call print instead of cout.
 * 
 * 
 * Params:
 *      None:
 * 
 * Returns:
 *      Nothing:
 */
void MyVector::Print() 
{
  Node* temp = front; //temp pointer for front

  //start of loop
  while (temp != nullptr) 
  {
    cout << temp->data; //printing next node (data)
    if (temp->next != nullptr) //if next node is not null print ->
    {
      cout << "->";
    }
    temp = temp->next; //moving temp to next node
  }
  cout << '\n';
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
ostream& operator<<(ostream &oStr, const MyVector &oldObj)
{
  Node* tPtr = oldObj.front; //temp pointer for 2nd list front
  oStr << "["; //print []

  //start of loop
  //loop is similar to the print method
  while(tPtr)
  {
    oStr << tPtr->data;
    if(tPtr!= nullptr)
    {
    oStr << "->";
    }
    tPtr = tPtr->next;
  }
  //end of loop
  oStr << ']';
  oStr << '\n';

  return oStr;
}
/**
* Public : operator<< // overloads the << (print to console operator)
* 
* Description:
*      A method that is similar to Print. except it overloads the << operator
*       allowing us to overwrite outfile with any word. I used magic for outfile.
* 
* 
* Params:
*      fstream&:
*      const MyVector&:
* 
* Returns:
*      returns magic; //user name for ostream
*/
fstream& operator<<(fstream& magic, const MyVector& oldObj) 
{
  Node* temp = oldObj.front; //temp pointer for 2nd list
  
  //start of loop
  //similar to print excepts prints to file
  while (temp != nullptr) 
  {
    magic << temp->data;
    if (temp->next != nullptr) 
    {
      magic << "->";
    }
    temp = temp->next;
  }
  magic << '\n';
  return magic;
}
/**
* Public : operator= // overloads the =
* 
* Description:
*      A method that allows the assignment operator (=) to be overloaded.
*      allowing the creation of a copy constructor using equal.
* 
* 
* Params:
*      const MyVector&:
* 
* Returns:
*      returns *this: //user name for ostream
*/
MyVector MyVector::operator=(const MyVector &oldObj)
{
    if(this == &oldObj)
  {
    return *this;
  }
  Node* tPtr = this->front;
  Node* prev = nullptr;
  Node* otherT = oldObj.front;
  while(tPtr != nullptr)
  {
    prev = tPtr;
    tPtr = tPtr->next;
    delete prev;
  }
  front = nullptr;
  rear = nullptr;
  size = 0;

  while(otherT != nullptr)
  {
    this->pushRear(otherT->data);
    otherT = otherT->next;
  }
   //this->front = oldObj.front;
   //this->rear = oldObj.rear;

  return *this;
}
/**
* Public : operator== // overloads the ==
* 
* Description:
*      A method that allows the assignment operator (=) to be overloaded.
*      so we can do equality comparissions such as V1==V2.
*      
* 
* 
* Params:
*      const MyVector&:
* 
* Returns:
*      returns equalList: 
*/
bool MyVector::operator==(const MyVector &oldObj)
{
  Node* tPtr = front;
  Node* oldObjPtr = oldObj.front;
  bool equalList = true;
  MyVector other = oldObj;
  while(tPtr && oldObjPtr)
  {
    if(tPtr->data != oldObjPtr->data)
    {
      equalList = false;
      break;
    }
    oldObjPtr = oldObjPtr->next;
    tPtr = tPtr->next;
  }
  if(tPtr || oldObjPtr)
  {
    equalList = false;
  }
  return equalList;
}
/**
* Public : operator+ // overloads the + operator
* 
* Description:
*      A method that allows the assignment operator (+) to be overloaded.
*      allowing the creation of a copy constructor using addition.
*      
* 
* 
* Params:
*      const MyVector&:
* 
* Returns:
*      returns tempVal:
*/
MyVector MyVector::operator+(const MyVector &oldObj)
{
  MyVector tempVal;
  Node* tPtr = front;         // get copy of the head of list
  Node* otherT = oldObj.front;  // same for other


  while(tPtr != nullptr && otherT != nullptr) 
  {  // runs if lhs is shorter
    tempVal.pushRear(tPtr->data + otherT->data);  // push the result to the end of the list
    tPtr = tPtr->next;  // walk down the list
    otherT = otherT->next;
  }
  while(tPtr != nullptr)
  {
    tempVal.pushRear(tPtr->data);
    tPtr = tPtr->next;
  }
  while(otherT != nullptr)
  {
    tempVal.pushRear(otherT->data);
    otherT = otherT->next;
  }

  return tempVal;
}
/**
* Public : operator- // overloads the - operator
* 
* Description:
*      A method that allows the assignment operator (-) to be overloaded.
*      allowing the creation of a copy constructor using subtraction.
*      
* 
* 
* Params:
*      const MyVector&:
* 
* Returns:
*      returns tempVal:
*/
MyVector MyVector::operator-(const MyVector& oldObj)
{
  MyVector tempVal;

  Node* tPtr = front;
  Node* otherT = oldObj.front;

  while(tPtr != nullptr && otherT != nullptr)
  {
    tempVal.pushRear(tPtr->data - otherT->data); 
    tPtr = tPtr->next;
    otherT = otherT->next;
  }

  while(tPtr != nullptr)
  {
    tempVal.pushRear(tPtr->data);
    tPtr = tPtr->next;
  }

  while(otherT != nullptr)
  {
    tempVal.pushRear(otherT->data);
    otherT = otherT->next;
  }
    
  return tempVal;
}
/**
* Public : operator (/) // overloads the (/) operator
* 
* Description:
*      A method that allows the assignment operator (/) to be overloaded.
*      allowing the creation of a copy constructor using division.
* 
* 
* Params:
*      const MyVector&:
* 
* Returns:
*      returns oStr; //user name for ostream
*/
MyVector MyVector::operator/(const MyVector& oldObj)
{
  MyVector tempVal;
  Node* tPtr = front;
  Node* otherT = oldObj.front;
  while(tPtr != nullptr && otherT != nullptr)
  {
    tempVal.pushRear(tPtr->data / otherT->data);
    tPtr = tPtr->next;
    otherT = otherT->next;
  }
  while(tPtr != nullptr)
  {
    tempVal.pushRear(tPtr->data);
    tPtr = tPtr->next;
  }
  while(otherT != nullptr)
  {
    tempVal.pushRear(otherT->data);
    otherT = otherT->next;
  }
  return tempVal;
}
/**
* Public : operator * // overloads the * operator
* 
* Description:
*      A method that allows the assignment operator (*) to be overloaded.
*      allowing the creation of a copy constructor using multiplication.
* 
* 
* Params:
*      const MyVector&:
* 
* Returns:
*      returns tempVal:
*/
MyVector MyVector::operator*(const MyVector& oldObj)
{
  MyVector tempVal;

  Node* tPtr = front;
  Node* otherT = oldObj.front;

  while(tPtr != nullptr && otherT != nullptr)
  {
    tempVal.pushRear(tPtr->data * otherT->data);
    tPtr = tPtr->next;
    otherT = otherT->next;
  }
  while(tPtr != nullptr)
  {
    tempVal.pushRear(tPtr->data);
    tPtr = tPtr->next;
  }
  while(otherT != nullptr)
  {
    tempVal.pushRear(otherT->data);
    otherT = otherT->next;
  }
  return tempVal;
}
/**
* Public : operator [] // overloads the [] operator
* 
* Description:
*      A method that allows the assignment operator [] to be overloaded.
*      allowing the creation of a copy constructor using [] for the array.
* 
* 
* Params:
*      const int:
* 
* Returns:
*      returns find->data:
*/
int &MyVector:: operator[](const int index)
{
  Node* find = front;
  int count = 0;
  while(count != index)
  {
    find = find -> next;
    count++;
  }
  
  return find->data;
}