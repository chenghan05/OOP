#include"Slime.h"
//TODO:Implement a Slime class, you can refer to Goblin class
Slime::Slime(string name, int hp, int atk, int buff)
	: Monster(name, hp, atk, buff) {}
void  Slime::useSkill(Monster* enemy) {
	//TODO : Apply different effects based on the type of monster
	hp += buff;
}
Monster* Slime::clone() {
	//TODO : Return a copy of this Goblin
	Monster* G = new Slime(name, hp, atk, buff);
	return G;
}
