#include <iostream>
#include <vector>

// Function to print the game board
void printBoard(const std::vector<std::vector<char>> &board) {
    std::cout << "   0 1 2 3 4 5\n";
    for (int i = 0; i < 6; ++i) {
        std::cout << i << " |";
        for (int j = 0; j < 6; ++j) {
            std::cout << board[i][j] << '|';
        }
        std::cout << std::endl;
    }
}

// Function to check if a player has won
bool checkWin(const std::vector<std::vector<char>> &board, char player) {
    // Check rows
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == player && 
                board[i][j + 1] == player && 
                board[i][j + 2] == player && 
                board[i][j + 3] == player && 
                board[i][j + 4] == player) {
                return true;
            }
        }
    }

    // Check columns
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (board[i][j] == player && 
                board[i + 1][j] == player && 
                board[i + 2][j] == player && 
                board[i + 3][j] == player && 
                board[i + 4][j] == player) {
                return true;
            }
        }
    }

    // Check diagonals
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            // Check the diagonal from top-left to bottom-right
            if (board[i][j] == player && 
                board[i + 1][j + 1] == player && 
                board[i + 2][j + 2] == player && 
                board[i + 3][j + 3] == player &&
                board[i + 4][j + 4] == player) {
                return true;
            }
            // Check the diagonal from top-right to bottom-left
            if (board[i][j + 4] == player && 
                board[i + 1][j + 3] == player && 
                board[i + 2][j + 2] == player && 
                board[i + 3][j + 1] == player &&
                board[i + 4][j] == player) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::cout << "This is a Gomoku/Gobang game!\n";
    std::cout << "The board will be 6x6.\n\n";

    std::vector<std::vector<char>> board(6, std::vector<char>(6, '.'));

    printBoard(board);

    bool player1Turn = true; // Player 1 starts
    int moves = 0;

    while (true) {
        int row, col;
        char playerSymbol = (player1Turn) ? 'x' : 'o';

        std::cout << "Player " << ((player1Turn) ? "1" : "2") << " (" << playerSymbol << ") - Enter the coordinates of your move (row column): ";
        std::cin >> row >> col;

        // Check if the input is within the board range and the cell is empty
        if (row >= 0 && row < 6 && 
            col >= 0 && col < 6 && 
            board[row][col] == '.') {
            board[row][col] = playerSymbol;
            printBoard(board);
            ++moves;

            // Check if the current player has won
            if (checkWin(board, playerSymbol)) {
                std::cout << "\nPlayer " << ((player1Turn) ? "1" : "2") << " wins!" << std::endl;
                break;
            }

            // Check if the game is a draw
            if (moves == 36) {
                std::cout << "It's a draw!" << std::endl;
                break;
            }

            // Switch turns
            player1Turn = !player1Turn;
        } else {
            std::cout << "Invalid move! Try again." << std::endl;
        }
    }

    return 0;
}
