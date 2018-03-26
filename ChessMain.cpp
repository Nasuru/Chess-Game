#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include "Board.h"
#include "Pieces.h"
#include "ScoreBoard.h"
using namespace std;
//This is meant to keep the window open for the chess board
bool running;

void On()
{
    SDL_Event events;
    while(SDL_PollEvent(&events))
    {
        if(events.type == SDL_QUIT)
        {
            running = false;
        }
    }
}

int change(int i)
{
    if (i == 0)
    {
        return 0;
    }
    else if (i == 1)
    {
        return 80;
    }
    else if (i == 2)
    {
        return 160;
    }
    else if (i == 3)
    {
        return 240;
    }
    else if (i == 4)
    {
        return 320;
    }
    else if (i == 5)
    {
        return 400;
    }
    else if (i == 6)
    {
        return 480;
    }
    else if (i == 7)
    {
        return 560;
    }
    else if (i == 8)
    {
        return 640;
    }
}

int main(int argc, char* args[])
{
    //This makes a board instance and initializes everything for sdl2 to work
    Board game;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    int area = 800;

    window = SDL_CreateWindow("window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 800, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    SDL_RenderClear(renderer);

    //This makes the font sizes and type
    TTF_Font *font = TTF_OpenFont("BEBAS.ttf", 60);
    TTF_Font *font1 = TTF_OpenFont("BEBAS.ttf", 90);

    SDL_Color color = {0, 0, 0, 255};

    //This is the letters and numbers on the side
    string letters[8] = {"A", "B", "C", "D", "E", "F", "G", "H"};

    // This is to get the Chess Pieces on display from an image
    SDL_Surface *image = IMG_Load("Chess.png");
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);


    //Keep window open and for text input
    running = true;

    while (running)
    {
        On();

        //This is the board and uses a for loop to make black spaces and the white is the background
        int row, column, x;
        SDL_Rect rect;

        for (row = 0; row < 8; row++)
        {
            column = row % 2;
            x = column;
            for (column = 0; column < 4 + (row % 1); column++)
            {
                SDL_SetRenderDrawColor(renderer, 64, 64, 64, 255);
                rect.w = area/10;
                rect.h = area/10;
                rect.x = x * rect.w;
                rect.y = row * rect.h;
                x = x + 2;
                SDL_RenderFillRect(renderer, &rect);
            }
        }
        //This adds a border to the chess board
        SDL_Rect line;
        line.x = 0;
        line.y = 0;
        line.w = 640;
        line.h = 640;

        SDL_RenderDrawRect(renderer, &line);
        //side text
        for (int i = 0; i < 8; i++)
        {
            SDL_Surface *M = TTF_RenderText_Solid(font, letters[i].c_str(), color);
            SDL_Texture *ABC = SDL_CreateTextureFromSurface(renderer, M);

            SDL_Rect Letter;
            Letter.x = (i * 80) + 27;
            Letter.y = 655;
            Letter.w = area/25;
            Letter.h = area/25;

            SDL_RenderCopy(renderer, ABC, NULL, &Letter);
        }

        for (int i = 0; i < 8; i++)
        {
            SDL_Surface *M = TTF_RenderText_Solid(font, to_string(i+1).c_str(), color);
            SDL_Texture *ABC = SDL_CreateTextureFromSurface(renderer, M);

            SDL_Rect Letter;
            Letter.x = 655;
            Letter.y = (i * 80) + 27;
            Letter.w = area/25;
            Letter.h = area/25;

            SDL_RenderCopy(renderer, ABC, NULL, &Letter);
        }
        //Pieces
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (game.tileBoard.at(i).at(j).getType() == "Pawn"&& game.tileBoard.at(i).at(j).getColor() == "Black")
                {
                    SDL_Rect Pawn;
                    Pawn.x = 1665;
                    Pawn.y = 333;
                    Pawn.w = 333;
                    Pawn.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &Pawn, &Spot);
                }
                else if (game.tileBoard.at(i).at(j).getType() == "Bishop" && game.tileBoard.at(i).at(j).getColor() == "Black")
                {
                    SDL_Rect Bishop;
                    Bishop.x = 666;
                    Bishop.y = 333;
                    Bishop.w = 333;
                    Bishop.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &Bishop, &Spot);
                }
                else if (game.tileBoard.at(i).at(j).getType() == "Knight" && game.tileBoard.at(i).at(j).getColor() == "Black")
                {
                    SDL_Rect Knight;
                    Knight.x = 999;
                    Knight.y = 333;
                    Knight.w = 333;
                    Knight.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &Knight, &Spot);
                }
                else if (game.tileBoard.at(i).at(j).getType() == "Rook" && game.tileBoard.at(i).at(j).getColor() == "Black")
                {
                    SDL_Rect Rook;
                    Rook.x = 1332;
                    Rook.y = 333;
                    Rook.w = 333;
                    Rook.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &Rook, &Spot);
                }
                else if (game.tileBoard.at(i).at(j).getType() == "Queen" && game.tileBoard.at(i).at(j).getColor() == "Black")
                {
                    SDL_Rect Queen;
                    Queen.x = 333;
                    Queen.y = 333;
                    Queen.w = 333;
                    Queen.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &Queen, &Spot);
                }
                else if (game.tileBoard.at(i).at(j).getType() == "King" && game.tileBoard.at(i).at(j).getColor() == "Black")
                {
                    SDL_Rect King;
                    King.x = 0;
                    King.y = 333;
                    King.w = 333;
                    King.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &King, &Spot);
                }
                else if (game.tileBoard.at(i).at(j).getType() == "Pawn" && game.tileBoard.at(i).at(j).getColor() == "White")
                {
                    SDL_Rect Pawn;
                    Pawn.x = 1665;
                    Pawn.y = 0;
                    Pawn.w = 333;
                    Pawn.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &Pawn, &Spot);
                }
                else if (game.tileBoard.at(i).at(j).getType() == "Bishop" && game.tileBoard.at(i).at(j).getColor() == "White")
                {
                    SDL_Rect Bishop;
                    Bishop.x = 666;
                    Bishop.y = 0;
                    Bishop.w = 333;
                    Bishop.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &Bishop, &Spot);
                }
                else if (game.tileBoard.at(i).at(j).getType() == "Knight" && game.tileBoard.at(i).at(j).getColor() == "White")
                {
                    SDL_Rect Knight;
                    Knight.x = 999;
                    Knight.y = 0;
                    Knight.w = 333;
                    Knight.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &Knight, &Spot);
                }
                else if (game.tileBoard.at(i).at(j).getType() == "Rook" && game.tileBoard.at(i).at(j).getColor() == "White")
                {
                    SDL_Rect Rook;
                    Rook.x = 1332;
                    Rook.y = 0;
                    Rook.w = 333;
                    Rook.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &Rook, &Spot);
                }
                else if (game.tileBoard.at(i).at(j).getType() == "Queen" && game.tileBoard.at(i).at(j).getColor() == "White")
                {
                    SDL_Rect Queen;
                    Queen.x = 333;
                    Queen.y = 0;
                    Queen.w = 333;
                    Queen.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &Queen, &Spot);
                }
                else if (game.tileBoard.at(i).at(j).getType() == "King" && game.tileBoard.at(i).at(j).getColor() == "White")
                {
                    SDL_Rect King;
                    King.x = 0;
                    King.y = 0;
                    King.w = 333;
                    King.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &King, &Spot);
                }
            }
        }

        game.saveGame();
        SDL_RenderPresent(renderer);

        game.currentTurn1();

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        for (row = 0; row < 8; row++)
        {
            column = row % 2;
            x = column;
            for (column = 0; column < 4 + (row % 1); column++)
            {
                SDL_SetRenderDrawColor(renderer, 64, 64, 64, 255);
                rect.w = area/10;
                rect.h = area/10;
                rect.x = x * rect.w;
                rect.y = row * rect.h;
                x = x + 2;
                SDL_RenderFillRect(renderer, &rect);
            }
        }
        //This adds a border to the chess board

        SDL_RenderDrawRect(renderer, &line);
        //side text
        for (int i = 0; i < 8; i++)
        {
            SDL_Surface *M = TTF_RenderText_Solid(font, letters[i].c_str(), color);
            SDL_Texture *ABC = SDL_CreateTextureFromSurface(renderer, M);

            SDL_Rect Letter;
            Letter.x = (i * 80) + 27;
            Letter.y = 655;
            Letter.w = area/25;
            Letter.h = area/25;

            SDL_RenderCopy(renderer, ABC, NULL, &Letter);
        }

        for (int i = 0; i < 8; i++)
        {
            SDL_Surface *M = TTF_RenderText_Solid(font, to_string(i+1).c_str(), color);
            SDL_Texture *ABC = SDL_CreateTextureFromSurface(renderer, M);

            SDL_Rect Letter;
            Letter.x = 655;
            Letter.y = (i * 80) + 27;
            Letter.w = area/25;
            Letter.h = area/25;

            SDL_RenderCopy(renderer, ABC, NULL, &Letter);
        }
        //Pieces
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (game.tileBoard.at(i).at(j).getType() == "Pawn"&& game.tileBoard.at(i).at(j).getColor() == "Black")
                {
                    SDL_Rect Pawn;
                    Pawn.x = 1665;
                    Pawn.y = 333;
                    Pawn.w = 333;
                    Pawn.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &Pawn, &Spot);
                }
                else if (game.tileBoard.at(i).at(j).getType() == "Bishop" && game.tileBoard.at(i).at(j).getColor() == "Black")
                {
                    SDL_Rect Bishop;
                    Bishop.x = 666;
                    Bishop.y = 333;
                    Bishop.w = 333;
                    Bishop.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &Bishop, &Spot);
                }
                else if (game.tileBoard.at(i).at(j).getType() == "Knight" && game.tileBoard.at(i).at(j).getColor() == "Black")
                {
                    SDL_Rect Knight;
                    Knight.x = 999;
                    Knight.y = 333;
                    Knight.w = 333;
                    Knight.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &Knight, &Spot);
                }
                else if (game.tileBoard.at(i).at(j).getType() == "Rook" && game.tileBoard.at(i).at(j).getColor() == "Black")
                {
                    SDL_Rect Rook;
                    Rook.x = 1332;
                    Rook.y = 333;
                    Rook.w = 333;
                    Rook.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &Rook, &Spot);
                }
                else if (game.tileBoard.at(i).at(j).getType() == "Queen" && game.tileBoard.at(i).at(j).getColor() == "Black")
                {
                    SDL_Rect Queen;
                    Queen.x = 333;
                    Queen.y = 333;
                    Queen.w = 333;
                    Queen.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &Queen, &Spot);
                }
                else if (game.tileBoard.at(i).at(j).getType() == "King" && game.tileBoard.at(i).at(j).getColor() == "Black")
                {
                    SDL_Rect King;
                    King.x = 0;
                    King.y = 333;
                    King.w = 333;
                    King.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &King, &Spot);
                }
                else if (game.tileBoard.at(i).at(j).getType() == "Pawn" && game.tileBoard.at(i).at(j).getColor() == "White")
                {
                    SDL_Rect Pawn;
                    Pawn.x = 1665;
                    Pawn.y = 0;
                    Pawn.w = 333;
                    Pawn.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &Pawn, &Spot);
                }
                else if (game.tileBoard.at(i).at(j).getType() == "Bishop" && game.tileBoard.at(i).at(j).getColor() == "White")
                {
                    SDL_Rect Bishop;
                    Bishop.x = 666;
                    Bishop.y = 0;
                    Bishop.w = 333;
                    Bishop.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &Bishop, &Spot);
                }
                else if (game.tileBoard.at(i).at(j).getType() == "Knight" && game.tileBoard.at(i).at(j).getColor() == "White")
                {
                    SDL_Rect Knight;
                    Knight.x = 999;
                    Knight.y = 0;
                    Knight.w = 333;
                    Knight.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &Knight, &Spot);
                }
                else if (game.tileBoard.at(i).at(j).getType() == "Rook" && game.tileBoard.at(i).at(j).getColor() == "White")
                {
                    SDL_Rect Rook;
                    Rook.x = 1332;
                    Rook.y = 0;
                    Rook.w = 333;
                    Rook.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &Rook, &Spot);
                }
                else if (game.tileBoard.at(i).at(j).getType() == "Queen" && game.tileBoard.at(i).at(j).getColor() == "White")
                {
                    SDL_Rect Queen;
                    Queen.x = 333;
                    Queen.y = 0;
                    Queen.w = 333;
                    Queen.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &Queen, &Spot);
                }
                else if (game.tileBoard.at(i).at(j).getType() == "King" && game.tileBoard.at(i).at(j).getColor() == "White")
                {
                    SDL_Rect King;
                    King.x = 0;
                    King.y = 0;
                    King.w = 333;
                    King.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &King, &Spot);
                }
            }
        }
        game.saveGame();
        SDL_RenderPresent(renderer);

        game.currentTurn2();

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        for (row = 0; row < 8; row++)
        {
            column = row % 2;
            x = column;
            for (column = 0; column < 4 + (row % 1); column++)
            {
                SDL_SetRenderDrawColor(renderer, 64, 64, 64, 255);
                rect.w = area/10;
                rect.h = area/10;
                rect.x = x * rect.w;
                rect.y = row * rect.h;
                x = x + 2;
                SDL_RenderFillRect(renderer, &rect);
            }
        }
        //This adds a border to the chess board

        SDL_RenderDrawRect(renderer, &line);
        //side text
        for (int i = 0; i < 8; i++)
        {
            SDL_Surface *M = TTF_RenderText_Solid(font, letters[i].c_str(), color);
            SDL_Texture *ABC = SDL_CreateTextureFromSurface(renderer, M);

            SDL_Rect Letter;
            Letter.x = (i * 80) + 27;
            Letter.y = 655;
            Letter.w = area/25;
            Letter.h = area/25;

            SDL_RenderCopy(renderer, ABC, NULL, &Letter);
        }

        for (int i = 0; i < 8; i++)
        {
            SDL_Surface *M = TTF_RenderText_Solid(font, to_string(i+1).c_str(), color);
            SDL_Texture *ABC = SDL_CreateTextureFromSurface(renderer, M);

            SDL_Rect Letter;
            Letter.x = 655;
            Letter.y = (i * 80) + 27;
            Letter.w = area/25;
            Letter.h = area/25;

            SDL_RenderCopy(renderer, ABC, NULL, &Letter);
        }
        //Pieces
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (game.tileBoard.at(i).at(j).getType() == "Pawn"&& game.tileBoard.at(i).at(j).getColor() == "Black")
                {
                    SDL_Rect Pawn;
                    Pawn.x = 1665;
                    Pawn.y = 333;
                    Pawn.w = 333;
                    Pawn.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &Pawn, &Spot);
                }
                else if (game.tileBoard.at(i).at(j).getType() == "Bishop" && game.tileBoard.at(i).at(j).getColor() == "Black")
                {
                    SDL_Rect Bishop;
                    Bishop.x = 666;
                    Bishop.y = 333;
                    Bishop.w = 333;
                    Bishop.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &Bishop, &Spot);
                }
                else if (game.tileBoard.at(i).at(j).getType() == "Knight" && game.tileBoard.at(i).at(j).getColor() == "Black")
                {
                    SDL_Rect Knight;
                    Knight.x = 999;
                    Knight.y = 333;
                    Knight.w = 333;
                    Knight.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &Knight, &Spot);
                }
                else if (game.tileBoard.at(i).at(j).getType() == "Rook" && game.tileBoard.at(i).at(j).getColor() == "Black")
                {
                    SDL_Rect Rook;
                    Rook.x = 1332;
                    Rook.y = 333;
                    Rook.w = 333;
                    Rook.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &Rook, &Spot);
                }
                else if (game.tileBoard.at(i).at(j).getType() == "Queen" && game.tileBoard.at(i).at(j).getColor() == "Black")
                {
                    SDL_Rect Queen;
                    Queen.x = 333;
                    Queen.y = 333;
                    Queen.w = 333;
                    Queen.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &Queen, &Spot);
                }
                else if (game.tileBoard.at(i).at(j).getType() == "King" && game.tileBoard.at(i).at(j).getColor() == "Black")
                {
                    SDL_Rect King;
                    King.x = 0;
                    King.y = 333;
                    King.w = 333;
                    King.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &King, &Spot);
                }
                else if (game.tileBoard.at(i).at(j).getType() == "Pawn" && game.tileBoard.at(i).at(j).getColor() == "White")
                {
                    SDL_Rect Pawn;
                    Pawn.x = 1665;
                    Pawn.y = 0;
                    Pawn.w = 333;
                    Pawn.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &Pawn, &Spot);
                }
                else if (game.tileBoard.at(i).at(j).getType() == "Bishop" && game.tileBoard.at(i).at(j).getColor() == "White")
                {
                    SDL_Rect Bishop;
                    Bishop.x = 666;
                    Bishop.y = 0;
                    Bishop.w = 333;
                    Bishop.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &Bishop, &Spot);
                }
                else if (game.tileBoard.at(i).at(j).getType() == "Knight" && game.tileBoard.at(i).at(j).getColor() == "White")
                {
                    SDL_Rect Knight;
                    Knight.x = 999;
                    Knight.y = 0;
                    Knight.w = 333;
                    Knight.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &Knight, &Spot);
                }
                else if (game.tileBoard.at(i).at(j).getType() == "Rook" && game.tileBoard.at(i).at(j).getColor() == "White")
                {
                    SDL_Rect Rook;
                    Rook.x = 1332;
                    Rook.y = 0;
                    Rook.w = 333;
                    Rook.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &Rook, &Spot);
                }
                else if (game.tileBoard.at(i).at(j).getType() == "Queen" && game.tileBoard.at(i).at(j).getColor() == "White")
                {
                    SDL_Rect Queen;
                    Queen.x = 333;
                    Queen.y = 0;
                    Queen.w = 333;
                    Queen.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &Queen, &Spot);
                }
                else if (game.tileBoard.at(i).at(j).getType() == "King" && game.tileBoard.at(i).at(j).getColor() == "White")
                {
                    SDL_Rect King;
                    King.x = 0;
                    King.y = 0;
                    King.w = 333;
                    King.h = 333;

                    SDL_Rect Spot;
                    Spot.x = change(j);
                    Spot.y = change(i);
                    Spot.w = area/10;
                    Spot.h = area/10;

                    SDL_RenderCopy(renderer, texture, &King, &Spot);
                }
            }
        }
        game.saveGame();
        SDL_RenderPresent(renderer);
       /* TTF_Font *font = TTF_OpenFont("BEBAS.ttf", 60);
        TTF_Font *font1 = TTF_OpenFont("BEBAS.ttf", 90);

        SDL_Color color = {0, 0, 0, 255};

        SDL_Surface *surfaceMessage = TTF_RenderText_Solid(font1, "Choose Your Piece: ", color);

        SDL_Texture *Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

        SDL_Rect Message_rect;
        Message_rect.x = 720;
        Message_rect.y = 20;
        Message_rect.w = 150;
        Message_rect.h = 50;
        SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

        SDL_FreeSurface(surfaceMessage);
        surfaceMessage = nullptr;*/
    }

  //  SDL_DestroyTexture(Message);
    TTF_Quit();
    SDL_Quit();
    return 0;
}



