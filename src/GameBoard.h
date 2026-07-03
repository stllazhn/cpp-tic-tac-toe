//
//  GameBoard.h
//  FinalAssignment
//
//  Created by Juanru Zhang on 11/26/25.
//

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>

//Class for making game board
template<int W, int H>
class GameBoard {
private:
    char board[W][H];

public:
    GameBoard();

    char getPiece(int x, int y) const;
    bool isOccupied(int x, int y) const;
    bool boardFull() const;
    void placePiece(char piece, int x, int y);
    void display() const;
};

//Set up initial playing board
template<int W, int H>
GameBoard<W, H>::GameBoard() {
    for (int r = 0; r < H; r++)
        for (int c = 0; c < W; c++)
            board[r][c] = ' ';
}

//Get piece at coordinates x,y
template<int W, int H>
char GameBoard<W, H>::getPiece(int x, int y) const {
    return board[x][y];
}

//Check piece present or not at coordinates x,y
template<int W, int H>
bool GameBoard<W, H>::isOccupied(int x, int y) const {
    return board[x][y] != ' ';
}

//Put piece at coordinates x,y
template<int W, int H>
void GameBoard<W, H>::placePiece(char piece, int x, int y) {
    board[x][y] = piece;  
}

//Check if board is full
template<int W, int H>
bool GameBoard<W, H>::boardFull() const {
    for (int r = 0; r < H; r++)
        for (int c = 0; c < W; c++)
            if (board[r][c] == ' ')
                return false;
    return true;
}

//Print out playing board
template<int W, int H>
void GameBoard<W, H>::display() const {
    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            std::cout << " " << board[r][c] << " ";
            if (c < W - 1) std::cout << "|";
        }
        std::cout << "\n";

        if (r < H - 1) {
            for (int c = 0; c < W; c++) {
                std::cout << "----";
            }
            std::cout << "\n";
        }
    }
}

#endif
