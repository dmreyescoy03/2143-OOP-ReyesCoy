/*                  
*  Authors: David Reyes-Coy, Edgar Zapata, Thor Land, Yoseph Helal
*  Email:            theoopgamers@protonmail.com
*  Label:            BolNiverse Fight Club
*  Title:            Program 3B
*  Course:           2143-OOP
*  Semester:         Fall 2021
*  (Yoseph Hardly helped, slim to none): Nice guy though.
*/

#include <iostream>
#include "dice.hpp"
#include "fighter.hpp"
#include "json.hpp"
#include <cstdlib>
#include <unistd.h>
#include "progressbar.hpp"

using namespace std;

int main() {
  srand(time(0));
  ofstream outfile;



  progressbar bar(11);
  bar.set_todo_char(" ");
  bar.set_done_char("█");
  bar.set_opening_bracket_char("{");
  bar.set_closing_bracket_char("}");
  sleep(1);
  cout << "\n\n\n\n\n\n";
  cout << "\t\tLOADING: ";
  sleep(double(.5));
  for (int i = 0; i < 10; ++i) 
  {
    sleep(double(1));
    bar.update();
    
      // ... the program
  }
  Matchup f4;
  f4.attack();

  cout << endl;
  cout << endl;
  cout << endl;


  f4.defend();

  f4.fight();
 
  ending end;
  end.printEnding();
  f4.closeFile(outfile);
  return 0;
}