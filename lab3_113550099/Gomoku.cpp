#include "Gomoku.h"

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

Gomoku::Gomoku() {
    // TODO: Initialize the game board by setting all positions to EMPTY.
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++){
            m_board[i][j] = EMPTY;
        }
    }
    gameStatus = PLAYING;
}

void Gomoku::OpenFile(string filename) {
    // TODO: Read moves from the input file and store them in the queue.
    //       Each move should contain an (x, y) position.
    ifstream input;
    input.open(filename);
    int x, y;
    for (int i = 0; i < 80; i++) {
        input >> x >> y;
        m_Queue.push(Position(x, y));
    }
}

void Gomoku::Play() {
    // TODO: Retrieve moves from the queue and place pieces on the board.
    //       Player A always moves first, followed by Player B.
    int moves = 0;//A is 1 and B is 0
    while (gameStatus == PLAYING && !m_Queue.empty()) {
        if (moves%2==0) {
            Place(m_Queue.front(), PLAYERA);
        }
        else {
            Place(m_Queue.front(), PLAYERB);
        }
        m_Queue.pop();
        moves += 1;
        gameStatus = GetGameStatus();
    }
    PrintWinner();
    PrintBoard();
}

void Gomoku::Place(Position position, Grid grid) {
    // TODO: Place a piece on the board at the specified position.
    m_board[position.x-1][position.y-1] = grid;
}

Status Gomoku::GetGameStatus() {
    // TODO: Check if Player A or Player B has won the game.
    //       Look for a winning condition in rows, columns, and diagonals.
    //       If both players have completed 40 moves each without a winner, output “DRAW.”
    //       Otherwise, return PLAYING.
    int moves = 0;
    int inarow = 1;
    int dx[8] = { 0,1,0,-1,1,1,-1,-1 };
    int dy[8] = { 1,0,-1,0,1,-1,-1,1 };
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (m_board[i][j] != EMPTY) {
                moves++;
                int x = i;
                int y = j;
                for (int k = 0; k < 8; k++) {
                    inarow = 1;
                    while (x + dx[k] >= 0 && x + dx[k] < SIZE && y + dy[k] >= 0 && y + dy[k] < SIZE
                        && m_board[i][j] == m_board[x + dx[k]][y + dy[k]]) {
                        inarow++;
                        x += dx[k];
                        y += dy[k];
                        if (inarow >= 5) {
                            return m_board[i][j] == PLAYERA ? PLAYERAWIN : PLAYERBWIN;
                        }
                    }
                }
            }
        }
    }
    if (moves >= 80) return DRAW ;
    return PLAYING;
}

void Gomoku::PrintBoard() {
    // TODO: Print the board.
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            switch(m_board[i][j]){
            case EMPTY:
                cout << "# ";
                break;
            case PLAYERA:
                cout << "O ";
                break;
            case PLAYERB:
                cout << "X ";
                break;
            }
        }
        cout << "\n";
    }
}

void Gomoku::PrintWinner() {
    // TODO: Determine the winner by calling GetGameStatus().
    //       Print "PLAYER A WINS!", "PLAYER B WINS!", or "DRAW!" accordingly.
    switch (gameStatus) {
    case DRAW:
        cout << "DRAW!\n";
        break;
    case PLAYERAWIN:
        cout << "PLAYER A WINS!\n";
        break;
    case PLAYERBWIN:
        cout << "PLAYER B WINS!\n";
        break;
    default:
        cout << "Playing!!!\n";
        break;
    }
}
