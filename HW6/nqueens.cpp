

#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <array>

#include<bits/stdc++.h>

using namespace std;


int board[100][100];

void printBoard(int n)
{
    static int k = 1;
    printf("%d-\n",k++);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}


bool isLegalPosition(int *queenRank, int boardSize)
{
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

int* nextLegalPosition(int *queenRank, int boardSize)
{


  int* queenRankCopy = new int[boardSize];

  for (int i=0; i<boardSize; i++){

    queenRankCopy[i] = queenRank[i];

  }

  if (queenRank[boardSize-1] == -1 && isLegalPosition(queenRank, boardSize)){

  cout<<"partial legal "<<endl;

  for (int i=0; i<boardSize; i++){

      if (queenRank[i] == -1){

          for (int j=0; j<boardSize; j++){

              queenRankCopy[i] = j;

              if (isLegalPosition(queenRankCopy, boardSize)){

                queenRank[i] = j;

                return queenRank;
              }

              // else{
                  queenRankCopy[i] = -1;
          //}
          }
      }

    }
  }

    if (!isLegalPosition(queenRank, boardSize)){

      cout<<"given board illegal "<<endl;
      int* newPos = new int[boardSize];

      int* newPosCopy = new int[boardSize];

      for (int i=0; i<boardSize; i++){

        newPos[i] = -1;

        newPosCopy[i] = -1;

      }


      for (int i=boardSize-1; i>=0; i--){

        newPos[i] = queenRank[i];

        newPosCopy[i] = queenRank[i];

        if (isLegalPosition(newPos, boardSize)){

          continue;

        }

        for (int j=boardSize-1; j>=0; j--){

          newPosCopy[i] = j;

          if (isLegalPosition(newPosCopy, boardSize)){

            newPos[i] = newPosCopy[i];

            queenRank[i] = newPos[i];

          }

          newPosCopy[i] = queenRank[i];

        }

        if (isLegalPosition(queenRank, boardSize))
          return queenRank;

      }

    }

    if (isLegalPosition(queenRank, boardSize) && queenRank[boardSize-1] != -1){

      cout<<"filled all the way "<<endl;
      int* newRank = new int[boardSize];

      // int* newPosCopy = new int[boardSize];

      // int new_pos = 0;

      for (int i=0; i<boardSize; i++){

        newRank[i] = queenRank[i];

        // newPosCopy[i] = queenRank[i];

      }

      for (int i=boardSize-1; i>=0; i--){

        for (int j=boardSize-1; j>=0; j--){

            if (queenRank[i] != j){

              newRank[i] = j;
              if (isLegalPosition(newRank, boardSize)){
                queenRank[i] = newRank[i];
                cout<<"Found a legal position for "<<i+1<<" "<<j+1<<endl;
                break;
              }
              else{
                  // queenRank[i] = -1;
                  newRank[i] = -1;
              }

            }

        }

      }

    }

  return queenRank;

}


bool isLegal(int n, int row, int col)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;

    for (i=row, j=col; j>=0 && i<n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool allSolutions(int n, int col)
{
    if (col == n)
    {
        printBoard(n);
        return true;
    }

    bool res = false;
    for (int i = 0; i < n; i++)
    {
        if ( isLegal(n, i, col) )
        {

            board[i][col] = 1;

            res = allSolutions(n, col + 1) || res;

            board[i][col] = 0;
        }
    }

    return res;
}

void backtrackAll(int n)
{
    memset(board, 0, sizeof(board));

    if (allSolutions(n, 0) == false)
    {
        printf("Solution does not exist");
        return ;
    }

    return ;
}

int main()
{
    // int boardSize;
    // int queenPositions;
    // cout << "How big is the board?" << endl;
    // cin >> boardSize;
    //
    // int* queenRank = new int[boardSize];
    //
    // cout << "Enter the positions for the queens from 1 to board size and enter -1 if you would like it to be a partial board" << endl;
    // int breakLoc = 0;
    // for(int i =0; i < boardSize;i++){
    //     cin >> queenPositions;
    //     if(queenPositions == -1){
    //         breakLoc = i;
    //         break;
    //     }else if(queenPositions < 1 || queenPositions > boardSize){
    //         cout << "Error not valid input please try again" << endl;
    //         i = i-1;
    //     }
    //     else {
    //         queenRank[i] =queenPositions-1;
    //     }
    // }
    // if(breakLoc != 0){
    //     for(int i =breakLoc; i < boardSize; i++){
    //         queenRank[i]= -1;
    //     }
    // }
    //
    // bool status = isLegalPosition(queenRank, boardSize);
    // cout<<"board legal status "<<status<<endl;
    //
    // for (int i=0; i<boardSize; i++){
    //   cout<<queenRank[i]<<" ";
    // }
    //
    // cout<<endl;
    //
    // int* nextQueenPos = nextLegalPosition(queenRank, boardSize);
    // cout<<"Next legal position"<<endl;
    // for (int i=0; i<boardSize; i++){
    //   cout<<nextQueenPos[i]+1<<" ";
    // }
      int n;
      cout<<"Enter board size ";
      cin>>n;


      backtrackAll(n);
        return 1;
}
