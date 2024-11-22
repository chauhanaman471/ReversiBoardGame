/**
 * @file ReversiConsoleView.h
 * @brief Header file for ReversiConsoleView class.
 *
 * This file contains the declaration of the ReversiConsoleView class which
 * is responsible for displaying the state of the Reversi game board.
 * It holds a pointer to a ReversiBoard instance and provides a method
 * to print the current state of the board.
 *
 *  @date 5 Nov 2024
 *  @author Aman Chauhan
 *  @details Master Student at HDA (Matriculation number: 1127928)
 */

#ifndef REVERSICONSOLEVIEW_H_
#define REVERSICONSOLEVIEW_H_

#include "ReversiBoard.h"

/**
 * @class ReversiConsoleView
 * @brief Class responsible for displaying board on the console..
 *
 * The ReversiConsoleView class provides methods to print the game board
 * and interact with the ReversiBoard instance to visualize the game state.
 */
class ReversiConsoleView{
private:
    /** Pointer to a ReversiBoard instance to access its methods and data. */
    ReversiBoard *boardPointer;

public:
    /**
     * @brief Constructor to initialize the ReversiConsoleView with a board.
     * @param board Pointer to an instance of ReversiBoard.
     */
    ReversiConsoleView(ReversiBoard *board);

    /**
     * @brief Method to print the current game board to the console.
     */
    void print();
};

#endif /* REVERSICONSOLEVIEW_H_ */
