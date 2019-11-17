#include <iostream>
#include <stdio.h>
#include <math.h>
#include <array>
#include <list>
#include "vector"

using namespace std;

string names[] = {"Alice", "Bob", "Chris", "Dylan"};

//Generates recursively the binary reflected Gray code of order n
//Input: A positive integer n
//Output: A list of all bit strings of length n composing the Gray code
vector<int> BRGC(int n)
{
    vector<int> listToReturn;
    vector<int> listReversed;
    int lengthOfint;
    if (n == 1)
    {
        listToReturn.push_back(0);
        listToReturn.push_back(1);
    }
    else
    {
        listToReturn = BRGC(n - 1);
        for (int i = 0; i < listToReturn.size(); i++)
        {

            listReversed.push_back(listToReturn[listToReturn.size() - i - 1]);
        }

        for (int i = 0; i < listReversed.size(); i++)
        {
            listReversed[i] = pow(2, n) + listReversed[i];
            listToReturn.push_back(listReversed[i]);
        }
    }

    return listToReturn;
}

vector<string> outputOrderOfnames(vector<int> grayCode)
{
    vector<string> orderOfnames;
    int numberShift;
    //int sizeOfArray = names.size();

    for (int i = 0; i < grayCode.size(); i++)
    {
        numberShift = grayCode[i];
        for (int j = 0; j < 4; j++)
        {
            if (numberShift & 1)
            {
                orderOfnames.push_back(names[j]);
                numberShift = numberShift >> 1;
            }
            else
            {
                numberShift = numberShift >> 1;
            }
        }
    }
    return orderOfnames;
}

int main()
{

    cout << BRGC(4).size() << endl;

    //vector<string> path = outputOrderOfnames(BRGC(4));
    vector<int> path = BRGC(4);
    for (int i = 0; i < path.size(); ++i)
    {
        cout << path[i] << endl;
    }

    return 1;
}
