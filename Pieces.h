#ifndef PIECES_H
#define PIECES_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Pieces
{
public:
    Pieces();
    Pieces(string, string, int, int); //The pieces will  be instantiated with a type, color, row, and col for ease
    ~Pieces();

    string getType(); //These get the data members
    void changeColor(string);
    string getColor();
    int getRow();
    int getCol();

public:
    string PColor;
    string PType;
    int PRow;
    int PCol;
};

#endif // PIECES_H
