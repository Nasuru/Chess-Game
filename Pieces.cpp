#include <iostream>
#include <fstream>
#include <vector>
#include "Pieces.h"
#include "Board.h"
#include <string>
using namespace std;
//This gives them default values
Pieces::Pieces()
{
    PType = "";
    PColor = "";
    PRow = 0;
    PCol = 0;
}
//This assigns the pieces a specific datamember at the start as they won't have to change
Pieces::Pieces(string type, string color, int row, int col)
{
    PType = type;
    PColor = color;
    PRow = row;
    PCol = col;
}

Pieces::~Pieces()
{

}
//These return the data members so other classes can use them
string Pieces::getType()
{
    return PType;
}

void Pieces::changeColor(string color)
{
    PColor = color;
}

string Pieces::getColor()
{
    return PColor;
}

int Pieces::getRow()
{
    return PRow;
}

int Pieces::getCol()
{
    return PCol;
}
