#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "Monster.h"
#include"Goblin.h"
#include"Golem.h"
#include"Knight.h"
#include"Slime.h"
#include"MonsterManager.h"
#include "Tools.h"
using namespace std;

int main() {
    vector<string> inputPath, outputPath;
    if (configure(inputPath, outputPath, "./configure.txt") != 0) {
        cerr << "Configure failed.\n";
        return -1;
    }
    MonsterManager* mg = new MonsterManager();
    int fileIndex;
    cout << "Input Index: ";
    while (cin >> fileIndex) {
        if (fileIndex <= 0 || fileIndex > inputPath.size()) {
            cout << "Invalid index.\n";
            continue;
        }
        ifstream data(inputPath[fileIndex - 1]);
     

        if (!data) {
            cerr << "File open failed.\n";
            continue;
        }

        
        string command;


        while (data >> command && command != "battle_count") {
            if (command == "monster") {
                string name;
                int hp, atk,buff;
                data >> name >> hp >> atk>>buff;

                Monster* m = nullptr;

                if (name == "Goblin")
                    m = new Goblin(name, hp, atk, buff);
                else if (name == "Slime")
                    m = new Slime(name, hp, atk, buff);
                else if (name == "Knight")
                    m = new Knight(name, hp, atk, buff);
                else if (name == "Golem")
                    m = new Golem(name, hp, atk, buff);
                else
                    m = new Monster(name, hp, atk, buff);  
                if (m) {
                    mg->addMonster(m);
                }
            }
        }
        mg->info();
        cout << endl;
        cout << "========Start Battle========" << endl;

        int battleCount = 0;
        data >> battleCount;
        for (int i = 0; i < battleCount; ++i) {
            string m1, m2;
            data >> m1 >> m2;

            Monster* battlemonster1=mg->getBattleMonster(m1);
            Monster* battlemonster2=mg->getBattleMonster(m2);
            cout << "Round " << i + 1 << " : "<<battlemonster1->getName() <<" vs " <<battlemonster2->getName() << endl;
            int actionCount;
            data >> actionCount;
            mg->Monster1active = true;
            for (int j = 0; j < actionCount; ++j) {
                string action;
                data >> action;
                if (action == "a")
                    mg->attackTurn(battlemonster1, battlemonster2);
                else if (action == "s")
                    mg->skillTurn(battlemonster1, battlemonster2);


            }
            cout << "Result : " << endl;
            mg->showwinner(battlemonster1,battlemonster2);
            cout << "Battle End\n\n";
            delete battlemonster1;
            delete battlemonster2;
        }
//        mg->DeleteAllMonster();
        data.close();
        


        cout << "Input Index: ";
    }

    return 0;
}
