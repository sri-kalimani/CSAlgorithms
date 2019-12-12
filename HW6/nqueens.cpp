

#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <array>

using namespace std;

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

void successor(int *queenRank, int boardSize)
{
    for (int i = 0; i < boardSize; i++)
    {
        if (queenRank[i] == -1)
        {
            for (int j = 0; j < boardSize; j++)
            {
                if (find(queenRank, queenRank + i, j) == (queenRank + i))
                {
                    queenRank[i] = j;
                    break;
                }
            }
            break;
        }
    }
}

bool isLegalPosition(int *queenRank, int boardSize)
{
    int board[boardSize][boardSize]; // create the board
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            board[i][j] = 0;
            // cout<<board[i][j]<<" ";
        }
        // cout<<endl;
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
                        cout<<"diagonal taken"<<endl;
                        return false;
                    }
                }
                for (k = (i + 1); k < boardSize; k++)
                {
                    if (board[k][j] == 1)
                    {
                        cout<<"row taken"<<endl;
                        return false;
                    }
                }
                for (l = (j + 1); l < boardSize; l++)
                {
                    if (board[i][l] == 1)
                    {
                        cout<<"column taken"<<endl;
                        return false;
                    }
                }
            }
        }
    }

    cout<<"positions are fine"<<endl;
    return true;
}

void nextLegalPosition(int *queenRank, int boardSize)
{
}

int main()
{
    int boardSize;
    int queenPositions;
    cout << "How big is the board?" << endl;
    cin >> boardSize;

    int* queenRank = new int[boardSize];

    cout << "Enter the positions for the queens from 1 to board size and enter -1 if you would like it to be a partial board" << endl;
    int breakLoc = 0;
    for(int i =0; i < boardSize;i++){
        cin >> queenPositions;
        if(queenPositions == -1){
            breakLoc = i;
            break;
        }else if(queenPositions < 1 || queenPositions > boardSize){
            cout << "Error not valid input please try again" << endl;
            i = i-1;
        }
        else {
            queenRank[i] =queenPositions-1;
        }
    }
    if(breakLoc != 0){
        for(int i =breakLoc; i < boardSize; i++){
            queenRank[i]= -1;
        }
    }
    // for(int i =0;i < boardSize;i++){
    //     cout << queenRank[i] << endl;
    // }
    bool status = isLegalPosition(queenRank, boardSize);
    cout<<status;

        return 1;
}
