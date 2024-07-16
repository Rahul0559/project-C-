#include <iostream>
using namespace std;

int space[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

string n1;
string n2;
int row;
int column;
char token = 'x'; // Start with player 1 ('x')
bool tie = false; // Initialize tie to false

void fun1() {
    cout << "Enter the name of the first player: " << endl;
    cin >> n1;
    cout << "Enter the name of the Second player: " << endl;
    cin >> n2;
    cout << n1 << " is player 1 so he/she will play first" << endl;
    cout << n2 << " is player 2 so he/she will play second" << endl;

    cout << "    |     |     \n";
    cout << "  " << space[0][0] << " |  " << space[0][1] << "  | " << space[0][2] << endl;
    cout << "____|_____|_____\n";
    cout << "    |     |     \n";
    cout << "  " << space[1][0] << " |  " << space[1][1] << "  | " << space[1][2] << endl;
    cout << "____|_____|_____\n";
    cout << "    |     |     \n";
    cout << "  " << space[2][0] << " |  " << space[2][1] << "  | " << space[2][2] << endl;
    cout << "    |     |     \n";
}

void fun2() {
    int digit;

    if (token == 'x') {
        cout << n1 << " please Enter: " << endl;
        cin >> digit;
    } else if (token == '0') {
        cout << n2 << " please Enter: " << endl;
        cin >> digit;
    }

    if (digit == 1) {
        row = 0;
        column = 0;
    } else if (digit == 2) {
        row = 0;
        column = 1;
    } else if (digit == 3) {
        row = 0;
        column = 2;
    } else if (digit == 4) {
        row = 1;
        column = 0;
    } else if (digit == 5) {
        row = 1;
        column = 1;
    } else if (digit == 6) {
        row = 1;
        column = 2;
    } else if (digit == 7) {
        row = 2;
        column = 0;
    } else if (digit == 8) {
        row = 2;
        column = 1;
    } else if (digit == 9) {
        row = 2;
        column = 2;
    } else {
        cout << "Invalid input! " << endl;
        fun2(); // Ask for input again if it's invalid
        return; // Exit the function after recursion
    }

    if (space[row][column] != 'x' && space[row][column] != '0') {
        if (token == 'x') {
            space[row][column] = 'x';
            token = '0';
        } else {
            space[row][column] = '0';
            token = 'x';
        }
    } else {
        cout << "That space is already taken!" << endl;
        fun2(); // Ask for input again if space is taken
    }
}

bool fun3() {
    for (int i = 0; i < 3; i++) {
        if ((space[i][0] == space[i][1] && space[i][0] == space[i][2]) ||
            (space[0][i] == space[1][i] && space[0][i] == space[2][i])) {
            return true;
        }
    }
    if ((space[0][0] == space[1][1] && space[1][1] == space[2][2]) ||
        (space[0][2] == space[1][1] && space[1][1] == space[2][0])) {
        return true;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'x' && space[i][j] != '0') {
                return false;
            }
        }
    }
    tie = true; // Set tie to true if all spaces are filled
    return true;
}

int main() {
    while (!fun3()) {
        fun1();
        fun2();
    }

    if (token == 'x' && !tie) {
        cout << n1 << " wins! " << endl;
    } else if (token == '0' && !tie) {
        cout << n2 << " wins! " << endl;
    } else {
        cout << "It's a draw!" << endl;
    }

    return 0;
}
