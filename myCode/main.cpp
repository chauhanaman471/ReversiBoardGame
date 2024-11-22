/**
 * @file main.cpp
 * @brief Main entry point of the Reversi game program.
 *
 * This program simulates a Reversi game where two players alternate placing
 * tokens on the board. The game tracks the board state and determines the
 * winner or end state based on user input.
 *
 * @author Aman Chauhan
 * @date 2024-11-20
 * @details Master student at HDA (Matriculation No. 1127928)
 *
 * @return int Exit code of the program (0 for successful execution).
 */

// Standard (system) header files
#include <iostream>
#include <cstdlib>

// Add more standard header files as required
using namespace std;

// Add your project's header files here
#include "ReversiBoard.h"
#include "ReversiConsoleView.h"

/**
 * @brief Main entry point of the program.
 *
 * This function initializes the game, handles user input, updates the board,
 * and determines the winner when the game ends.
 */
int main()
{
    cout << "The starting point of a board game" << endl;

    // Getting dimensions of the board from user
    cout << "Please enter the size (x,y) of the game:" << endl;

    int xDimension, yDimension;
    cin >> xDimension >> yDimension;

    // Checking a valid positive board dimension range
    while(xDimension <= 0){
        cout << "Please enter a positive number for no of rows: "<<endl;
        cin >> xDimension;
    }
    while(yDimension <= 0){
        cout << "Please enter a positive number for no of columns: "<<endl;
        cin >> yDimension;
    }

    /**
     * @brief Create a ReversiBoard object.
     * @param xDimension The width of the board.
     * @param yDimension The height of the board.
     */
    ReversiBoard board{xDimension, yDimension};

    // Creating a ReversiConsoleView object
    // This object is passing the address of ReversiBoard instance (board)
    ReversiConsoleView printBoard{&board};

    // Variable to track game progress
    bool gameInProgress = true;

    // Variable to switch between players
    int currentPlayer = 1;

    while (gameInProgress){
        // Print the current board state
        printBoard.print();

        cout << "User can place token from position x-> 0 to "
             << (xDimension - 1) << " ,y-> 0 to " << (yDimension - 1)
             << endl;
        cout << "Tokens for Player 1: 'x' and Player 2: 'o'" << endl;

        // Get token and its position from user
        cout << "Player:" << currentPlayer << " Please enter a position (x,y) "
             "and a stone character (-1 to end):" << endl;

        int xTokenPos;
        int yTokenPos;
        char token;

        cin >> xTokenPos;

        // Logic to end the game
        if (xTokenPos == -1){
            gameInProgress = false;
            cout << "You have ended the game" << endl;
            break;
        }

        cin >> yTokenPos >> token;

        cout << "Token: " << token << " with position: "
             << xTokenPos << "," << yTokenPos << endl;

        /**
         * @brief Query the board field state at a specific token position.
         * @param xTokenPos The x-coordinate of the token position.
         * @param yTokenPos The y-coordinate of the token position.
         */
        board.getFieldState(xTokenPos, yTokenPos);

        /**
         * @brief Set the field state of the board.
         *
         * @param xTokenPos The x-coordinate of the token position.
         * @param yTokenPos The y-coordinate of the token position.
         * @param token The player's token ('x' or 'o').
         * @return bool True if the move is valid, false otherwise.
         */
        if (board.setFieldState(xTokenPos, yTokenPos, token) == true){
            // Switch player after a successful move
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
        }
        else{
            cout << "Invalid Move. Please try again" << endl;
        }

        /**
         * @brief Check if the game is over.
         *
         * If the game is over, calculate and display the winner.
         * @return bool True if the game is over, false otherwise.
         */
        if (board.gameOver() == true){
            gameInProgress = false;
            cout << "Game Over! Calculating Winner..." << endl;

            // Display the winner
            board.gameWinner();
        }
    }

    return 0;
}
