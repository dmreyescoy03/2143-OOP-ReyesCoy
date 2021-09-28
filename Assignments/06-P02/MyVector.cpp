#include "MyVector.h"

MyVector::MyVector()
{
  init(); // calling init to set variables to NULL
          // size/sorted set to the int value zero
          // NULL being empty space "Zero" 
}

MyVector::MyVector(int A[], int arrS) 
{
  init();

  for (int i = 0; i < size; i++)
  {
    pushRear(A[i]);
  }
}

void MyVector::init()
{
  front = rear = NULL;
  fileName = "";
  size = 0;
  sorted = 0;
}

void MyVector::inOrder(int z)
{
  Node* tPtr = new Node(z);
  Node* prev = front;
  Node* curr = front;

  while(curr->data >  z)
  {
    prev = curr;
    curr = curr->next;
  }
  tPtr->next = prev->next;
  prev->next = tPtr;

  size++;
}

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
  fin.open("input.txt");

  int num = 0;
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
void MyVector::Print() 
{
  Node* temp = front;
  while (temp != nullptr) 
  {
    cout << temp->data;
    if (temp->next != nullptr) 
    {
      cout << "->";
    }
    temp = temp->next;
  }
  cout << '\n';
}
MyVector &MyVector::operator=(const MyVector &oldObj)
{
  if(this == &oldObj)
  {
    return *this;
  }
  Node* curr;
  Node* prev;
  curr = prev = this->front;

  while(curr)
  {
    prev = curr;
    curr = curr->next;
    delete prev;
  }
  // this->front = oldObj.front;
  // this->rear = oldObj.rear;

  return *this;
}
void MyVector::operator+(int value) 
{
  Node* tempPtr = new Node(value);

  // handles empty list
  if (front == nullptr) 
  {
    front = rear = tempPtr;
  } 
  else 
  {
    // append to rear
    rear->next = tempPtr;  // adds it to end
    rear = tempPtr;        // points tail to the new last node
  }
}
fstream& operator<<(fstream& magic, const MyVector& oldObj) 
{
  MyVector::Node* temp = oldObj.front;
  
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
MyVector MyVector::operator+=(const int value) 
{
  MyVector x(*this);

  x.pushRear(value);

  return x;
}
bool MyVector::operator==(const MyVector &rhs)
{
  Node* tPtr = front;
  Node* rhsPtr = rhs.front;
  bool equalList = true;
  MyVector other = rhs;
  while(tPtr && rhsPtr)
  {
    if(tPtr->data != rhsPtr->data)
    {
      equalList = false;
      break;
    }
    rhsPtr = rhsPtr->next;
    tPtr = tPtr->next;
  }
  if(tPtr || rhsPtr)
  {
    equalList = false;
  }
  return equalList;
  // if (this->size != other.size)
  // {
  //   return false;
  // }
  // else
  // {
  //   for (int i = 0; i < size; i++)
  //   {
  //     return (*this)[i] == other[i];
  //   }
  // }
}

// void MyVector::operator+(const MyVector &rhs)
// {
//   MyVector tempVal;
//   Node* tPtr = front;         // get copy of the head of list
//   Node* otherT = rhs.front;  // same for other

//   if (this->size < rhs.size)
//   {
//     for (int i = 0; i < this->size; i++) 
//     {  // runs if lhs is shorter
//       tempVal.pushRear(tPtr->data +otherT->data);  // push the result to the end of the list
//       otherT = otherT->next;  // walk down the list
//       tPtr = tPtr->next;
//         //newVector.size++;
//     }
//     for (int i = rhs.size - this->size; i > 0; i--) 
//     {
//       tempVal.pushRear(otherT->data);
//       otherT = otherT->next;
//     }
//   }
//   else if (this->size >= rhs.size)
//    {
//       while (otherT != nullptr) 
//       {
//         tempVal.pushRear(tPtr->data + otherT->data);
//         otherT = otherT->next;
//         tPtr = tPtr->next;
//         //newVector.size++;
//       }
//       while (tPtr != nullptr) 
//       {
//         tempVal.pushRear(tPtr->data);
//         tPtr = tPtr->next;
//         //newVector.size++;
//       }
//     }
//     // remaining nodes
//     //return tempVal;
//   }

// MyVector operator-(const MyVector& rhs)
// {
//   MyVector newList;

//   MyVector::Node* tPtr = front;
//   MyVector::Node* otherT = rhs.front;

//     MyVector newVector;
  
//     while(tPtr && otherT){
//       newList.pushRear(tPtr->data - otherT->data); 
//       tPtr = tPtr->next;
//       otherT = otherT->next;
//     }

//     while(tPtr)
//     {
//       newList.pushRear(tPtr->data);
//       tPtr = tPtr->next;
//     }

//     while(otherT){
//       newList.pushRear(otherT->data);
//       otherT = otherT->next;
//     }
    
//     return newList;                   

// }
ofstream MyVector::fout;