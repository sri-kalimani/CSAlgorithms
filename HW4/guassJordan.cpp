/*
Submissions for Bryan Gass, Sriranjani Kalimani and Theodore Campbell
*/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <array>

using namespace std;

void guassElimination(double a[][9], int n)
{

    double soutions[n];
    int pivotRow;
    double temp, temp2;
    for (int i = 0; i < n; i++)
    {
        pivotRow = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j][i] > a[pivotRow][i])
            {
                pivotRow = j;
            }
        }

        for (int k = i; k < (n + 1); k++)
        {

            swap(a[i][k], a[pivotRow][k]);
        }

        for (int j = i + 1; j < n; j++)
        {

            temp = a[j][i] / a[i][i];

            for (int k = i; k < (n + 1); k++)
            {
                a[j][k] = a[j][k] - (temp * a[i][k]);
            }
        }

        for (int j = i - 1; j >= 0; j--)
        {

            temp2 = a[j][i] / a[i][i];

            for (int k = i; k < (n + 1); k++)
            {
                a[j][k] = a[j][k] - (temp2 * a[i][k]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        a[i][8] = a[i][8] / a[i][i];
        a[i][i] = a[i][i] / a[i][i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            printf("%.2f ", a[i][j]);
        }
        cout << endl;
    }
}

int main()
{
    double a[8][9];
    a[0][0] = 1;
    a[0][1] = 1;
    a[0][2] = 1;
    a[0][3] = 1;
    a[0][4] = 1;
    a[0][5] = 1;
    a[0][6] = 1;
    a[0][7] = 1;
    a[0][8] = 0;
    //
    a[1][0] = 1;
    a[1][1] = 2;
    a[1][2] = 1;
    a[1][3] = 1;
    a[1][4] = 1;
    a[1][5] = 1;
    a[1][6] = 2;
    a[1][7] = 1;
    a[1][8] = 0;
    //
    a[2][0] = 1;
    a[2][1] = 1;
    a[2][2] = 3;
    a[2][3] = 1;
    a[2][4] = 1;
    a[2][5] = 3;
    a[2][6] = 1;
    a[2][7] = 1;
    a[2][8] = 0;
    //
    a[3][0] = 1;
    a[3][1] = 1;
    a[3][2] = 1;
    a[3][3] = 4;
    a[3][4] = 4;
    a[3][5] = 1;
    a[3][6] = 1;
    a[3][7] = 1;
    a[3][8] = 0;
    //
    a[4][0] = 11;
    a[4][1] = 1;
    a[4][2] = 1;
    a[4][3] = 1;
    a[4][4] = 1;
    a[4][5] = 1;
    a[4][6] = 1;
    a[4][7] = 1;
    a[4][8] = 20;
    //
    a[5][0] = 1;
    a[5][1] = 1;
    a[5][2] = 1;
    a[5][3] = 1;
    a[5][4] = -1;
    a[5][5] = -1;
    a[5][6] = -1;
    a[5][7] = -1;
    a[5][8] = 34;
    //
    a[6][0] = 1;
    a[6][1] = 2;
    a[6][2] = 3;
    a[6][3] = 4;
    a[6][4] = 5;
    a[6][5] = 6;
    a[6][6] = 7;
    a[6][7] = 8;
    a[6][8] = -51;
    //
    a[7][0] = 1;
    a[7][1] = -1;
    a[7][2] = 1;
    a[7][3] = -1;
    a[7][4] = 1;
    a[7][5] = -1;
    a[7][6] = 1;
    a[7][7] = -1;
    a[7][8] = -6;

    guassElimination(a, 8);
    return 1;
};
