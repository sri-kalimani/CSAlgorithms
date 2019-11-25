#include <iostream>
#include <vector>
#include<algorithm>
#include <bits/stdc++.h>

using namespace std;

#define ROWS 7
#define COLS 7

struct Gem_data{
  int count;
  int i;
  int j;
  Gem_data(int count, int i, int j) : count(count), i(i), j(j) {}
};

struct Coordinate{
  int i;
  int j;
  Coordinate(int i, int j) : i(i), j(j) {}
};

struct max_sort
{
    inline bool operator() (const Gem_data& struct1, const Gem_data& struct2)
    {
        return (struct1.count < struct2.count);
    }
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

vector<Gem_data> gem_heap;
int gems_found = 0;


/* Returns legal neighbors of a given cell */
vector<vector<int> > neighbors(int i, int j){

    vector<int> index;
    vector<vector<int> > pair;

    //if cell is left edge: i+1, j; i+1, j+1
    if (j==0 && i<ROWS){
      index.push_back(i+1);
      index.push_back(j);
      pair.push_back(index);
      index.clear();

      index.push_back(i+1);
      index.push_back(j+1);
      pair.push_back(index);
      index.clear();
    }
    //if cell is right edge: i+1, j; i+1,j-1
    else if (j==COLS && i<ROWS){
      index.push_back(i+1);
      index.push_back(j);
      pair.push_back(index);
      index.clear();

      index.push_back(i+1);
      index.push_back(j-1);
      pair.push_back(index);
      index.clear();
    }

    //not edge cell: i+1, j; i+1, j+1; i+1, j-1
    else if (i>=0 && i<=ROWS-1 && j>=1 && j<=COLS-1){
      index.push_back(i+1);
      index.push_back(j);
      pair.push_back(index);
      index.clear();

      index.push_back(i+1);
      index.push_back(j+1);
      pair.push_back(index);
      index.clear();

      index.push_back(i+1);
      index.push_back(j-1);
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

Coordinate max_sum_row (vector<vector<int> > sums_row){
int i=0;

Coordinate max_coor = {sums_row.at(i)[0], sums_row.at(i)[1]};

  while (i < sums_row.size()){
    if (gems[sums_row.at(i)[0]][sums_row.at(i)[1]] > gems[max_coor.i][max_coor.j]){
      max_coor.i = sums_row.at(i)[0];
      max_coor.j = sums_row.at(i)[1];
    }
    i++;
  }
return max_coor;

}

/* For each node, we  */
vector<int> preciousPath (){
  // until last row
    // for each cell in row
      // sum = current_gems + gems_of_max_neighbor
      // save current_gems, gems_of_max_neighbor in path_so_far
    // max_sum = max of sum
    // update max_path with path_so_far

    int max_sum=0;
    vector<Coordinate> path_so_far, max_path;
    vector<int> sum;
    Coordinate max_coor = {0, 0};

    for (int i=0; i<ROWS; i++){
      for (int j=0; j<=COLS; j++){
        vector<vector<int> > index = neighbors(i,j);
        max_coor = max_neighbor(index);
        sum[j] += gems[i][j] + gems[max_coor.i][max_coor.j];
      }
      // max_sum = *max_element(sum.begin(), sum.end());
    }

    return sum;

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
  for (int i=0; i<all_sums.size(); i++){
      cout<<all_sums.at(i)<<endl;
  }


  /* Test max_heap */
/*
  Gem_data gm1 = {gems[0][0], 0, 0};
  Gem_data gm2 = {gems[0][1], 0, 1};
  Gem_data gm3 = {gems[7][7], 7, 7};
  Gem_data gm4 = {gems[1][1], 1, 1};

  vector<Gem_data> v1;
  v1.push_back(gm1);
  v1.push_back(gm2);
  v1.push_back(gm3);
  v1.push_back(gm4);
  v1.push_back(Gem_data(gems[2][2], 2, 2));

  make_heap(v1.begin(), v1.end(), max_sort());
  cout << v1.front().i << ","<< v1.front().j<<endl;
  v1.pop_back();
  cout << v1.back().i << ","<< v1.back().j<<endl;
*/

  return 0;
}
