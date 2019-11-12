#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;



int countInversion(int *arr, int n){
  std::vector <std::vector <int> > inv;
  std::vector<int> pair;

    for (int i=0; i<n; i++){
      for (int j=0; j<n; j++){
          pair.clear();
          if (i<j && arr[i] > arr[j]){
            pair.push_back(arr[i]);
            pair.push_back(arr[j]);
          }
      }
      inv.push_back(pair);

    }

    // for (int k=0; k<inv.size(); k++){
    //   for (int l=0; l<inv[k].size(); l++){
    //     cout<<inv[k][l];
    //   }
    //   cout<<endl;
    // }

    return (inv.size());
}


int main(void){

  int arr[10] = {3, 2, 6, 9, 1, 4, 5, 8, 7, 0};
  int arr1[3] = {3, 2, 1};
  // countInversion(arr1, 3);
  cout<<countInversion(arr, 10)<<endl;
  // cout<<countInversion(arr1, 3)<<endl;


  return 0;
}
