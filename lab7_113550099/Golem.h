#pragma once
#include"Monster.h"
//TODO:Implement a Golem class, you can refer to Goblin class
#include <string>
class Golem : public Monster {
public:
    Golem(string name, int hp, int atk, int buff);

    void useSkill(Monster* enemy) override;
    Monster* clone() override;
};