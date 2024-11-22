# Reversi Game

This project implements a command-line version of the classic Reversi (Othello) game. Two players alternate turns to place tokens on a board, attempting to capture their opponent's pieces by flanking them.

## Project Structure

### Classes

#### **ReversiBoard**
- **Description**: Handles the core game logic, including board setup, move validation, and token flipping.
- **Methods**:
  - `initializeBoard()`: Initializes the board with the starting positions.
  - `isValidMove(int x, int y, char player)`: Validates the player's move.
  - `makeMove(int x, int y, char player)`: Makes the move and flips opponent tokens if valid.
  - `flipTokens(int x, int y, char player)`: Flips the opponent's pieces after a valid move.
  - `printBoard()`: Displays the current state of the board.
  - `isGameOver()`: Checks if the game has ended (no valid moves left or board full).
  - `getWinner()`: Determines the winner based on the number of pieces on the board.

#### **ReversiConsoleView**
- **Description**: Responsible for displaying the game board and interacting with the user.
- **Methods**:
  - `printBoard(const char board[8][8])`: Prints the board to the console.
  - `getInput()`: Prompts the player to enter a move (x, y).
  - `displayMessage(string message)`: Displays messages to the player (e.g., invalid moves, winner announcements).

## Basic Functionality

- **Game Setup**: The game initializes with an 8x8 board, setting the tokens to their default starting positions.
- **Gameplay**: Players take turns to provide coordinates (x, y) for their moves. The game checks if the move is valid, updates the board, and flips any opponent tokens as necessary.
- **Winning Condition**: The game ends when there are no valid moves or the board is full. The player with the most tokens on the board wins.
- **Turn System**: Player 1 uses 'x' and Player 2 uses 'o'. The players alternate turns to make moves.

## License

This project is licensed under the MIT License.
