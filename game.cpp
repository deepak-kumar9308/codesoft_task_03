// Tic-Tac-Toe game
// Made by Deepak kr
// Date: 15/05/2024
#include <iostream>
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}}; // char array for indicating
int row, column;
char token = 'X';
string n1, n2;
bool tie = false;

void functionOne() {
    cout << "   |   |   \n";
    cout << " " << space[0][0] << " | " << space[0][1] << " | " << space[0][2] << " \n";
    cout << "___|___|___\n";
    cout << "   |   |   \n";
    cout << " " << space[1][0] << " | " << space[1][1] << " | " << space[1][2] << " \n";
    cout << "___|___|___\n";
    cout << "   |   |   \n";
    cout << " " << space[2][0] << " | " << space[2][1] << " | " << space[2][2] << " \n";
    cout << "   |   |   \n";
}

void functionTwo() {
    int digit;
    if (token == 'X') {
        cout << n1 << ", please enter a number: ";
        cin >> digit;
    } else if (token == 'O') {
        cout << n2 << ", please enter a number: ";
        cin >> digit;
    }
    if (digit >= 1 && digit <= 9) {
        row = (digit - 1) / 3;
        column = (digit - 1) % 3;
    } else {
        cout << "Invalid input! Please enter a number between 1 and 9." << endl;
        functionTwo();
        return;
    }

    if (space[row][column] != 'X' && space[row][column] != 'O') {
        space[row][column] = token;
        token = (token == 'X') ? 'O' : 'X';
    } else {
        cout << "Space already taken! Try again." << endl;
        functionTwo();
    }
}

bool functionThree() {
    // Check rows and columns for a win
    for (int i = 0; i < 3; i++) {
        if ((space[i][0] == space[i][1] && space[i][1] == space[i][2]) || (space[0][i] == space[1][i] && space[1][i] == space[2][i])) {
            return false;
        }
    }
    // Check diagonals for a win
    if ((space[0][0] == space[1][1] && space[1][1] == space[2][2]) || (space[0][2] == space[1][1] && space[1][1] == space[2][0])) {
        return false;
    }
    // Check for any empty spaces
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'X' && space[i][j] != 'O') {
                return true;
            }
        }
    }
    tie = true;
    return false;
}

int main() {
    cout << "\nENTER THE NAME OF THE FIRST PLAYER: ";
    getline(cin, n1);
    cout << "\nENTER THE NAME OF THE SECOND PLAYER: ";
    getline(cin, n2);
    cout << n1 << " is player 1, so he/she will play first.\n";
    cout << n2 << " is player 2, so he/she will play second.\n";

    while (functionThree()) {
        functionOne();
        functionTwo();
    }
    functionOne(); // Display the final board
    if (tie) {
        cout << "It's a draw!" << endl;
    } else {
        if (token == 'O') { // Note: token is toggled after the last move
            cout << n1 << " wins!" << endl;
        } else {
            cout << n2 << " wins!" << endl;
        }
    }
    return 0;
}


