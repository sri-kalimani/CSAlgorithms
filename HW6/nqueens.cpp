

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
            return 1;
        }
    }
    queenRank[row] = -1;
    return 0;
}

bool isLegalPosition(int *queenRank, int boardSize)
{
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
    //finds the current row
    for (int i = boardSize - 1; i >= 0; i--)
    {
        if (i == 0)
        {
            currentRow = 0;
            break;
        }
        if (queenRank[i] >= 0)
        {
            currentRow = i + 1;
            break;
        }
    }
    //sees if it's on the first row
    if (currentRow == 0)
    { //if it is not at the edge
        if (queenRank[0] != boardSize)
        {
            queenRank[0]++;
            successor(queenRank, boardSize, currentRow + 1);
        }
    }
    else
    {
        //if it is at the end and a legal position then it is a solution
        if (currentRow == boardSize - 1)
        {
            if (isLegalPosition(queenRank, boardSize) && !solFound)
            {
                solFound = true;
                return 1;
            }
        }
        //then it is at the edge of the board
        if (successor(queenRank, boardSize, currentRow))
        {
            return true;
        }
        else
        { //clear the row above it if it is at an edge
            if (queenRank[currentRow - 2] == boardSize - 1)
            {
                queenRank[currentRow - 2] = -1;
            } //if failing move back up
            queenRank[currentRow - 1] = -1;
            return nextLegalPosition(queenRank, boardSize);
        }
    }
    return false;
}
void findFirstSol(int n)
{
    int solution = 1;
    for (int i = 4; i < n; i++)
    {
        //makes a new board for each n
        int *queenRank = new int[i];
        solFound = 0;     //sets solution found
        queenRank[0] = 0; //sets the intial of the board to be 1 in the corner
        //sets the rest of the queenRank to 0
        for (int j = 1; j < i; j++)
        {
            queenRank[j] = -1;
        }
        //sets solution to be true while looping
        solution = 1;
        while (solution)
        { //calls next legal to fill up the board
            nextLegalPosition(queenRank, i);
            printBoard(queenRank, i);
            cout << endl;
            //exits if solution found
            if (solFound)
            {
                solution = 0;
            }
        }
        //outputs the solution
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
    int breakLoc = -1;
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
    if (breakLoc > 0)
    {
        for (int i = breakLoc; i < boardSize; i++)
        {
            queenRank[i] = -1;
        }
    }

    cout << nextLegalPosition(queenRank, boardSize) << endl;
    printBoard(queenRank, boardSize);
    cout << nextLegalPosition(queenRank, boardSize) << endl;
    printBoard(queenRank, boardSize);
    cout << nextLegalPosition(queenRank, boardSize) << endl;
    printBoard(queenRank, boardSize);
    cout << nextLegalPosition(queenRank, boardSize) << endl;
    printBoard(queenRank, boardSize);

    free(queenRank);
    findFirstSol(6);
    return 1;
}