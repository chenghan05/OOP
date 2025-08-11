#ifndef __GOMOKU_H__
#define __GOMOKU_H__

// You can use SIZE to avoid magic number.
#define SIZE 11

#include <string>
#include <queue>

using namespace std;

struct Position {
    int x, y;

    Position(int _x, int _y): x(_x), y(_y) {}
};

enum Grid {
    EMPTY, PLAYERA, PLAYERB
};

enum Status {
    PLAYING, DRAW, PLAYERAWIN, PLAYERBWIN
};

class Gomoku {
    private:
        Grid m_board[SIZE][SIZE];
        queue<Position> m_Queue;
        Status gameStatus;

    public:
        Gomoku();
        void OpenFile(string filename);
        void Play();
        void Place(Position position, Grid grid);
        Status GetGameStatus();
        void PrintBoard();
        void PrintWinner();
};


#endif
