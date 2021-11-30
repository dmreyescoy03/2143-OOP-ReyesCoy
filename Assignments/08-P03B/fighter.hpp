#pragma once
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include "weapon.hpp"
#include "helpers.hpp"

using namespace std;

class baseFighter {
 protected:
  string name;
  baseWeapon* weapon;

  // this is the health
  int basehealth;

 public:
  baseFighter() {
    name = "";
    basehealth = 5;
    weapon = new baseWeapon;
  }

  baseFighter(string n) {
    name = n;
    weapon = new baseWeapon;
    basehealth = 5;
  }

  virtual double attack() { return weapon->use(); }

  // this is where the fighter take damaged
  void takedamaged(int x) { basehealth -= x; }

  /// this is to make sure the fighters are alive
  bool alive() { return basehealth > 0; }

  friend ostream& operator<<(ostream& os, const baseFighter& f) {
    return os << "(" << f.name << " , " << *f.weapon << ")";
  }
};

class Warrior : public baseFighter {
 public:
  Warrior() {
    name = "Warrior";
    weapon = new Sword();
  }

  //  Warrior health
  double health() {
    double health = basehealth;
    health = rand() % 5 + 20;
    return health;
  }

  // this just the base weapon
  double attack() { return weapon->use(); }
};

// wizard character
class Wizard : public baseFighter {
 public:
  Wizard() {
    name = "Wizard";
    weapon = new staff();
  }

  double health() {
    double health = basehealth;
    health = rand() % 5 + 10;
    return health;
  }

  double attack() { return weapon->use(); }
};

// archer   character
class Archer : public baseFighter {
 public:
  Archer() {
    name = "Archer";
    weapon = new bow();
  }

  double health() {
    double health = basehealth;
    health = rand() % 5 + 15;
    return health;
  }

  double attack() { return weapon->use(); }
};

// dragonBorn  character
class DragonBorn : public baseFighter {
 public:
  DragonBorn() {
    name = "DragonBorn";
    weapon = new Dragontooth();
  }

  double health() {
    double health = basehealth;
    health = rand() % 5 + 25;
    return health;
  }

  double attack() { return weapon->use(); }
};

class Elf : public baseFighter {
 public:
  Elf() {
    name = "Elf";
    weapon = new rainbow();
  }

  double health() {
    double health = basehealth;
    health = rand() % 5 + 15;
    return health;
  }

  double attack() { return weapon->use(); }
};

class Matchup {
  protected:
   vector<baseFighter*> attackers;
   vector<baseFighter*> defenders;
   vector<baseFighter*> death_bed;

  public:
   Matchup() {
     // attacker.
     // populate attackers and defenders
 }
   // this is where the attackers are loaded up
   void attack() {
     vector<string> choices = {"warrior", "elf", "wizard", "dragonBorn", "archer"};
     
     string rchoice;
     for (int i = 0; i < 20; i++) {
       rchoice = choices[rand() % choices.size()];

       if (rchoice == "warrior") {
         attackers.push_back(new Warrior());
       } else if (rchoice == "wizard") {
        attackers.push_back(new Wizard());
       } else if (rchoice == "elf") {
         attackers.push_back(new Elf());
       } else if (rchoice == "dragonBorn") {
         attackers.push_back(new DragonBorn());
       } else if (rchoice == "archer") {
         attackers.push_back(new Archer());
       }
     }
   }

  // this is where the defenders load up
   void defend() {
     vector<string> choices = 
     {"warrior", "elf", "wizard", "dragonBorn", "archer"};

     string rchoice;
     for (int i = 0; i < 20; i++) {
       rchoice = choices[rand() % choices.size()];

       if (rchoice == "warrior") {
         defenders.push_back(new Warrior());
       } else if (rchoice == "wizard") {
         defenders.push_back(new Wizard());
       } else if (rchoice == "elf") {
         defenders.push_back(new Elf());
       } else if (rchoice == "dragonBorn") {
         defenders.push_back(new DragonBorn());
       } else if (rchoice == "archer") {
         defenders.push_back(new Archer());
       }
     }
   }

   void death() {    
     cout << "size of the deaths " << death_bed.size() << endl; 
   }

   //writing results to the outfile
   void getFile(ofstream& outfile)
   {
     string ofile = "";
     cout << "Where do you want to save your score? ";
     cin >> ofile;

     outfile.open(ofile);
   }

   //nifty little closing
   void closeFile(ofstream& outfile){
    outfile.close();
   }

  // this is were they fight
  void fight() {
    ofstream outfile;
    int count_attackers = 0;
    int count_def = 0;
    int i = 0;



    baseFighter* Firstattackers;
    baseFighter* Firstdefenders;
    // Game loop
    
    while (attackers.size() && defenders.size()) {
      // the first ppl to attack
      Firstattackers = attackers.back();
      Firstdefenders = defenders.back();

      // while loop to make the game start
      while (Firstattackers->alive() && Firstdefenders->alive()) {
        this_thread::sleep_for(chrono::milliseconds(100));
        system("clear");

        cout << "Attackers: " << attackers.size() << " vs " << "Defenders: " << defenders.size() << endl;
        Firstdefenders->takedamaged(Firstattackers->attack());
        Firstattackers->takedamaged(Firstdefenders->attack());
        
        
      }
      if (!attackers.back()->alive()) {

        attackers.pop_back();
        death_bed.push_back(Firstattackers);
        count_attackers++;
      }
      if (!defenders.back()->alive()) {

        defenders.pop_back();
        death_bed.push_back(Firstdefenders);
        count_def++;
      }

    }
    getFile(outfile);
    outfile << "Number of Attackers: " << attackers.size() << '\n';
    cout << "Attackers size: " << attackers.size() << endl;

    outfile << "Number of Defenders: " << defenders.size() << '\n';
    cout << "Defenders size:  " << defenders.size() << endl;
    
    outfile << "The Death Pool: " << death_bed.size() << '\n';
    cout << "The Death pool: "  <<  death_bed.size() << endl;

    cout << " --Number of dead attacker: " << count_attackers << endl;
    cout << " --Number of dead defenders: " << count_def << endl;
    outfile << " --Number of dead attacker: " << count_attackers << '\n';
    outfile << " --Number of dead defenders: " << count_def << '\n';
  }
};