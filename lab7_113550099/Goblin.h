#pragma once
#include <string>
#include "Monster.h"
class Goblin : public Monster {
public:
    Goblin(string name, int hp, int atk, int buff);

    void useSkill(Monster* enemy) override;
    Monster* clone() override;
};
