#include"Goblin.h"
Goblin::Goblin(string name, int hp, int atk, int buff)
	: Monster(name, hp, atk,buff) {}
void  Goblin::useSkill(Monster* enemy) {
	//TODO : Apply different effects based on the type of monster
	for (int i = 0; i < buff; i++) {
		enemy->takeDamage(atk);
	}
}
Monster* Goblin::clone() {
	//TODO : Return a copy of this Goblin
	Monster* G = new Goblin(name, hp, atk, buff);
	return G;
}