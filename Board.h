#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include "Pieces.h"
#include <string>
using namespace std;

class Board
{
public:
    Board(); // This constructor just puts all the pieces into an array
    ~Board();

    void startGame(); // This will be put into the first constructor to start the game
    void resumeGame();
    void saveGame();
    int PLocation(string);
    int PLocation2(string);
    void currentTurn1();
    void currentTurn2();
    void ParseSave(string, string[]);
    void Pawn(); // These are the functions for the specific pieces, they will have their specific move set and attributes
    void Bishop();
    void Knight();
    void Rook();
    void Queen();
    void King();

public:
    vector<vector<Pieces>> tileBoard; // This will be the array holding all the pieces and another row and column for the letters on the side of the array
    bool Checkmate; //This will make sure the game saves until someone wins with checkmate true
    bool running; //This keeps the game running
    string player1; //These are the players names
    string player2;
    bool player_one;
    int ro, co;
};

#endif // BOARD_H
