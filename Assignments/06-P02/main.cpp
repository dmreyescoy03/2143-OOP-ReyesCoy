#include <iostream>
#include <fstream>
#include <vector>
#include "MyVector.h"

using namespace std;


#include <iostream>
#include <fstream>
#include <vector>
#include "MyVector.h"

using namespace std;


int main() 
{ 
  ofstream magic;
  magic.open("thisfile.txt");
  int a1[] = { 1, 2, 3, 4, 5 };
  int a2[] = { 10, 20, 30 };

  MyVector V1(a1,5);
  MyVector V2(a2,3);
  cout << V1[2] << endl;
// writes out 3

  V1[4] = 9;
// V1 now = [1,2,3,4,9]

  cout << V1 << endl;
// writes out [1,2,3,4,9] to console.

  magic << V1 << endl;
// writes out [1,2,3,4,9] to your output file.

  MyVector V3 = V1 + V2;
cout << V3 << endl;
// writes out [11,22,33,4,9] to console.

  V3 = V1 - V2;
  cout << V3 << endl;
// writes out [-9,-18,-27,4,9] to console.

  V3 = V2 - V1;
  cout << V3 << endl;
// writes out [9,18,27,4,9] to console.

  V3 = V2 * V1;
  cout << V3 << endl;
// writes out [10,40,90,4,9] to console.

  V3 = V1 * V2;
  cout << V3 << endl;
// writes out [10,40,90,4,9] to console.

  V3 = V1 / V2;
  cout << V3 << endl;
// writes out [0,0,0,4,9] to console.

  V3 = V2 / V1;
  cout << V3 << endl;
// writes out [10,10,10,4,9] to console.

  cout << (V2 == V1) << endl;
// writes 0 to console (false) .

  MyVector V4 = V1;
  cout << (V4 == V1) << endl;
// writes 1 to console (true) .

  return 0;
}