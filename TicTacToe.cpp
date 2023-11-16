#include <iostream>
using namespace std;

void displayBoard(char Board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << Board[i][j];
            if (j < 2) {
                cout << '|';
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "------\n";
        }
    }
}

bool checkIfLegal(int userInput, char Board[3][3]) {
    if (userInput >= 1 && userInput <= 9) {
        int posX = (userInput - 1) / 3;
        int posY = (userInput - 1) % 3;
        return Board[posX][posY] == ' ';
    }
    else {
        return false;
    }
}

bool checkForDraw(char Board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (Board[i][j] == ' ') {
                return false; // If any empty space is found, the game is not a draw
            }
        }
    }
    return true; // All spaces are filled, indicating a draw
} 

bool checkForWin(char Board[3][3]) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (Board[i][0] == Board[i][1] && Board[i][1] == Board[i][2] && Board[i][0] != ' ') {
            return true; // Row win
        }
        if (Board[0][i] == Board[1][i] && Board[1][i] == Board[2][i] && Board[0][i] != ' ') {
            return true; // Column win
        }
    }

    // Check diagonals
    if (Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2] && Board[0][0] != ' ') {
        return true; // Diagonal win (top-left to bottom-right)
    }
    if (Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0] && Board[0][2] != ' ') {
        return true; // Diagonal win (top-right to bottom-left)
    }

    return false; // No win
}

void update(char Board[3][3], char currentPlayer) {
    int userInput;
    cout << "Player " << currentPlayer << ", enter your move (1-9): ";
    cin >> userInput;

    if (checkIfLegal(userInput, Board)) {
        int posX = (userInput - 1) / 3;
        int posY = (userInput - 1) % 3;
        Board[posX][posY] = currentPlayer;
    }
    else {
        cout << "Invalid move. Try again.\n";
        update(Board, currentPlayer);
    }
}

int main() {
    char Board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    char currentPlayer = 'X';
    cout << "Welcome to Tic Tac Toe, " << currentPlayer << " starts!\n";

    while (true) {
        displayBoard(Board);
        update(Board, currentPlayer);

        if (checkForWin(Board)) {
            displayBoard(Board);
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        if (checkForDraw(Board)) {
            displayBoard(Board);
            cout << "It's a draw!\n";
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch players
    }

    return 0;
}
