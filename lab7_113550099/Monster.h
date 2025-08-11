#pragma once
#include <string>
#include <iostream>
#include<map>
using namespace std;
class Monster {
protected:
    string name;
    int hp;
    int atk;
    int buff;
public:
    Monster(string name, int hp, int atk, int buff);
  
    virtual ~Monster() {}

    int doAttack();
    
    int gethp();
    string getName();
    bool isAlive();
    void printinfo();
    void takeDamage(int dmg);

    virtual void useSkill(Monster* enemy){};
    virtual Monster* clone(){return nullptr;};
   
};