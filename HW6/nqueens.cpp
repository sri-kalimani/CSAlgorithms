

#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <array>

using namespace std;
bool solFound = false;
bool isLegalPosition(int *queenRank, int boardSize);
void printBoard(int *queenRank, int boardSize)
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            queenRank[i] == j ? cout << "1 " : cout << "0 ";
        }
        cout << endl;
    }
}

bool successor(int *queenRank, int boardSize, int row)
{
    int intialValue = queenRank[row];
    for (int i = queenRank[row] + 1; i < boardSize; i++)
    {
        queenRank[row] = i;
        if (isLegalPosition(queenRank, boardSize))
        {
            cout << "gets here with the value being" << i << endl;
            return 1;
        }
    }
    queenRank[row] = intialValue;
    return 0;
}

bool isLegalPosition(int *queenRank, int boardSize)
{
    cout << "Breaks on print board" << endl;
    fflush(stdout);
    int board[boardSize][boardSize]; // create the board
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            board[i][j] = 0;
        }
    }

    for (int i = 0; i < boardSize; i++)
    {
        if (queenRank[i] != -1)
        {                               // -1 means leave that row blank
            board[i][queenRank[i]] = 1; // put a 1 in each row at the correct rank
        }
    }

    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            if (board[i][j] == 1)
            { // check every queen
                int k, l;

                for (k = (i + 1), l = (j + 1); k < boardSize && l < boardSize; k++, l++)
                {
                    if (board[k][l] == 1)
                    {
                        return false;
                    }
                }
                for (k = (i + 1), l = (j - 1); k < boardSize && l >= 0; k++, l--)
                {
                    if (board[k][l] == 1)
                    {
                        return false;
                    }
                }
                for (k = (i + 1); k < boardSize; k++)
                {
                    if (board[k][j] == 1)
                    {
                        return false;
                    }
                }
                for (l = (j + 1); l < boardSize; l++)
                {
                    if (board[i][l] == 1)
                    {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

bool nextLegalPosition(int *queenRank, int boardSize)
{
    int currentRow = 0;

    for (int i = boardSize - 1; i >= 0; i--)
    {
        cout << queenRank[i] << endl;
        if (queenRank[i] >= 0 && currentRow < i)
        {
            currentRow = i + 1;
            break;
        }
    }
    cout << currentRow << endl;
    cout << boardSize << endl;
    if (currentRow == boardSize)
    {
        if (isLegalPosition(queenRank, boardSize) && !solFound)
        {
            solFound = true;
            return 1;
        }
    }
    if (successor(queenRank, boardSize, currentRow))
    {
        return true;
    }
    else
    {
        queenRank[currentRow] = -1;
        return nextLegalPosition(queenRank, boardSize);
    }
    return false;
}
void findFirstSol(int n)
{
    int solution = 1;
    for (int i = 4; i < n; i++)
    {
        int *queenRank = new int[i];
        for (int j = 0; j < i; j++)
        {
            queenRank[j] = -1;
        }
        solution = 1;
        while (solution)
        {
            isLegalPosition(queenRank, i);
            if (solFound)
            {
                solution = 0;
            }
        }
        for (int j = 0; j < i; j++)
        {
            cout << queenRank[j] << endl;
        }
        free(queenRank);
    }
}
int main()
{
    int boardSize;
    int queenPositions;
    int solution = 1;
    cout << "How big is the board?" << endl;
    cin >> boardSize;

    int *queenRank = new int[boardSize];

    cout << "Enter the positions for the queens from 1 to board size and enter -1 if you would like it to be a partial board" << endl;
    int breakLoc = 0;
    for (int i = 0; i < boardSize; i++)
    {
        cin >> queenPositions;
        if (queenPositions == -1)
        {
            breakLoc = i;
            break;
        }
        else if (queenPositions < 1 || queenPositions > boardSize)
        {
            cout << "Error not valid input please try again" << endl;
            i = i - 1;
        }
        else
        {
            queenRank[i] = queenPositions - 1;
        }
    }
    if (breakLoc != 0)
    {
        for (int i = breakLoc; i < boardSize; i++)
        {
            queenRank[i] = -1;
        }
    }

    printBoard(queenRank, boardSize);
    cout << nextLegalPosition(queenRank, boardSize) << endl;
    printBoard(queenRank, boardSize);
    cout << isLegalPosition(queenRank, boardSize) << endl;

    return 1;
}