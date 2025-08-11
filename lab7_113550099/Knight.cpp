#include"Knight.h"
//TODO:Implement a Knight class, you can refer to Goblin class
Knight::Knight(string name, int hp, int atk, int buff)
	: Monster(name, hp, atk, buff) {}
void  Knight::useSkill(Monster* enemy) {
	//TODO : Apply different effects based on the type of monster
	int temp = atk * buff;
	enemy->takeDamage(temp);
}
Monster* Knight::clone() {
	//TODO : Return a copy of this Goblin
	Monster* G = new Knight(name, hp, atk, buff);
	return G;
}
