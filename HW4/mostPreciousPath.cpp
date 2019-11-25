#include <iostream>
#include <vector>
#include<algorithm>
#include <bits/stdc++.h>

using namespace std;

#define ROWS 7
#define COLS 7

struct Coordinate{
  int i;
  int j;
  Coordinate(int i, int j) : i(i), j(j) {}
};

int gems[][8] = {
                  {79, 71, 18, 20, 34, 51, 93, 65},
                  {73, 38, 24, 49, 18, 6, 40, 74},
                  {31, 5, 63, 10, 32, 40, 14, 13},
                  {13, 78, 48, 19, 78, 11, 90, 94},
                  {22, 93, 68, 11, 56, 63, 49, 35},
                  {85, 52, 27, 5, 94, 91, 82, 62},
                  {46, 23, 99, 77, 10, 42, 1, 72},
                  {89, 70, 73, 83, 90, 22, 44, 92}
                };

int gems_copy[][8] = {
                  {79, 71, 18, 20, 34, 51, 93, 65},
                  {73, 38, 24, 49, 18, 6, 40, 74},
                  {31, 5, 63, 10, 32, 40, 14, 13},
                  {13, 78, 48, 19, 78, 11, 90, 94},
                  {22, 93, 68, 11, 56, 63, 49, 35},
                  {85, 52, 27, 5, 94, 91, 82, 62},
                  {46, 23, 99, 77, 10, 42, 1, 72},
                  {89, 70, 73, 83, 90, 22, 44, 92}
                };

/* Returns legal neighbors of a given cell */
vector<vector<int> > neighbors(int i, int j){

    vector<int> index;
    vector<vector<int> > pair;

    //if cell is left edge: i+1, j; i+1, j+1
    if (j==0 && i<=ROWS){
      index.push_back(i-1);
      index.push_back(j);
      pair.push_back(index);
      index.clear();

      index.push_back(i-1);
      index.push_back(j+1);
      pair.push_back(index);
      index.clear();
    }
    //if cell is right edge: i+1, j; i+1,j-1
    else if (j==COLS && i<=ROWS){
      index.push_back(i-1);
      index.push_back(j);
      pair.push_back(index);
      index.clear();

      index.push_back(i-1);
      index.push_back(j-1);
      pair.push_back(index);
      index.clear();
    }

    //not edge cell: i+1, j; i+1, j+1; i+1, j-1
    else if (i>=0 && i<=ROWS && j>=1 && j<=COLS-1){
      index.push_back(i-1);
      index.push_back(j);
      pair.push_back(index);
      index.clear();

      index.push_back(i-1);
      index.push_back(j-1);
      pair.push_back(index);
      index.clear();

      index.push_back(i-1);
      index.push_back(j+1);
      pair.push_back(index);
      index.clear();
    }
    //out of bounds values or last row
    else{
      cout<<"No neighbors \n";
      return pair;
    }

    return pair;
}

Coordinate max_neighbor (vector<vector<int> > neighbor){
int i=0;

Coordinate max_coor = {neighbor.at(i)[0], neighbor.at(i)[1]};

  while (i < neighbor.size()){
    if (gems[neighbor.at(i)[0]][neighbor.at(i)[1]] > gems[max_coor.i][max_coor.j]){
      max_coor.i = neighbor.at(i)[0];
      max_coor.j = neighbor.at(i)[1];
    }
    i++;
  }
return max_coor;

}

/* For each node, we  */
vector<int> preciousPath (){

    cout<<"preciousPath"<<endl;
    vector<int> row_sums;


    // for (int i=0; i<=COLS; i++){
    //   row_sums.push_back(gems[1][i]);
    //   cout<<row_sums[i]<<" ";
    // }
    //
    for (int i=0; i<=COLS; i++){
      cout<<gems_copy[0][i]<<" ";
    }
    cout<<endl;

    for (int i=1; i<=ROWS; i++){

      for (int j=0; j<=COLS; j++){
        vector<vector<int> > walkable_cells = neighbors(i, j);
        Coordinate max_coor = max_neighbor(walkable_cells);
        // row_sums.at(j) += gems[max_coor.i][max_coor.j];
        gems_copy[i][j] += gems_copy[max_coor.i][max_coor.j];

        cout<<gems_copy[i][j]<<" ";
      }

      cout<<endl;
    }




    return row_sums;

}

int main(){

  /* Test neighbor function */
  // int i=0, j=0;
  // cout<<"Neighbors of 0,1 "<<endl;
  // vector<vector<int> > index = neighbors(7,7);
  // for (i=0; i<index.size(); i++){
  //   for (j=0; j<index[i].size(); j++){
  //     cout<<index[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  // Coordinate max_coor = max_neighbor(index);
  // cout<<"Max neigbor is "<<max_coor.i<<", "<<max_coor.j<<endl;
  // cout<<"Gems at max neighbor is "<<gems[max_coor.i][max_coor.j]<<endl;
  //
  // int row, col;
  // while (index.size()!=0){
  //     row = index.back()[0];
  //     col = index.back()[1];
  //     cout<<gems[row][col]<<endl;
  //     index.pop_back();
  // }
  //
  vector <int> all_sums = preciousPath();

  return 0;
}
