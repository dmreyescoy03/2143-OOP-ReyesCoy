/*****************************************************************************
*                    
*  Author:           David Reyes-coy
*  Email:            dmreyescoy0318@my.msutexas.edu
*  Label:            A04
*  Title:            Class: Queue
*  Course:           CMPS 2143
*  Semester:         Fall 2021
* 
*  Description:
*        This code contains a class called CircularArrayQue which builds a queue based off
*        an array. it can determine what the current size of the queue is and because
*        it keeps track of the front and rear it allows it to print "circular".
* 
*  Usage:
*        No real usage just a fun program.
* 
*  Files:            main.cpp:  |driver file|
*****************************************************************************/

#include <iostream>

using namespace std;

/**
 * Class Name: CircularArrayQue
 * 
 * Description: This class will create a linked list using a queue, keeping track
 *              of the head and rear allowing it to print out "circular". The class 
 *              includes a way to add and remove from the queue it also determines the size.
 *      
 * 
 * Public Methods:
 *      CicularArrayQue()  Return: None
 *      CircularArrayQue(int size)  Return: None
 *      Void Push(int item)    Return: None
 *      int Pop()  Return: temp
 * 
 * Private Methods:
 *      void init(int size)  Return: None
 *      bool Full() Return: Current Size
 * 
 *      Declared variables:
 *      int *Container
 *      int Front
 *      int Rear
 *      int QueSize
 *      int CurrentSize
 * 
 * Usage: 
 *    created just for example
 *      
 */

class CircularArrayQue {
private:
    int *Container;  //declaring a pointer (dynamically allocating memory)
    int Front; // declaring front (tracks front of queue)
    int Rear; // declaring rear (similar to front, tracks end of queue)
    int QueSize; // items in the queue
    int CurrentSize; // declaring CurrentSize (holds current size of queue)
    
    /**
     * Private/Protected : void init()
     * 
     * Description:
     *      declaring Front, Rear, CurrentSize to 0
     *      setting the Quesize to size
     * 
     * Params:
     *     int size-  Description: to declare size of queue
     * 
     * Returns:
     *      Does not return anything
     */

    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }
    
    /**
     * Private/Protected : bool Full()
     * 
     * Description:
     *      The purupose of this function is to determine if the 
     *      queue is full or not if it is sends error message "FULL"
     * 
     * Params:
     *      None.
     * 
     * Returns:
     *      Returns the CurrentSize which is set to the quesize
     */

    bool Full() {
        return CurrentSize == QueSize;
    }

public:
    /**
     * Public : CircularArrayQue()
     * 
     * Description:
     *      constructor: creating the array and setting it to 10
     * 
     * Params:
     *     None.
     * 
     * Returns:
     *      No return type.
     */

    CircularArrayQue() {
        Container = new int[10];
        init(10);
    }    /**
     * Public : CircularArrayQue()
     * 
     * Description:
     *      constructor:getting a new size for the que
     * 
     * Params:
     *     int size: Declaring size for array
     * 
     * Returns:
     *      No return type.
     */

    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }
        /**
     * Public : void Push()
     * 
     * Description:
     *           function that adds a number to the queue, unless it is full
     *           if container is full throws error message "FULL"
     *      
     * 
     * Params:
     *     int item: Description: Represents items in que
     * 
     * Returns:
     *      No return type.
     */


    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        } else {
            cout << "FULL!!!!" << endl;
        }
    }
        /**
     * Public : Pop()
     * 
     * Description:
     *      function pops (removes items from the list) also uses temp
     *      to point to the "front" of the que so we don't lose it
     * 
     * Params:
     *     None.
     * 
     * Returns:
     *      returns the temp
     */


    int Pop() {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }
    // not declared in private but can use private because "friend" 
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};
    /**
     * Public : &operator<<
     * 
     * Description:
     *      overloads the output operator inorder to print "cicular"
     * 
     * Params:
     *     ostream &os const CircularArrayQue, &other
     * 
     * Returns:
     *      returns os
     */

ostream &operator<<(ostream &os, const CircularArrayQue &other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main() {
    CircularArrayQue C1(5);

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1); // next 3 lines push numbers to the queue
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl; // prints out what is in the queue

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;  // prints queue again
}


