//
//  main.cpp
//  FinalAssignment
//
//  Created by Juanru Zhang on 11/25/25.
//

#include <iostream>

#include "TicTacToe.h"

int main() {
    TicTacToe<3> game;
    std::cout << "Please Press Enter to Start the Game: ";
    game.play();
    return 0;
}
