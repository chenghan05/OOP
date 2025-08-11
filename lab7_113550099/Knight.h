#pragma once
#include"Monster.h"
//TODO:Implement a Knight class, you can refer to Goblin class#pragma once
#include <string>
class Knight : public Monster {
public:
    Knight(string name, int hp, int atk, int buff);

    void useSkill(Monster* enemy) override;
    Monster* clone() override;
};
