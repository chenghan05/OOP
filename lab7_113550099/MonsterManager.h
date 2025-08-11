#pragma once
#include <string>
#include<map>
#include "Monster.h"
using namespace std;
class MonsterManager {
protected:
    map<string, Monster*> monsterMap; // record all of the monster
    
public:
    MonsterManager();
    bool Monster1active = true; // the turn which monster can attack or use skill
    
    Monster* getBattleMonster(string monster_name);

    void addMonster(Monster* newMonster);
    void showwinner(Monster* Monster_one, Monster* Monster_two);
    void attackTurn(Monster* Monster_one, Monster* Monster_two);
    void skillTurn(Monster* Monster_one, Monster* Monster_two);
    void DeleteAllMonster();
    void info();
};