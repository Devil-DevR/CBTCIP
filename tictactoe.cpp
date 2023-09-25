#include <iostream>
using namespace std;

void initializeBoard(char arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = ' ';
        }
    }
}

void displayBoard(char arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        cout << "|";
        for (int j = 0; j < 3; j++) {
            cout << " " << arr[i][j] << " |";
        }
        cout << endl;
        for (int j = 0; j < 3; j++) {
            cout << "----";
        }
        cout << endl;
    }
}

bool isPositionValid(char arr[3][3], int temp) {
    
    return (temp >= 1 && temp <= 9 && arr[(temp - 1) / 3][(temp - 1) % 3] == ' ');
}

void move(char sign, char arr[3][3]) {
    int temp;
    do {
        
        cout << "Choose Position (1-9): ";
        cin >> temp;if(!isPositionValid(arr, temp)){cout<<"\nInvalid input Choose Again \n\n";}
    } while (!isPositionValid(arr, temp));

    arr[(temp - 1) / 3][(temp - 1) % 3] = sign;
}

bool checkDraw(char arr[3][3]) {
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] == ' ') {
                return false; 
            }
        }
    }
    return true; 
}
bool checkWin(char board[3][3], char player)
{

    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
        {
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return true;
    }

    return false;
}



int main() {
    char arr[3][3];
    initializeBoard(arr);
    displayBoard(arr);
    int count = 0;

    do {
        if (count % 2 == 0) {
            cout << "\n Player X:";
            move('X', arr);
        } else {
            cout << "\n Player O:";
            move('O', arr);
        }

        displayBoard(arr);

        if (checkWin(arr, 'X')) {
            cout << "\nPlayer X wins!!!\n\n Thanks for Playing!!";
            break;
        } else if (checkWin(arr, 'O')) {
            cout << "\nPlayer O wins!!!\n\n Thanks for Playing!!";
            break;
        }

        count++;
        
        if (count == 9 && !checkWin(arr, 'X') && !checkWin(arr, 'O')) {
            cout << "\nThe game is a draw!\n\n Thanks for Playing!!";
        }

    } while (count < 9);

    return 0;
}
