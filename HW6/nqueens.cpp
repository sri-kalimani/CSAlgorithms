

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

int* successor(int *queenRank, int boardSize)
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

    return queenRank;
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


      for (int i=0; i<boardSize; i++){

        newPos[i] = queenRank[i];

        newPosCopy[i] = queenRank[i];

        if (isLegalPosition(newPos, boardSize)){

          continue;

        }

        for (int j=0; j<boardSize; j++){

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

    bool status = isLegalPosition(queenRank, boardSize);
    cout<<"board legal status "<<status<<endl;

    for (int i=0; i<boardSize; i++){
      cout<<queenRank[i]<<" ";
    }

    cout<<endl;

    int* nextQueenPos = nextLegalPosition(queenRank, boardSize);
    cout<<"Next legal position"<<endl;
    for (int i=0; i<boardSize; i++){
      cout<<nextQueenPos[i]+1<<" ";
    }


        return 1;
}
