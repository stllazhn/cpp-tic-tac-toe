# C++ Terminal Tic-Tac-Toe

This is a two-player Tic-Tac-Toe game that runs in the terminal.

The project uses a templated `GameBoard` class to represent the board and a `TicTacToe` class to manage player setup, turns, move validation, win detection, and tie handling.

## Features

- Two-player terminal gameplay
- Player name input
- 3-by-3 Tic-Tac-Toe board
- Move input using row and column coordinates
- Checks for invalid coordinates
- Prevents moves on occupied spaces
- Detects row wins
- Detects column wins
- Detects diagonal wins
- Detects tied games
- Uses C++ templates for board sizing
- Separates board logic from game logic

## Tech Stack

- C++
- Standard Library

## Project Structure

```text
cpp-terminal-tic-tac-toe/
├── README.md
├── .gitignore
└── src/
    ├── GameBoard.h
    ├── GameBoard.cpp
    ├── TicTacToe.h
    ├── TicTacToe.cpp
    └── main.cpp
```

## How to Run

Make sure you have a C++ compiler installed.

Compile the project:

```bash
g++ -std=c++17 src/main.cpp src/GameBoard.cpp src/TicTacToe.cpp -o tic-tac-toe
```

Run the game:

```bash
./tic-tac-toe
```

On Windows, run:

```bash
tic-tac-toe.exe
```

## How to Play

1. Start the program.
2. Press Enter when prompted.
3. Enter Player 1's name.
4. Enter Player 2's name.
5. Players take turns entering coordinates.

Coordinates should be entered in this format:

```text
row column
```

Example:

```text
1 3
```

This means first row, third column.

Player 1 uses:

```text
X
```

Player 2 uses:

```text
O
```

The game ends when one player gets three pieces in a row, column, or diagonal, or when the board is full and the game is tied.

## Example

```text
Please Press Enter to Start the Game:
Please input Player 1 name: Alice
Please input Player 2 name: Bob

Game Start

   |   |   
------------
   |   |   
------------
   |   |   

Alice's turn (X). Enter coordinates in 'x y' format: 1 1
```

## Main Files

```text
src/GameBoard.h
```

Defines the templated board class used to store and display pieces.

```text
src/TicTacToe.h
```

Defines the main game logic, including turns, move validation, win checks, and tie checks.

```text
src/main.cpp
```

Creates and starts a `TicTacToe<3>` game.

## Notes

The project focuses on classes, templates, arrays, terminal input/output, turn-based game logic, and separating board behavior from gameplay behavior.
