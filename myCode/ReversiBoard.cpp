/**
 *  @file ReversiBoard.cpp
 *  @brief Implementation of the ReversiBoard class.
 *
 *  This file contains the implementation of the ReversiBoard class, which
 *  manages the game board and implements the game logic for the Reversi game.
 *  The board is represented as a 2D array, and the class provides methods to:
 *  - Initialize the board
 *  - Validate moves
 *  - Update the board state
 *  - Determine the winner
 *  - Check if the game is over
 *
 *  @date 5 Nov 2024
 *  @author Aman Chauhan
 *  @details Master Student at HDA (Matriculation number: 1127928)
 */
#include "ReversiConsoleView.h"
#include "ReversiBoard.h"
#include <iostream>
using namespace std;
#include <vector>

/**
 * @brief Constructor to initialize the board with given dimensions.
 *
 * This constructor sets up the Reversi game board with the specified number
 * of rows and columns. It initializes the board to an empty state and
 * places the initial tokens in the center according to Reversi rules.
 *
 * @param xDimension Number of rows in the board.
 * @param yDimension Number of columns in the board.
 */
ReversiBoard::ReversiBoard(int xDimension, int yDimension){
    rows = xDimension;
    columns = yDimension;
    // Resize the board to create a 2D vector with rows x columns
    board.resize(rows, vector<BoardState>(columns, EMPTY));

    // Set up initial token pieces in the center as per Reversi rules
    board[(rows / 2) - 1][(columns / 2) - 1] = PLAYER1;
    board[rows / 2][(columns / 2) - 1] = PLAYER2;
    board[(rows / 2) - 1][columns / 2] = PLAYER2;
    board[rows / 2][columns / 2] = PLAYER1;
}

/**
 * @brief Method to query the state of a specific field on the board.
 *
 * This method checks if the field at the given position is empty or
 * occupied by one of the players.
 *
 * @param xPosition Row position on the board.
 * @param yPosition Column position on the board.
 */
void ReversiBoard::getFieldState(int xPosition, int yPosition){
    if(xPosition >= rows || yPosition >= columns || xPosition < 0 ||
       yPosition < 0){
        cout << "x: " << xPosition << " y: " << yPosition << " is Invalid"
             << endl;
    }
    switch(board[xPosition][yPosition]){
    case EMPTY:
        cout << "x:" << xPosition << " & y:" << yPosition << " is empty"
             << endl;
        break;
    case PLAYER1:
        cout << "x:" << xPosition << " & y:" << yPosition
             << " is occupied by Player 1" << endl;
        break;
    case PLAYER2:
        cout << "x:" << xPosition << " & y:" << yPosition
             << " is occupied by Player 2" << endl;
        break;
    default:
        cout << "x:" << xPosition << " & y:" << yPosition << " is Invalid"
             << endl;
    }
}

/**
 * @brief Method to check if the move is valid and update the board state.
 *
 * This method checks if a given move is valid and updates the board field
 * with the appropriate token. If the move is invalid, the board remains
 * unchanged.
 *
 * @param xPosition Row position of the move.
 * @param yPosition Column position of the move.
 * @param token Token ('x' for Player 1, 'o' for Player 2) to be placed
 * on the board.
 *
 * @return True if the move is valid and was made; false otherwise.
 */
bool ReversiBoard::setFieldState(int xPosition, int yPosition, char token){
    BoardState player = (token == 'x') ? PLAYER1 : PLAYER2;
    // Move is valid and flip opponent token
    if(isValidMove(xPosition, yPosition, player) == true){
        cout << "Valid Move" << endl;
        board[xPosition][yPosition] = player;
        return true;
    } else {
        cout << "Invalid Move" << endl;
        return false;
    }
}

/**
 * @brief Helper function to check if a move is valid.
 *
 * This method checks if the move is valid by verifying if the field is
 * empty and if the opponent's tokens can be flipped according to Reversi
 * rules.
 *
 * @param xPosition Row position of the move.
 * @param yPosition Column position of the move.
 * @param player The current player making the move.
 *
 * @return True if the move is valid and opponent tokens can be flipped;
 * false otherwise.
 */
bool ReversiBoard::isValidMove(int xPosition, int yPosition,
		BoardState player){
    // Condition 1: The token position should be an empty field
    if(board[xPosition][yPosition] != EMPTY){
        return false;
    }

    // Declaring 2D array for 8 possible move directions
    int directionArray[8][2] = {
        {1, 0},   // Right
        {-1, 0},  // Left
        {0, 1},   // Down
        {0, -1},  // Up
        {1, 1},   // Diagonal Down Right
        {-1, -1}, // Diagonal Up Left
        {-1, 1},  // Diagonal Down Left
        {1, -1}   // Diagonal Up Right
    };

    // Assign opponent using ternary operations
    BoardState opponentPlayer = (player == PLAYER1) ? PLAYER2 : PLAYER1;

    bool flipOccurred = false;

    // Looping through 8 possible directions
    for (int i = 0; i < 8; i++) {
        int dx = directionArray[i][0]; // Change in x-direction
        int dy = directionArray[i][1]; // Change in y-direction
        int xNewPosition = xPosition + dx;
        int yNewPosition = yPosition + dy;

        // Temporary list to store opponent tokens to flip
        vector<pair<int, int>> tokensToFlip;

        // Moving until we hit boundary or encounter a piece we cannot flip
        while (xNewPosition >= 0 && xNewPosition < rows &&
               yNewPosition >= 0 && yNewPosition < columns) {
            if (board[xNewPosition][yNewPosition] == opponentPlayer) {
                // Discovered an opponent piece
                tokensToFlip.push_back({xNewPosition, yNewPosition});
            }
            else if (board[xNewPosition][yNewPosition] == player) {
                // Found a player piece, flip opponent tokens if possible
                if (!tokensToFlip.empty()) {
                    // Flip opponent pieces in the direction
                    for (size_t j = 0; j < tokensToFlip.size(); j++) {
                        int oppX = tokensToFlip[j].first;
                        int oppY = tokensToFlip[j].second;
                        board[oppX][oppY] = player; // Flip opponent token
                    }
                    flipOccurred = true; // A flip occurred
                }
                break; // Found player piece, end this direction search
            }
            else {
                break; // Found empty field, break the search
            }

            // Move further in the current direction
            xNewPosition = xNewPosition + dx; // Move horizontally
            yNewPosition = yNewPosition + dy; // Move vertically
        }
    }

    return flipOccurred; // False for invalid move, true if flip occurred
}

/**
 * @brief Method to check if the game is over.
 *
 * This method checks if the board is full and no valid moves are available.
 *
 * @return True if the game is over; false otherwise.
 */
bool ReversiBoard::gameOver(){
    // Condition: Board is full and no valid moves available
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if (board[i][j] == EMPTY){
                return false; // Game not over, board is not full
            }
        }
    }
    return true; // Game over
}

/**
 * @brief Method to determine the winner of the game.
 *
 * This method counts the number of tokens for each player and determines
 * the winner based on the number of tokens, or declares a draw if the
 * counts are equal.
 */
void ReversiBoard::gameWinner(){
    int player1Count = 0;
    int player2Count = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if (board[i][j] == PLAYER1){
                player1Count++;
            } else if(board[i][j] == PLAYER2){
                player2Count++;
            }
        }
    }
    if(player1Count > player2Count){
        cout << "Player 1 is the Winner" << endl;
    } else if(player1Count < player2Count){
        cout << "Player 2 is the Winner" << endl;
    } else{
        cout << "It's a Draw" << endl;
    }
}
