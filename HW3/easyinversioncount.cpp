#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


/*
* countInversion: checkes if elements after current element are
* greater and adds count

* returns count of inversions
*/
int countInversion(int *arr, int n){

  int count=0;
    for (int i=0; i<n-1; i++){
      for (int j=i; j<n; j++){
          if (arr[i]>arr[j])
          count++;
      }
    }
    return(count);
}


int main(void){

// Test arrays
  int arr1[] = {3, 2, 6, 9, 1, 4, 5, 8, 7, 0};
  int arr2[] = {3, 2, 1};

// Test output
  cout<<countInversion(arr1, 10)<<endl;
  cout<<countInversion(arr2, 3)<<endl;

  return 0;
}
