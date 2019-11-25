#include <iostream>
#include <stdio.h>
#include <math.h>
#include <array>

using namespace std;

int gems[][8] = {
    {79, 71, 18, 20, 34, 51, 93, 65},
    {73, 38, 24, 49, 18, 6, 40, 74},
    {31, 5, 63, 10, 32, 40, 14, 13},
    {13, 78, 48, 19, 78, 11, 90, 94},
    {22, 93, 68, 11, 56, 63, 49, 35},
    {85, 52, 27, 5, 94, 91, 82, 62},
    {46, 23, 99, 77, 10, 42, 1, 72},
    {89, 70, 73, 83, 90, 22, 44, 92}};

int dprograming[][8] = {
    {79, 71, 18, 20, 34, 51, 93, 65},
    {73, 38, 24, 49, 18, 6, 40, 74},
    {31, 5, 63, 10, 32, 40, 14, 13},
    {13, 78, 48, 19, 78, 11, 90, 94},
    {22, 93, 68, 11, 56, 63, 49, 35},
    {85, 52, 27, 5, 94, 91, 82, 62},
    {46, 23, 99, 77, 10, 42, 1, 72},
    {89, 70, 73, 83, 90, 22, 44, 92}};

int maxNeighbor(int i, int j)
{
    if (j == 0)
    {
        if (dprograming[i - 1][j] > dprograming[i - 1][j + 1])
        {
            return dprograming[i - 1][j];
        }
        else
            return dprograming[i - 1][j + 1];
    }
    else if (j == 7)
    {
        if (dprograming[i - 1][j] > dprograming[i - 1][j - 1])
        {
            return dprograming[i - 1][j];
        }
        else
            return dprograming[i - 1][j - 1];
    }
    else if (dprograming[i - 1][j] > dprograming[i - 1][j + 1] && dprograming[i - 1][j] > dprograming[i - 1][j - 1])
    {
        return dprograming[i - 1][j];
    }
    else if (dprograming[i - 1][j + 1] > dprograming[i - 1][j - 1])
    {
        return dprograming[i - 1][j + 1];
    }
    else
        return dprograming[i - 1][j - 1];
}
void fillIntable()
{
    for (int i = 1; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            dprograming[i][j] = dprograming[i][j] + maxNeighbor(i, j);
        }
    }
}

int main()
{
    fillIntable();

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%d  ", dprograming[i][j]);
        }
        cout << endl;
    }
}
