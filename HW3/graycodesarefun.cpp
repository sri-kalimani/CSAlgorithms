#include <iostream>
#include <stdio.h>
#include <math.h>
#include <array>
#include <list>
#include "vector"

using namespace std;
vector<string> namesInPic(string grayCode);
string names[] = {"Alice", "Bob", "Chris", "Dylan"};

//Generates recursively the binary reflected Gray code of order n
//Input: A positive integer n
//Output: A list of all bit strings of length n composing the Gray code
vector<string> BRGC(int n)
{
    vector<string> listToReturn;
    vector<string> listReversed;
    int lengthOfint;
    if (n == 1)
    {
        listToReturn.push_back("0");
        listToReturn.push_back("1");
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
            listToReturn[i] = "0" + listToReturn[i];
            listReversed[i] = "1" + listReversed[i];
            listToReturn.push_back(listReversed[i]);
        }
    }

    return listToReturn;
}
int toBinary(string binaryString)
{
    int binaryNum = 0;

    for (int i = 0; i < binaryString.length(); i++)
    {
        if (binaryString.substr(binaryString.length() - (i + 1), 1) == "1")
        {

            binaryNum = binaryNum + pow(2, i);
        }
    }

    return binaryNum;
}
vector<string> outputOrderOfnames(vector<string> grayCode)
{
    vector<string> orderOfnames;
    vector<string> namesInList;
    int numberShift;
    int previousNum;
    int currentNum;
    string previousString;
    string currentString;
    string addToList;

    for (int i = 1; i < grayCode.size(); i++)
    {
        previousString = grayCode[i - 1];
        currentString = grayCode[i];
        previousNum = toBinary(previousString);
        currentNum = toBinary(currentString);
        numberShift = (currentNum ^ previousNum);
      
        for (int j = 0; j < 4; j++)
        {
            
            if (numberShift & 1)
            {
                namesInList = namesInPic(grayCode[i]);
                addToList = " ";
                for(int k =0; k < namesInList.size();k++){
                    if(namesInList[k] == names[j]){
                        addToList = names[j] + " in";
                    }else if(addToList == " "){
                        addToList = names[j] + " out";
                    }
                }
                orderOfnames.push_back(addToList );
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
vector<string> namesInPic(string grayCode)
{
    vector<string> orderOfnames;
    int numberShift;
    int previousNum;
    int currentNum;
   
    //int sizeOfArray = names.size();

    
        numberShift = toBinary(grayCode);
        // cout << numberShift;
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
        
    
    return orderOfnames;
}

void createTable(vector<string> grayCode, vector<string> OrderOfnames)
{
    vector<string> namesInPhoto;
    
    for (int i = 1; i < 16; i++)
    {
        cout << i << "   ";
        cout << grayCode[i] << "  ";
        namesInPhoto = namesInPic(grayCode[i]);
        for(int j = 0; j < namesInPhoto.size();j++){
         cout << namesInPhoto[j] << " ";   
        }
        
        cout << "    " << OrderOfnames[i-1] << "  ";
        cout << endl;
    }
    
}

int main()
{

    createTable(BRGC(4), outputOrderOfnames(BRGC(4)));
    return 1;
}
