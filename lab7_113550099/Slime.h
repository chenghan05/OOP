#pragma once
#include"Monster.h"
//TODO:Implement a Slime class, you can refer to Goblin class#pragma once
#include <string>
class Slime : public Monster {
public:
    Slime(string name, int hp, int atk, int buff);

    void useSkill(Monster* enemy) override;
    Monster* clone() override;
};

