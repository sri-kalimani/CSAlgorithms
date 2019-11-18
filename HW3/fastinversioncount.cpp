#include <stdio.h>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


int mergeSort(int arr[], int temp[], int left, int right);
int mergeInv(int arr[], int temp[], int left, int mid, int right);

/*
* int countInversion(int arr[], int array_size)
* return inv_count
* Sorts the input array and returns the
* number of inversions in the array
* This function calls everything else
*/
int countInversion(int arr[], int array_size)
{
    int temp[array_size];
    return mergeSort(arr, temp, 0, array_size - 1);
}

/*
* int mergeSort(int arr[], int temp[], int left, int right)
* return inv_count
* Recursive function that sorts the input array and
* returns the number of inversions in the array.
*/
int mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left) {
        // Divide the array into two parts
        mid = (right + left) / 2;

        inv_count = mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);

        inv_count += mergeInv(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

/*
* int mergeInv (int arr[], int temp[], int left, int mid, int right)
* return inversion count
* Function merges left and right sorted arrays and returns count of Inversions
* Called until all elements are merged
*/
int mergeInv(int arr[], int temp[], int left, int mid, int right)
{
    int i, j, k;
    int inv_count = 0;

    i = left;
    j = mid;
    k = left; /* k is index for resultant merged subarray*/
    // Copy elements from right and left sub arrays based on greater element to temp
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }

    /* Copy remaining elements of left subarray to temp*/
    while (i <= mid - 1)
        temp[k++] = arr[i++];

    /* Copy remaining elements of right subarray to temp*/
    while (j <= right)
        temp[k++] = arr[j++];

    /*Copy temp to original array*/
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

int main()
{
    // Test arrays
      int arr1[] = {3, 2, 6, 9, 1, 4, 5, 8, 7, 0};
      int arr2[] = {3, 2, 1};
      int arr3[] = {5, 4, 3, 2, 1};

    // Test output
      cout<<countInversion(arr1, 10)<<endl;
      cout<<countInversion(arr2, 3)<<endl;
      cout<<countInversion(arr3, 5)<<endl;

    return 0;
}
