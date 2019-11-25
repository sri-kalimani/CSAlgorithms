#include <iostream>
#include <stdio.h>
#include <math.h>
#include <array>
#include <vector>

using namespace std;

int max_coorR, max_coorC;
int path[8][2];

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

int path[8][8] = {0};
int maxNeighbor(int i, int j)
{
    if (j == 0)
    {
        if (dprograming[i - 1][j] > dprograming[i - 1][j + 1])
        {
            max_coorR = i - 1;
            max_coorC = j;
            return dprograming[i - 1][j];
        }
        else
        {
            max_coorR = i - 1;
            max_coorC = j + 1;
            return dprograming[i - 1][j + 1];
        }
    }
    else if (j == 7)
    {
        if (dprograming[i - 1][j] > dprograming[i - 1][j - 1])
        {
            max_coorR = i - 1;
            max_coorC = j;
            return dprograming[i - 1][j];
        }
        else
        {
            max_coorR = i - 1;
            max_coorC = j - 1;
            return dprograming[i - 1][j - 1];
        }
    }
    else if (dprograming[i - 1][j] > dprograming[i - 1][j + 1] && dprograming[i - 1][j] > dprograming[i - 1][j - 1])
    {
        max_coorR = i - 1;
        max_coorC = j;
        return dprograming[i - 1][j];
    }
    else if (dprograming[i - 1][j + 1] > dprograming[i - 1][j - 1])
    {
        max_coorR = i - 1;
        max_coorC = j + 1;
        return dprograming[i - 1][j + 1];
    }
    else
    {
        max_coorR = i - 1;
        max_coorC = j - 1;
        return dprograming[i - 1][j - 1];
    }
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
//returns the column of the creator of i , j
int numberOrgin(int i, int j)
{
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;

    void find_path()
    {

        int max_c = 0;
        for (int i = 0; i < 8; i++)
        {
            if (dprograming[7][max_c] < dprograming[7][i])
            {
                max_c = i;
            }
        }

        path[7][0] = 7;
        path[7][1] = max_c;
        int rowT, colT, prev_gem;
        rowT = 7;
        colT = max_c;

        for (int i = 6; i >= 0; i--)
        {
            prev_gem = maxNeighbor(rowT, colT);
            rowT = max_coorR;
            colT = max_coorC;
            path[i][0] = rowT + 1;
            path[i][1] = colT + 1;
        }
    }

    int main()
    {
        fillIntable();
        findPath();

        /*for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%d  ", dprograming[i][j]);
        }
        cout << endl;
    }*/
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                printf("%d  ", path[i][j]);
            }
            cout << endl;
        }

        find_path();

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout << path[i][j] << " ";
            }
            cout << endl;
        }
    }
