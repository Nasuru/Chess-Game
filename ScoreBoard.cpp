#include <string>
#include <iostream>
#include <vector>
#include "ScoreBoard.h"
using namespace std;
//This initializes everything at the start
ScoreBoard::ScoreBoard()
{
    numPawn = 0;
    numBishop = 0;
    numKnight = 0;
    numRook = 0;
    numQueen = 0;
    numKing = 0;
    numPawn1 = 0;
    numBishop1 = 0;
    numKnight1 = 0;
    numRook1 = 0;
    numQueen1 = 0;
    numKing1 = 0;
}

ScoreBoard::~ScoreBoard()
{

}
//This will find all the number of pieces that player 1 has taken with a for loop through the tile board
void ScoreBoard::getNumPlayer1()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
 /*           if (tileBoard[i][j].getType == "Pawn" && tileBoard[i][j].getColor == "Black")
            {
                numPawn++;
            }
            else if (tileBoard[i][j].getType == "Bishop" && tileBoard[i][j].getColor == "Black")
            {
                numBishop++;
            }
            else if (tileBoard[i][j].getType == "Knight" && tileBoard[i][j].getColor == "Black")
            {
                numBishop++;
            }
            else if (tileBoard[i][j].getType == "Rook" && tileBoard[i][j].getColor == "Black")
            {
                numKnight++;
            }
            else if (tileBoard[i][j].getType == "Queen" && tileBoard[i][j].getColor == "Black")
            {
                numQueen++;
            }
            else if (tileBoard[i][j].getType == "King" && tileBoard[i][j].getColor == "Black")
            {
                numKing++;
            }
*/
        }
    }
}
//This will find all the number of pieces that player 2 has taken with a for loop through the tile board
void ScoreBoard::getNumPlayer2()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
     /*       if (tileBoard[i][j].getType == "Pawn" && tileBoard[i][j].getColor == "White")
            {
                numPawn1++;
            }
            else if (tileBoard[i][j].getType == "Bishop" && tileBoard[i][j].getColor == "White")
            {
                numBishop1++;
            }
            else if (tileBoard[i][j].getType == "Knight" && tileBoard[i][j].getColor == "White")
            {
                numBishop1++;
            }
            else if (tileBoard[i][j].getType == "Rook" && tileBoard[i][j].getColor == "White")
            {
                numKnight1++;
            }
            else if (tileBoard[i][j].getType == "Queen" && tileBoard[i][j].getColor == "White")
            {
                numQueen1++;
            }
            else if (tileBoard[i][j].getType == "King" && tileBoard[i][j].getColor == "White")
            {
                numKing1++;
            }*/

        }
    }
}
