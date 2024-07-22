#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void printBoard() {
    cout << endl;
    cout << "--------------" << endl;
    cout << "| " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " | " << endl;
    cout << "----|---|----" << endl;
    cout << "| " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " | " << endl;
    cout << "----|---|----" << endl;
    cout << "| " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " | " << endl;
    cout << "--------------" << endl;
}

void marked(int position, char player) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;
    if (board[row][col] != 'x' && board[row][col] != 'o') {
        board[row][col] = player;
    }
}

bool isWinner(char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

bool game() {
    char player1, player2;
    int position;
    cout << "Tic tac toe " << endl;
    printBoard();
    cout << "It's player 1, choose the symbol (x or o): ";
    cin >> player1;
    if (player1 == 'x') {
        player2 = 'o';
    } else {
        player2 = 'x';
    }
    while (player1 != 'x' && player1 != 'o') {
        cout << "Invalid symbol, please enter x or o !" << endl;
        cin >> player1;
    }
    cout << "Player 1 is: " << player1 << endl;
    cout << "Player 2 is: " << player2 << endl;
    char currentPlayer = player1;
    for (int i = 0; i < 9; i++) {
        string player = (currentPlayer == player1) ? "player 1" : "player 2";
        cout << "It's " << player << " turn ,Choose the position: " << endl;
        cin >> position;
        marked(position, currentPlayer);
        printBoard();
        if (isWinner(currentPlayer)) {
            cout << player << "(" << currentPlayer << ") wins!" << endl;
            return true;
        }
        currentPlayer = (currentPlayer == player1) ? player2 : player1;
    }
    cout << "It's a draw!" << endl;
    return false;
}

void reset() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '1' + i * 3 + j;
        }
    }
}

int main() {
    char playAgain;
    do {
        reset();
        game();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
