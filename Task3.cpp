#include <bits/stdc++.h>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE];
char currentPlayer;

void initializeBoard()
{


    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            board[i][j] = '1' + i * SIZE + j; // Fill with numbers 1-9
        }
    }
    currentPlayer = 'X'; // First player gets X
}

void displayBoard()
{
    cout << "\n";
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            cout << board[i][j];


            if (j < SIZE - 1)
                cout << " | "; // For the boundaries of each box in 3*3 matrix
        }
        cout << "\n";
        if (i < SIZE - 1)
            cout << "--+---+--\n"; // For the boundaries of each box in 3*3 matrix
    }
    cout << "\n";
}

bool isWinner()
{

    for (int i = 0; i < SIZE; ++i) // Check rows and columns
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }



    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) // Check diagonals
        return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;
    return false;
}

bool isDraw()
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O') // checking that any box is not not occupied by 'X' or 'O' if not the game is drawn
            {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer()
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // if current player is 'X' then next player is 'O' and vice versa
}

bool makeMove(int position)
{
    int row = (position - 1) / SIZE;
    int col = (position - 1) % SIZE;
    
    if (board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = currentPlayer; // rewriting the symbol from a number to 'X' or 'O'
        return true;
    }
    return false;
}

int main()
{
    char playAgain;
    do
    {
        initializeBoard();
        displayBoard();
        bool gameEnd = false;

        while (!gameEnd)
        {
            int move;
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;

            if (move < 1 || move > 9 || !makeMove(move))
            {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            displayBoard();

            if (isWinner()) // winner is printed
            {
                cout << "Player " << currentPlayer << " wins!\n";
                gameEnd = true;
            }
            else if (isDraw()) // if game became draw
            {
                cout << "It's a draw!\n";
                gameEnd = true;
            }
            else
            {
                switchPlayer();
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y'); // To start again a new game

    return 0;
}
