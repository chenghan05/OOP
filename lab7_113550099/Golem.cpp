#include"Golem.h"
//TODO:Implement a Golem class, you can refer to Goblin class
Golem::Golem(string name, int hp, int atk, int buff)
	: Monster(name, hp, atk, buff) {}
void  Golem::useSkill(Monster* enemy) {
	//TODO : Apply different effects based on the type of monster
	takeDamage(buff);
	atk += buff;
}
Monster* Golem::clone() {
	//TODO : Return a copy of this Goblin
	Monster* G = new Golem(name, hp, atk, buff);
	return G;
}