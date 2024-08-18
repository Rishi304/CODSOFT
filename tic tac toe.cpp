#include <iostream>

using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}};

char currentMarker;
int currentPlayer;

void drawBoard()
{
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool placeMarker(int slot)
{
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = currentMarker;
        return true;
    }
    else
    {
        return false;
    }
}

int checkWinner()
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return currentPlayer;
    }
    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return currentPlayer;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return currentPlayer;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return currentPlayer;

    return 0;
}

void swapPlayerAndMarker()
{
    if (currentMarker == 'X')
        currentMarker = 'O';
    else
        currentMarker = 'X';

    if (currentPlayer == 1)
        currentPlayer = 2;
    else
        currentPlayer = 1;
}

int main()
{
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "Player 1, choose your marker (X or O): ";
    char markerP1;
    cin >> markerP1;

    currentPlayer = 1;
    currentMarker = markerP1;

    drawBoard();

    int winner = 0;
    int slot;

    for (int i = 0; i < 9; i++)
    {
        cout << "It's Player " << currentPlayer << "'s turn. Enter your slot: ";
        cin >> slot;

        if (slot < 1 || slot > 9)
        {
            cout << "Invalid slot! Please choose a slot between 1 and 9." << endl;
            i--;
            continue;
        }

        if (!placeMarker(slot))
        {
            cout << "Slot already taken! Try again." << endl;
            i--;
            continue;
        }

        drawBoard();

        winner = checkWinner();
        if (winner != 0)
        {
            cout << "Player " << winner << " wins!" << endl;
            break;
        }

        swapPlayerAndMarker();
    }

    if (winner == 0)
        cout << "It's a tie!" << endl;

    return 0;
}
