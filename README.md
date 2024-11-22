# Reversi Game

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Project Structure](#project-structure)
- [Prerequisites](#prerequisites)
- [Setup and Compilation](#setup-and-compilation)
- [Usage](#usage)
- [Game Rules](#game-rules)
- [Contributing](#contributing)
- [License](#license)

## Introduction
This project implements a command-line version of the classic Reversi (Othello) game. Two players alternate turns, placing tokens on the board while attempting to capture their opponent's pieces by flanking them. The game continues until the board is full or no player can make a valid move. The player with the most tokens on the board at the end wins.

## Features
- **Flexible Board Size**: Users can specify the board dimensions (e.g., 8x8 for a standard Reversi board).
- **Full Game Rules**: Includes move validation, token flipping, and proper handling of the game state.
- **Text-Based Board Visualization**: The game visually displays the board after every move, making it easy to follow along.
- **End Game Detection**: Automatically detects when the game ends and announces the winner.

## Project Structure
ReversiGame/
  ├── main.cpp                  # Entry point of the game
  ├── ReversiBoard.h            # Header file for the board logic
  ├── ReversiBoard.cpp          # Implementation of the board logic
  ├── ReversiConsoleView.h      # Header file for board visualization
  ├── ReversiConsoleView.cpp    # Implementation of board visualization
  └── README.md                 # Documentation (this file)


