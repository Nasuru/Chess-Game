#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <iostream>
#include <string>
#include <vector>
#include "Board.h"
using namespace std;

class ScoreBoard
{
public:
    ScoreBoard();
    ~ScoreBoard();

    void getNumPlayer1();
    void getNumPlayer2();

public:
    string name; // This is for the input of the players' names
    int numPawn; // The next data members will get from the board class and keep track of all the pieces on the board and display them for player 1
    int numBishop;
    int numKnight;
    int numRook;
    int numQueen;
    int numKing;
    int numPawn1; // The next data members will get from the board class and keep track of all the pieces on the board and display them for player 2
    int numBishop1;
    int numKnight1;
    int numRook1;
    int numQueen1;
    int numKing1;
    Board game1; //This is meant to get the tileboard from the board class
   // game1.tileBoard[8][8];

};

#endif // SCOREBOARD_H
