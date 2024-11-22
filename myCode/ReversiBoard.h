/**
 * @file ReversiBoard.h
 * @brief Defines the ReversiBoard class for the Reversi board game.
 *
 * This file contains the class definition for managing the Reversi game board.
 * It includes methods for setting up the board, querying and updating field
 * states, validating moves, checking game status, and determining the winner.
 *
 *  @date 5 Nov 2024
 *  @author Aman Chauhan
 *  @details Master Student at HDA (Matriculation number: 1127928)
 */

#ifndef REVERSIBOARD_H_
#define REVERSIBOARD_H_

#include <vector>
/**
 * @class ReversiBoard
 * @brief Manages the game board and game logic for Reversi.
 *
 * This class handles the creation and management of the Reversi game board.
 * It includes methods to check valid moves, update the board, determine the
 * game status, and find the winner.
 */
class ReversiBoard
{
private:
    /**
     * @enum BoardState
     * @brief Represents the state of a board cell.
     *
     * The cell can be EMPTY, occupied by PLAYER1, or occupied by PLAYER2.
     */
    enum BoardState {
        EMPTY,   ///< Represents an empty cell.
        PLAYER1, ///< Represents a cell occupied by Player 1 ('x').
        PLAYER2 ///< Represents a cell occupied by Player 2 ('o').
    };

    int rows;     ///< Number of rows on the board.
    int columns;  ///< Number of columns on the board.

    /**
     * @brief A 2D vector representing the board.
     *
     * Each element is of type BoardState, representing the state of each cell.
     */
    std::vector<std::vector<BoardState>> board;

    /**
     * @brief Helper Functon to Check if a token move is valid for a player.
     *
     * @param xPosition X-coordinate of the token move.
     * @param yPosition Y-coordinate of the token move.
     * @param player The player making the move (PLAYER1 or PLAYER2).
     * @return bool True if the move is valid, false otherwise.
     */
    bool isValidMove(int xPosition, int yPosition, BoardState player);

    // Declaring ReversiConsoleView as a friend class
    // to access private members of ReversiBoard class
    friend class ReversiConsoleView;

public:
    /**
     * @brief Constructs a ReversiBoard with the given dimensions.
     *
     * @param xDimension The number of rows for the board.
     * @param yDimension The number of columns for the board.
     */
    ReversiBoard(int xDimension, int yDimension);

    /**
     * @brief Queries the state of a specific cell on the board.
     *
     * @param xPosition X-coordinate of the cell.
     * @param yPosition Y-coordinate of the cell.
     */
    void getFieldState(int xPosition, int yPosition);

    /**
     * @brief Validates and updates the state of a specific cell.
     *
     * @param xPosition X-coordinate of the move.
     * @param yPosition Y-coordinate of the move.
     * @param tokenPiece The token ('x' or 'o') to place.
     * @return bool True if the move is valid and the board was updated.
     */
    bool setFieldState(int xPosition, int yPosition, char tokenPiece);

    /**
     * @brief Checks if the game is over (no valid moves or board is full).
     *
     * @return bool True if the game is over, false otherwise.
     */
    bool gameOver();

    /**
     * @brief Determines and prints the winner of the game.
     *
     * This method counts the tokens of each player and declares the winner.
     */
    void gameWinner();
};

#endif /* REVERSIBOARD_H_ */
