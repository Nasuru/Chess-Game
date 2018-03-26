#include <iostream>
#include <fstream>
#include <vector>
#include "Board.h"
#include <unistd.h>
#include <string>
using namespace std;

void startGame();
void resumeGame();
void currentTurn();
void Pawn();
void Bishop();
void Knight();
void Rook();
void Queen();
void King();
//This constructor opens a file and checks if the savefile has anything in it
// if it does than it prompts the user if they want to continue and calls the resume game function, if not then the two players enter their names
// Then it calls the startgame function
Board::Board()
{
    tileBoard.resize(8, vector<Pieces>(8));
    ifstream myFile;
    myFile.open("SaveFile.cpp");
    string l;
    while(getline(myFile, l))
    {
        char A;
        string B;
        string C;
        if (l == "")
        {
            cout << "Player 1, Choose Your Name: ";
            getline(cin, B);
            player1 = string(B);
            cin.get();
            cout << "Player 2, Choose Your Name: ";
            getline(cin, C);
            player2 = string(C);
            cin.get();
            myFile.close();
            startGame();
        }
        else
        {
            myFile.close();
            cout << "Would you like to continue your last game? Y or N?" << endl;
            cin >> A;
            cin.get();

            if (A == 'Y'|| A == 'y')
            {
                resumeGame();
            }
            else if (A == 'N'|| A == 'n')
            {
                cout << "Player 1, Choose Your Name: ";
                getline(cin, B);
                player1 = string(B);
                cin.get();
                cout << "Player 2, Choose Your Name: ";
                getline(cin, C);
                player2 = string(C);
                cin.get();
                startGame();
            }
            else
            {
                while (A != 'Y'& A != 'N'&& A != 'y' && A != 'n')
                {
                    cout << "That wasn't a valid response. Y or N?" << endl;
                    cin >> A;
                    if (A == 'Y'||A == 'y')
                    {
                        resumeGame();
                    }
                    else if (A == 'N'||A == 'n')
                    {
                        cout << "Player 1, Choose Your Name: ";
                        getline(cin, B);
                        player1 = string(B);
                        cin.get();
                        cout << "Player 2, Choose Your Name: ";
                        getline(cin, C);
                        player2 = string(C);
                        cin.get();
                        startGame();
                    }
                }
            }
        }
    }
    Checkmate = false;
}

Board::~Board()
{
    if (Checkmate == false)
    {

    }
}
//This funtion is for the currentturn function and makes sure the location given is correct by putting it in an array
//Then has to pass the if statement and would give the appropriate array coordinate depending on the input for the chess coordinate
//If it doesn't pass then they are prompted to put in a location again
int Board::PLocation(string a)
{
    bool valid = false;

    while(valid == false)
    {
        string arr[2];
        for (int i = 0; i < 2; i++)
        {
            arr[i] = a[i];
        }
        if (arr[0] >= "A" && arr[0] <= "H" || arr[0] >= "a" && arr[0] <= "h" && arr[1] >= "1" && arr[1] <= "8")
        {
            valid = true;
            if (arr[0] == "A"||arr[0] == "a")
            {
                return 0;
            }
            else if (arr[0] == "B"||arr[0] == "b")
            {
                return 1;
            }
            else if (arr[0] == "C"||arr[0] == "c")
            {
                return 2;
            }
            else if (arr[0] == "D"||arr[0] == "d")
            {
                return 3;
            }
            else if (arr[0] == "E"||arr[0] == "e")
            {
                return 4;
            }
            else if (arr[0] == "F"||arr[0] == "f")
            {
                return 5;
            }
            else if (arr[0] == "G"||arr[0] == "g")
            {
                return 6;
            }
            else if (arr[0] == "H"||arr[0] == "h")
            {
                return 7;
            }
        }
        else
        {
            cout << "That's not a valid location, check the order of the location. Try again." << endl;
            cout << "What piece would you like to move: ";
            getline(cin, a);
        }
    }
}

int Board::PLocation2(string a)
{
    bool valid = false;

    while(valid == false)
    {
        string arr[2];
        for (int i = 0; i < 2; i++)
        {
            arr[i] = a[i];
        }
        if (arr[0] >= "A" && arr[0] <= "H" || arr[0] >= "a" && arr[0] <= "h" && arr[1] >= "1" && arr[1] <= "8")
        {
            valid = true;
            return stoi(arr[1]) - 1;
        }
        else
        {
            cout << "That's not a valid location, check the order of the location. Try again." << endl;
            cout << "What piece would you like to move: ";
            getline(cin, a);
        }
    }
}

//This asks the players to put in a location to choose a piece, it has to be exactly two, otherwise it would give a prompt to do it again
//Then if it is 2 it would call the plocation function above, then it would call the appropriate chess piece function depending on the piece type at the array location
void Board::currentTurn1()
{
        player_one = true;
        string l;
        cout << "What piece would you like to move, " + string(player1) + ": ";
        getline(cin, l);
        int a, b;
        while (l.length() != 2)
        {
            l = "";
            cout << "That's too long/short, not a valid location. Try again."<< endl;
            cout << "What piece would you like to move, " + string(player1) + ": ";
            getline(cin, l);
        }
        if (l.length() == 2)
        {
            b = PLocation(l);
            a = PLocation2(l);

            if (tileBoard.at(a).at(b).getType() == "Pawn")
            {
                ro = a;
                co = b;
                tileBoard.at(a).at(b) = Pieces();
                Pawn();
            }
            else if (tileBoard.at(a).at(b).getType() == "Bishop")
            {
                ro = a;
                co = b;
                tileBoard.at(a).at(b) = Pieces();
                Bishop();
            }
            else if (tileBoard.at(a).at(b).getType() == "Knight")
            {
                ro = a;
                co = b;
                tileBoard.at(a).at(b) = Pieces();
                Knight();
            }
            else if (tileBoard.at(a).at(b).getType() == "Rook")
            {
                ro = a;
                co = b;
                tileBoard.at(a).at(b) = Pieces();
                Rook();
            }
            else if (tileBoard.at(a).at(b).getType() == "Queen")
            {
                ro = a;
                co = b;
                tileBoard.at(a).at(b) = Pieces();
                Queen();
            }
            else if (tileBoard.at(a).at(b).getType() == "King")
            {
                ro = a;
                co = b;
                tileBoard.at(a).at(b) = Pieces();
                King();
            }
            else if (tileBoard.at(a).at(b).getType() == "")
            {
                cout << "There's nothing there." << endl;
                currentTurn1();
            }
        }
        l = "";
}
void Board::currentTurn2()
{
        string l;
        player_one = false;
        cout << "What piece would you like to move, " + string(player2) + ": ";
        getline(cin, l);
        int r, c;

        while (l.length() != 2)
        {
            l = "";
            cout << "That's too long/short, not a valid location. Try again."<< endl;
            cout << "What piece would you like to move, " + string(player2) + ": ";
            getline(cin, l);
        }
        if (l.length() == 2)
        {
            c = PLocation(l);
            r = PLocation2(l);

            if (tileBoard.at(r).at(c).getType() == "Pawn")
            {
                ro = r;
                co = c;
                tileBoard.at(r).at(c) = Pieces();
                Pawn();
            }
            else if (tileBoard.at(r).at(c).getType() == "Bishop")
            {
                ro = r;
                co = c;
                tileBoard.at(r).at(c) = Pieces();
                Bishop();
            }
            else if (tileBoard.at(r).at(c).getType() == "Knight")
            {
                ro = r;
                co = c;
                tileBoard.at(r).at(c) = Pieces();
                Knight();
            }
            else if (tileBoard.at(r).at(c).getType() == "Rook")
            {
                ro = r;
                co = c;
                tileBoard.at(r).at(c) = Pieces();
                Rook();
            }
            else if (tileBoard.at(r).at(c).getType() == "Queen")
            {
                ro = r;
                co = c;
                tileBoard.at(r).at(c) = Pieces();
                Queen();
            }
            else if (tileBoard.at(r).at(c).getType() == "King")
            {
                ro = r;
                co = c;
                tileBoard.at(r).at(c) = Pieces();
                King();
            }
            else if (tileBoard.at(r).at(c).getType() == "")
            {
                cout << "There's nothing there." << endl;
                currentTurn2();
            }
        }
        l = "";
}
//This puts in all the pieces into the tileboard array
void Board::startGame()
{
    cout << "Let the game begin!" << endl << endl;

    for (int j = 0; j < 8; j++)
    {
        tileBoard.at(1).at(j) = Pieces ("Pawn", "Black", 1, j);
    }

    tileBoard.at(0).at(1) = Pieces("Bishop", "Black", 0, 1);
    tileBoard.at(0).at(6) = Pieces("Bishop", "Black", 0, 6);
    tileBoard.at(0).at(2) = Pieces("Knight", "Black", 0, 2);
    tileBoard.at(0).at(5) = Pieces("Knight", "Black", 0, 5);
    tileBoard.at(0).at(0) = Pieces("Rook", "Black", 0, 0);
    tileBoard.at(0).at(7) = Pieces("Rook", "Black", 0, 7);
    tileBoard.at(0).at(3) = Pieces("Queen", "Black", 0, 3);
    tileBoard.at(0).at(4) = Pieces("King", "Black", 0, 4);

    for (int j = 0; j < 8; j++)
    {
        tileBoard.at(6).at(j) = Pieces("Pawn", "White", 6, j);
    }

    tileBoard.at(7).at(1) = Pieces("Bishop", "White", 7, 1);
    tileBoard.at(7).at(6) = Pieces("Bishop", "White", 7, 6);
    tileBoard.at(7).at(2) = Pieces("Knight", "White", 7, 2);
    tileBoard.at(7).at(5) = Pieces("Knight", "White", 7, 5);
    tileBoard.at(7).at(0) = Pieces("Rook", "White", 7, 0);
    tileBoard.at(7).at(7) = Pieces("Rook", "White", 7, 7);
    tileBoard.at(7).at(3) = Pieces("Queen", "White", 7, 3);
    tileBoard.at(7).at(4) = Pieces("King", "White", 7, 4);
}

void Board::ParseSave(string line, string Array[])
{
    int p = 0;
    int c = 0;
    line = line + " ";

    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ' ')
        {
            Array[c] = line.substr(p, i-p);
            p = i+1;
            c++;
        }
        cout << Array[i] + ", " << endl;
    }
}

//This is meant to get data from the save file to resume the game
void Board::resumeGame()
{
    ifstream myFile;
    myFile.open("SaveFile.cpp");
    string l;

    while (!myFile.eof())
    {
        getline(myFile, l);
        string arr[4];
        ParseSave(l, arr);
        tileBoard.at(stoi(arr[2])).at(stoi(arr[3])) = Pieces(arr[0], arr[1], stoi(arr[2]), stoi(arr[3]));
    }

    cout << "Let the game begin ... Again!" << endl << endl;
}
//This is meant to take the array and put it into the savefile
void Board::saveGame()
{
    if (Checkmate == false)
    {
        ofstream myFile;
        myFile.open("SaveFile.cpp", ofstream::out | ofstream::trunc);
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                if (tileBoard.at(i).at(j).getType() == "Pawn"&& tileBoard.at(i).at(j).getColor() == "Black")
                {
                    myFile << tileBoard.at(i).at(j).getType() + " " + tileBoard.at(i).at(j).getColor() +  " " + to_string(i) + " " + to_string(j) << endl;
                }
                else if (tileBoard.at(i).at(j).getType() == "Bishop" && tileBoard.at(i).at(j).getColor() == "Black")
                {
                    myFile << tileBoard.at(i).at(j).getType() + " " + tileBoard.at(i).at(j).getColor() +  " " + to_string(i) + " " + to_string(j) << endl;
                }
                else if (tileBoard.at(i).at(j).getType() == "Knight" && tileBoard.at(i).at(j).getColor() == "Black")
                {
                    myFile << tileBoard.at(i).at(j).getType() + " " + tileBoard.at(i).at(j).getColor() +  " " + to_string(i) + " " + to_string(j) << endl;
                }
                else if (tileBoard.at(i).at(j).getType() == "Rook" && tileBoard.at(i).at(j).getColor() == "Black")
                {
                    myFile << tileBoard.at(i).at(j).getType() + " " + tileBoard.at(i).at(j).getColor() +  " " + to_string(i) + " " + to_string(j) << endl;
                }
                else if (tileBoard.at(i).at(j).getType() == "Queen" && tileBoard.at(i).at(j).getColor() == "Black")
                {
                    myFile << tileBoard.at(i).at(j).getType() + " " + tileBoard.at(i).at(j).getColor() +  " " + to_string(i) + " " + to_string(j) << endl;
                }
                else if (tileBoard.at(i).at(j).getType() == "King" && tileBoard.at(i).at(j).getColor() == "Black")
                {
                    myFile << tileBoard.at(i).at(j).getType() + " " + tileBoard.at(i).at(j).getColor() +  " " + to_string(i) + " " + to_string(j) << endl;
                }
                else if (tileBoard.at(i).at(j).getType() == "Pawn" && tileBoard.at(i).at(j).getColor() == "White")
                {
                    myFile << tileBoard.at(i).at(j).getType() + " " + tileBoard.at(i).at(j).getColor() +  " " + to_string(i) + " " + to_string(j) << endl;
                }
                else if (tileBoard.at(i).at(j).getType() == "Bishop" && tileBoard.at(i).at(j).getColor() == "White")
                {
                    myFile << tileBoard.at(i).at(j).getType() + " " + tileBoard.at(i).at(j).getColor() +  " " + to_string(i) + " " + to_string(j) << endl;
                }
                else if (tileBoard.at(i).at(j).getType() == "Knight" && tileBoard.at(i).at(j).getColor() == "White")
                {
                    myFile << tileBoard.at(i).at(j).getType() + " " + tileBoard.at(i).at(j).getColor() +  " " + to_string(i) + " " + to_string(j) << endl;
                }
                else if (tileBoard.at(i).at(j).getType() == "Rook" && tileBoard.at(i).at(j).getColor() == "White")
                {
                    myFile << tileBoard.at(i).at(j).getType() + " " + tileBoard.at(i).at(j).getColor() +  " " + to_string(i) + " " + to_string(j) << endl;
                }
                else if (tileBoard.at(i).at(j).getType() == "Queen" && tileBoard.at(i).at(j).getColor() == "White")
                {
                    myFile << tileBoard.at(i).at(j).getType() + " " + tileBoard.at(i).at(j).getColor() +  " " + to_string(i) + " " + to_string(j) << endl;
                }
                else if (tileBoard.at(i).at(j).getType() == "King" && tileBoard.at(i).at(j).getColor() == "White")
                {
                    myFile << tileBoard.at(i).at(j).getType() + " " + tileBoard.at(i).at(j).getColor() +  " " + to_string(i) + " " + to_string(j) << endl;
                }
            }
        }
        myFile.close();
    }
    else
    {
        ofstream myFile;
        myFile.open("SaveFile.cpp", ofstream::out | ofstream::trunc);
        myFile.close();
    }
}
//These are the functions for the chess pieces
void Board::Pawn()
{
    cout << "Where would you like your Pawn to go: ";
    string l;
    getline(cin, l);
    int a, b;

    if (l.length() == 2 && player_one == true)
    {
        a = PLocation2(l);
        b = PLocation(l);
        if (tileBoard.at(a).at(b).getColor() == "White")
        {
            cout << "That's one your pieces, try again" << endl;
            Pawn();
        }
        else
        {
            tileBoard.at(a).at(b) = Pieces();
            tileBoard.at(a).at(b) = Pieces("Pawn", "White", a, b);
        }
    }
    else if (l.length() == 2 && player_one == false)
    {
        a = PLocation2(l);
        b = PLocation(l);
        if (tileBoard.at(a).at(b).getColor() == "Black")
        {
            cout << "That's one your pieces, try again" << endl;
            Pawn();
        }
        else
        {
            tileBoard.at(a).at(b) = Pieces();
            tileBoard.at(a).at(b) = Pieces("Pawn", "Black", a, b);
        }
    }
}

void Board::Bishop()
{
    cout << "Where would you like your Bishop to go: ";
    string l;
    getline(cin, l);
    int a, b;

    if (l.length() == 2 && player_one == true)
    {
        a = PLocation2(l);
        b = PLocation(l);
        tileBoard.at(a).at(b) = Pieces();
        tileBoard.at(a).at(b) = Pieces("Bishop", "White", a, b);
    }
    else if (l.length() == 2 && player_one == false)
    {
        a = PLocation2(l);
        b = PLocation(l);
        tileBoard.at(a).at(b) = Pieces();
        tileBoard.at(a).at(b) = Pieces("Bishop", "Black", a, b);
    }
}

void Board::Knight()
{
    cout << "Where would you like your Knight to go: ";
    string l;
    getline(cin, l);
    int a, b;

    if (l.length() == 2 && player_one == true)
    {
        a = PLocation2(l);
        b = PLocation(l);
        tileBoard.at(a).at(b) = Pieces();
        tileBoard.at(a).at(b) = Pieces("Knight", "White", a, b);
    }
    else if (l.length() == 2 && player_one == false)
    {
        a = PLocation2(l);
        b = PLocation(l);
        tileBoard.at(a).at(b) = Pieces();
        tileBoard.at(a).at(b) = Pieces("Knight", "Black", a, b);
    }
}

void Board::Rook()
{
    cout << "Where would you like your Rook to go: ";
    string l;
    getline(cin, l);
    int a, b;

    if (l.length() == 2 && player_one == true)
    {
        a = PLocation2(l);
        b = PLocation(l);
        tileBoard.at(a).at(b) = Pieces();
        tileBoard.at(a).at(b) = Pieces("Rook", "White", a, b);
    }
    else if (l.length() == 2 && player_one == false)
    {
        a = PLocation2(l);
        b = PLocation(l);
        tileBoard.at(a).at(b) = Pieces();
        tileBoard.at(a).at(b) = Pieces("Rook", "Black", a, b);
    }
}

void Board::Queen()
{
    cout << "Where would you like your Queen to go: ";
    string l;
    getline(cin, l);
    int a, b;

    if (l.length() == 2 && player_one == true)
    {
        a = PLocation2(l);
        b = PLocation(l);
        tileBoard.at(a).at(b) = Pieces();
        tileBoard.at(a).at(b) = Pieces("Queen", "White", a, b);
    }
    else if (l.length() == 2 && player_one == false)
    {
        a = PLocation2(l);
        b = PLocation(l);
        tileBoard.at(a).at(b) = Pieces();
        tileBoard.at(a).at(b) = Pieces("Queen", "Black", a, b);
    }
}

void Board::King()
{
    cout << "Where would you like your King to go: ";
    string l;
    getline(cin, l);
    int a, b;

    if (l.length() == 2 && player_one == true)
    {
        a = PLocation2(l);
        b = PLocation(l);
        tileBoard.at(a).at(b) = Pieces();
        tileBoard.at(a).at(b) = Pieces("King", "White", a, b);
    }
    else if (l.length() == 2 && player_one == false)
    {
        a = PLocation2(l);
        b = PLocation(l);
        tileBoard.at(a).at(b) = Pieces();
        tileBoard.at(a).at(b) = Pieces("King", "Black", a, b);
    }
}

