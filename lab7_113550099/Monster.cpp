#include"Monster.h"
Monster::Monster(string name, int hp, int atk, int buff) {
	// TODO: Initialize monster attributes with the given parameters
	this->name = name;
	this->hp = hp;
	this->atk = atk;
	this->buff = buff;
}
int  Monster::doAttack() {
	//TODO : Return the monster's atk to attack another monster
	return atk;
}
void Monster::takeDamage(int dmg) {
	//TODO : According to another monster's atk to reduce hp
	hp -= dmg;
}
string Monster::getName() {
	//TODO : Return the name of the monster
	return name;
}
bool Monster::isAlive() {
	//TODO :check whether the monster is still alive(hp>0)
	return hp > 0;
}
void Monster::printinfo() {
	//TODO : Print the information about this monster(NAME,HP,ATK,BUFF)
	cout << "Name: " << name << ", HP: " << hp << ", Attack: " << atk << ", Buff: " << buff << endl;
}

int Monster::gethp() {
	return hp;
}