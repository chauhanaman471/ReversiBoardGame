/**
 * @file ReversiConsoleView.cpp
 * @brief Implementation of the ReversiConsoleView class.
 *
 * This file contains the implementation of the methods defined in the
 * ReversiConsoleView class. It provides the functionality to print
 * the current state of the Reversi game board to the console.
 *
 *  @date 5 Nov 2024
 *  @author Aman Chauhan
 *  @details Master Student at HDA (Matriculation number: 1127928)
 */

#include "ReversiConsoleView.h"
#include "ReversiBoard.h"
#include <iostream>
using namespace std;

/**
 * @brief Constructor to initialize the ReversiConsoleView with a ReversiBoard.
 * @param board Pointer to an instance of ReversiBoard.
 *
 * This constructor assigns the board pointer to the passed ReversiBoard
 * instance to interact with and display the game state.
 */
ReversiConsoleView::ReversiConsoleView(ReversiBoard *board){
    // Assign the pointer to the ReversiBoard instance
    boardPointer = board;
}

/**
 * @brief Method to print the current state of the game board to the console.
 *
 * This method displays the dimensions of the board and prints the current
 * state of the board. It iterates over the board and displays the player
 * tokens ('x' for Player1, 'o' for Player2) or empty spaces ('.').
 */
void ReversiConsoleView::print(){
    // Displaying the board dimensions and object address using "this"
    cout << "Allocated board of dimension x = " << boardPointer->rows
         << ", y = " << boardPointer->columns
         << " at address " << this << endl;
    cout << "Current Board State:" << endl;

    // Iterate through the board to display tokens or empty spaces
    for (int i = 0; i < boardPointer->rows; i++) {
        for (int j = 0; j < boardPointer->columns; j++) {
            if (boardPointer->board[i][j] == boardPointer->EMPTY) {
                cout << ". ";
            } else if (boardPointer->board[i][j] == boardPointer->PLAYER1){
                cout << "x ";
            } else {
                cout << "o ";
            }
        }
        cout << endl;
    }
}
