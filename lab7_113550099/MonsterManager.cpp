#include"MonsterManager.h"
MonsterManager::MonsterManager() {

}
void MonsterManager::addMonster(Monster* newMonster) {
    // TODO: Add the new monster to the monsterMap
    //       Use the monster's name as the key
    monsterMap[newMonster->getName()] =  newMonster;
}

Monster* MonsterManager::getBattleMonster(string monster_name) {
    // TODO: Look up the monster by name from the monsterMap
    //       Return a clone of the monster to be used in battle
    //       so the original monster data remains unchanged
    return monsterMap[monster_name]->clone();
}

void MonsterManager::DeleteAllMonster() {
    // TODO: Delete all monster objects stored in the monsterMap to free memory
    //       Then clear the entire map.
    for (auto& monster : monsterMap) {
        delete monster.second;
    }
    monsterMap.clear();
}

void MonsterManager::info() {
    // TODO: Print info for all of each monster(using printinfo())
    for (auto& monster : monsterMap) {
        monster.second->printinfo();
    }
}

void MonsterManager::attackTurn(Monster* Monster_one, Monster* Monster_two) {
    // TODO: Use Monster1active to check whose turn it is and attack the other monster
    if (Monster1active) {
        Monster_two->takeDamage(Monster_one->doAttack());
    }
    else {
        Monster_one->takeDamage(Monster_two->doAttack());
    }
    Monster1active = Monster1active ? 0 : 1;
}

void MonsterManager::skillTurn(Monster* Monster_one, Monster* Monster_two) {
	//TODO : Use Monster1active to check whose turn it is and use their corresponding skill
    if (Monster1active) {
        Monster_one->useSkill(Monster_two);
    }
    else {
        Monster_two->useSkill(Monster_one);
    }
    Monster1active = Monster1active ? 0 : 1;
}

void MonsterManager::showwinner(Monster* Monster_one, Monster* Monster_two) {
    // TODO: Check which monster is still alive.
	//       Print the current state of these two monsters and print the winner's name (if they are all still alive, the monster with higher hp is winner)
    Monster_one->printinfo();
    Monster_two->printinfo();
    if (Monster_one->gethp() > Monster_two->gethp()) {
        cout << "Winner: " << Monster_one->getName() << endl;
    }
    else {
        cout << "Winner: " << Monster_two->getName() << endl;
    }
}


