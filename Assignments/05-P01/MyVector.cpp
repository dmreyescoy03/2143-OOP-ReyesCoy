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
{ // default constructor
  init();
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
MyVector::MyVector(int A[], int arrS) //param constructor
{
  init();

  for (int i = 0; i < arrS; i++)
  {
    pushRear(A[i]);
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
  while (!fin.eof())
  {
    fin >> size; 
    pushRear(size);
    this->size++;
  }
}
/**
 * Public : MyVector
 * 
 * Description:
 *       Overloads the = operator. Array[] size gets set to the
 *       size of V1.size 
 * 
 * 
 * Params:
 *      const MyVector&
 * 
 * Returns:
 *      this:
 */
MyVector MyVector::operator=(const MyVector& V1)
{ //overloading the = operator
  this->size = V1.size;
  for (int i = 0; i < this->size; i++)
  {
    this->A[i] = V1.A[i];
  }
  return *this;
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
  front = rear = nullptr; // initializing front(head) and rear(tail) to
                       // NULL ("zero") empty space.
  fileName = ""; //declaring fileName, setting it equal to an empty string

  //declaring size and sorted, setting sizes to 0
  size = 0;
}
/**
 * Public : pushFront 
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
void MyVector::pushFront(const MyVector& V2)
{
  Node *tPtr = V2.front;
  while (tPtr != nullptr)
  {
    pushFront(tPtr->data);
    tPtr = tPtr->next;    
  }
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
void MyVector::pushAt(int loc, int x)
{
  if(loc == 0)
	{
	 pushFront(x);
	}
	else
	{
		if(loc < size)
		{
			Node* tPtr = front;
			for(int i = 0; i < loc; i++)
			{
			 tPtr->prev = tPtr;
			 tPtr = tPtr->next;
			}
			tPtr->prev->next = new Node(x);
			tPtr->prev->next->next = tPtr->next;
    }
		else
		{
			pushRear(x);
		}
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
void MyVector::pushFront(int num)
{
  if (front == nullptr)                           //head is empty
  {
    front = new Node(num);                          // add new node to list
    rear = front;                                 // set head and tail equal
    size++;                                        //update size
  }
  else
  {
    Node *tPtr = front;                             // nodeptr to head
    front = new Node(num);                          // set new value to head

    front->next = tPtr;
    tPtr->prev = rear;

    size++;
  }
}
/**
 * Public : pushRear 
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
void MyVector::pushRear(const MyVector& V2)
{
  Node *tPtr = V2.front;
  while (tPtr)
  {
    pushRear(tPtr->data); // print data from node
    tPtr = tPtr->next;   // move to next node
  }
}
/**
 * Public : pushRear 
 * 
 * Description:
 *      Creates a temp pointer that points to a new node. If list is empty
 *      set head and rear to new node. If not empty rear is set to the new 
 *      node being created.
 * 
 * 
 * Params:
 *      int x;
 * 
 * Returns:
 *      Nothing;
 */
void MyVector::pushRear(int x)
{
  Node *tPtr = new Node(x);
  if (!front)
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
 * Public : popAt 
 * 
 * Description:
 *      declares a temp pointer to keep track of front. checks for nullptr and loc
 *      if loc doesn't exist then error. Searches for value and returns the
 *      subscript value.
 * 
 * 
 * Params:
 *      int loc;
 * 
 * Returns:
 *      returns size;
 */
int MyVector::popAt(int loc)
{
  Node *tPtr = front; 
  int remove;
	int size =  0;
  int pos = 0; 

  if (front != nullptr)
  {
    while (tPtr->next != nullptr && pos != loc)
    {
      tPtr->prev = tPtr;
      tPtr = tPtr->next;
      pos++;
    }
    if (loc > pos+1)
    cout << "location does not exist\n";
    else
    {
      remove = tPtr->data;
      tPtr = tPtr->prev;
      delete tPtr;
      return remove;
    }
  }
  return size;
}
/**
 * Public : popFront 
 * 
 * Description:
 *      checks head for nullptr if null then error. if not empty
 *      int is set to the head of list creates temp pointer to
 *      point to the next value in list. then deletes int(old head)
 * 
 * 
 * Params:
 *      None;
 * 
 * Returns:
 *      return 0;
 */
int MyVector::popFront()
{
  if(front == nullptr)
  {
    cout <<"Can't pop from an empty list\n";
  }
  else
  {
    int pf = front->data;
    Node *tPtr = front;
    front = front->next;
    delete tPtr;
    size--;
    return pf;
  }
  return 0;
}
/**
 * Public : popRear
 * 
 * Description:
 *      checks rear for nullptr if null then error. if not empty
 *      int is set to the rear of list creates temp pointer to
 *      point to the next value in list. then deletes int(old head)
 * 
 * 
 * Params:
 *      None;
 * 
 * Returns:
 *      return 0;
 */
int MyVector::popRear()
{
  if(rear == nullptr)
  {
    cout << "empty";
  }
  else
  {
    int pr = rear->data;
    Node *tPtr = front;
    while(tPtr->next != rear)
    {
      tPtr = tPtr->next;
    }
    rear = tPtr;
    rear->next = nullptr;
    size--;
    return pr;
  }
  return 0;
}
/**
 * Public : find 
 * 
 * Description:
 *      if head is not found return nothing. else create a int value
 *      and temp pointer to point to front. Traverse the list finding 
 *      desired value. if value is not found return -1
 * 
 * 
 * Params:
 *      None;
 * 
 * Returns:
 *      return 0;
 */
int MyVector::find(int val)
{
  if(!front)
  {
    return 0;
  }
  if (front->data == val)
  {
    return 0;
  }
  else
  {
    int num = 0;
    Node *tPtr = front;
    while (tPtr != nullptr && tPtr->data != val)
    {
      tPtr = tPtr->next;
      num++;
    }
    if(!tPtr)
    {
      return -1;
    }
    return num;
  }
  return 0;
}
/**
 * Public : Print
 * 
 * Description:
 *      A method that prints []-> to the screen. Print each value of the list
 * 
 * 
 * Params:
 *      None;
 * 
 * Returns:
 *      nothing;
 */
void MyVector::print()
{
  cout << "[";
  Node *tPtr = front;
  while (tPtr)
  {
    cout << tPtr->data << "->";
    tPtr = tPtr->next;
  }
  cout << "] ";
  cout << '\n';
}
/**
 * Public : oPrint
 * 
 * Description:
 *      A method that is similar to Print. Instead of printing to
 *      the screen it goes to an outfile;
 * 
 * 
 * Params:
 *      ostream&:
 * 
 * Returns:
 *      nothing;
 */
void MyVector::oPrint(ofstream& banana)
{
  banana << "[ ";
  Node *tPtr = front;
  while (tPtr)
  {
    banana << tPtr->data << "->";
    tPtr = tPtr->next;
  }
  banana << "] ";
  banana << '\n';
  
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
{ //deconstructor
}
