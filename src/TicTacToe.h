//
//  TicTacToe.h
//  FinalAssignment
//
//  Created by Juanru Zhang on 11/26/25.
//

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "GameBoard.h"
#include <iostream>
#include <string>

template<int NUMSIZE>
class TicTacToe {
private:
    GameBoard<NUMSIZE, NUMSIZE> board;
    std::string player1, player2;
    char p1Piece = 'X';
    char p2Piece = 'O';

public:
    void setupPlayer1();
    void setupPlayer2();
    void play();

private:
    void NewTurn(const std::string& name, char piece);
    bool gameOver(char& winningPiece);
    void WinnerIs(const char p);
};

template<int NUMSIZE>
void TicTacToe<NUMSIZE>::setupPlayer1() {
    std::cout << "Please input Player 1 name: ";
    std::getline(std::cin, player1);
}

template<int NUMSIZE>
void TicTacToe<NUMSIZE>::setupPlayer2() {
    std::cout << "Please input Player 2 name: ";
    std::getline(std::cin, player2);
}

// Receive input coordinates from player
template<int NUMSIZE>
void TicTacToe<NUMSIZE>::NewTurn(const std::string& name, char piece) {
    int row, column;

    while (true) {
        std::cout << name << "'s turn (" << piece << "). Enter coordiates in 'x y' format, with row numbers 1,2,3 and column numbers 1,2,3. E.g 1 3 is first row, third column: ";
        std::cin >> row >> column;
        
        row -= 1;
        column -= 1;

        if (row < 0 || row >= NUMSIZE || column < 0 || column >= NUMSIZE) {
            std::cout << "Invalid coordinates. Please enter another set of coordinates.\n";
            continue;
        }
        if (board.isOccupied(row, column)) {
            std::cout << "These coordinates is already used. Please enter another set of coordinates.\n";
            continue;
        }

        board.placePiece(piece, row, column);
        break;
    }
    std::cout << "\n";
    board.display();
    std::cout << "\n";
}

template<int NUMSIZE>
bool TicTacToe<NUMSIZE>::gameOver(char& winningPiece) {
    //Check whether the winning condition has been met for columns
    for (int c = 0; c < NUMSIZE; c++) {
        char first = board.getPiece(0, c);
        if (first == ' ') continue;

        bool win = true;
        for (int r = 1; r < NUMSIZE; r++)
            if (board.getPiece(r, c) != first) win = false;

        if (win) { winningPiece = first; return true; }
    }

    //Check whether the winning condition has been met for rows
    for (int r = 0; r < NUMSIZE; r++) {
        char first = board.getPiece(r, 0);
        if (first == ' ') continue;

        bool win = true;
        for (int c = 1; c < NUMSIZE; c++)
            if (board.getPiece(r, c) != first) win = false;

        if (win) { winningPiece = first; return true; }
    }

    //Check whether the winning condition has been met for diagonal from top left to bottom right
    {
        char first = board.getPiece(0, 0);
        if (first != ' ') {
            bool win = true;
            for (int i = 1; i < NUMSIZE; i++)
                if (board.getPiece(i, i) != first) win = false;

            if (win) { winningPiece = first; return true; }
        }
    }

    //Check whether the winning condition has been met for diagonal from bottom left to top right
    {
        char first = board.getPiece(NUMSIZE - 1, 0);
        if (first != ' ') {
            bool win = true;
            for (int i = 1; i < NUMSIZE; i++)
                if (board.getPiece(NUMSIZE - 1 - i, i) != first) win = false;

            if (win) { winningPiece = first; return true; }
        }
    }

    return false;
}

// Check Winner
template<int NUMSIZE>
void TicTacToe<NUMSIZE>::WinnerIs(const char p) {
    if (p == p1Piece)
        std::cout << "\nThe Winner is " << player1 << ".\n";
    else
        std::cout << "\nThe Winner is " << player2 << ".\n";
}

//Gameplay setup
template<int NUMSIZE>
void TicTacToe<NUMSIZE>::play() {
    std::cin.ignore();

    setupPlayer1();
    setupPlayer2();

    std::cout << "\nGame Start\n\n";
    board.display();
    std::cout << "\n";

    char winner = ' ';

    // Loop: One player make a move, code verify whether game is won or tied
    while (true) {
        NewTurn(player1, p1Piece);
        if (gameOver(winner)) { WinnerIs(winner); break; }
        if (board.boardFull()) { std::cout << "Tied.\n"; break; }

        NewTurn(player2, p2Piece);
        if (gameOver(winner)) { WinnerIs(winner); break; }
        if (board.boardFull()) { std::cout << "Tied.\n"; break; }
    }
}

#endif

