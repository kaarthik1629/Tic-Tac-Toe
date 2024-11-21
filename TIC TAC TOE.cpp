// TIC TAC TOE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>


using namespace std;

const int BOARD_SIZE = 3;
vector<vector<char>> board(BOARD_SIZE, vector<char>(BOARD_SIZE, ' '));



void displayBoard()
{
    cout << "TIC TAC TOE Board \n";
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            cout << board[i][j];
            if (j < BOARD_SIZE - 1)
            
                cout << " | ";
        }
            
            cout << "\n";
         if (i < BOARD_SIZE - 1)
        
            cout << "--|---|--\n";
        
    }
}

void MakeMove(char player)
{
    int row, col;
    bool isValid = false;

    while (!isValid)
    {
        cout << "Player " << player << ",enter row and column (0-2): ";
        cin >> row >> col;

        if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ')
        {
            board[row][col] = player;
            isValid = true;
        }
        else {
            cout << "Invalid move. Try again.\n";
        }



    }


}
bool checkWin(char player)
{
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true;
        }
    }
    for (int j = 0; j < BOARD_SIZE; ++j)
    {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
        {
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return true;
    }

    return false;

}
int main()
{
    char  currentPlayer = 'X';
    for (int turn = 0; turn < BOARD_SIZE * BOARD_SIZE; ++turn)
    {
        displayBoard();
        MakeMove(currentPlayer);

        if (checkWin(currentPlayer))
        {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            return 0;
        }


        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    cout << "It's a draw!\n";
    displayBoard();
        return 0;
}



