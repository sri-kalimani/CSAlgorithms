#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

string table[1000];
int actualHashValue[1000];
int fixTable[1000] = {0};
//function that reads raven.txt and store its words into a hash table
void fillHashtable()
{
  //opens raven.txt
  freopen("Raven.txt", "r", stdin);

  string input;
  int C = 123;
  int m = 1000;
  int placedNot = 1;
  int newHash;
  //reads the file word by word
  while (cin >> input)
  {
    int h = 0;
    int flag = 0;
    string parsed = "";
    //goes through and cleans the string
    for (int i = 0; i < input.size(); i++)
    {
      char c = input[i];
      if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || c == '\'')
      {
        flag = 1;
        parsed += c;
        //creates the hash
        h = (h * C + int(c)) % m;
      }
    }
    //makes sure the word was cleaned
    if (flag == 1)
    {
      //if the hash value is empty store it there
      if (fixTable[h] == 0)
      {
        fixTable[h] = 1;
        table[h] = parsed;
        actualHashValue[h] = h;
      } //if not empty start stepping through the table looking for a empty spot
      else
      {
        if (table[h] != parsed)
        {
          placedNot = 1;
          newHash = h;
          while (placedNot)
          {
            if (newHash < 999)
            {
              newHash++;
            }
            else
            {
              newHash = 0;
            }
            if (fixTable[newHash] == 0)
            {
              fixTable[newHash] = 1;
              table[newHash] = parsed;
              actualHashValue[newHash] = h;
              placedNot = 0;
            }
            else if (table[newHash] == parsed)
            {
              placedNot = 0;
            }
          }
        }
      }
    }
  }
}
int main()
{
  fillHashtable();
  //part 3 a
  for (int i = 0; i < 1000; i++)
  {
    cout << "String with hash " << i << " : ";
    cout << table[i];
    cout << " the value of the hash word " << actualHashValue[i] << endl;
  }
  double load;
  int takenSpaces = 0;
  for (int i = 0; i < 1000; i++)
  {
    if (fixTable[i] == 1)
    {
      takenSpaces++;
    }
  }
  load = (double)takenSpaces / 1000.0;
  cout << "There are " << takenSpaces << " Taken Spaces in the table" << endl;
  cout << "This gives a load factor of " << load << endl;
  //part 3 b
  int EmptyCounter = 0;
  // EmptyCounter is the int that counts the amount of empty spaces
  // inbetween full spaces in the hashmap

  int CompareCounter = 0;

  int StartPoint = -1;
  int EndPoint = -1;

  int BestStartPoint = -1;
  int BestEndPoint = -1;

  for (int i = 0; i < 1000; i++)
  {
    if (fixTable[i] == 0)
    {
      if (EmptyCounter == 0)
      {
        StartPoint = i;
      }
      EmptyCounter++;
    }
    else if (fixTable[i] == 1)
    {
      if (EmptyCounter > CompareCounter)
      {
        CompareCounter = EmptyCounter;
        EndPoint = i - 1;
        BestEndPoint = EndPoint;
        BestStartPoint = StartPoint;
      }
      EmptyCounter = 0;
    }
  }
  cout << "The largest gap is now " << CompareCounter << endl;
  cout << "There is nothing from Start point " << BestStartPoint << " to endpoint " << BestEndPoint << endl;
  //part 3 c
  EmptyCounter = 0;
  CompareCounter = 0;

  StartPoint = -1;
  EndPoint = -1;

  BestStartPoint = -1;
  BestEndPoint = -1;

  for (int i = 0; i < 1000; i++)
  {
    if (fixTable[i] == 1)
    {
      if (EmptyCounter == 0)
      {
        StartPoint = i;
      }
      EmptyCounter++;
    }
    else if (fixTable[i] == 0)
    {
      if (EmptyCounter > CompareCounter)
      {
        CompareCounter = EmptyCounter;
        EndPoint = i - 1;
        BestEndPoint = EndPoint;
        BestStartPoint = StartPoint;
      }
      EmptyCounter = 0;
    }
  }
  cout << "The largest cluster is now " << CompareCounter << endl;
  cout << "There is something from Start point " << BestStartPoint << " to endpoint " << BestEndPoint << endl;
  //part 3 d
  int modeArray[1000] = {0};

  for (int i = 0; i < 1000; i++)
  {
    if (fixTable[i] == 1)
    {
      modeArray[actualHashValue[i]]++;
    }
  }

  int addressMode = 0;
  int address = -1;

  for (int i = 0; i < 1000; i++)
  {
    if (modeArray[i] > addressMode)
    {
      addressMode = modeArray[i];
      address = i;
    }
  }

  cout << "The hash address with the most unique words is " << address << ", with " << addressMode << " unique words." << endl;
  //part 3 e
  int greatestDistance = 0;
  int indexOfFarthestWord = 0;

  for (int i = 0; i < 1000; i++)
  {

    if (actualHashValue[i] != 0)
    {
      if ((i - actualHashValue[i]) > greatestDistance)
      {

        greatestDistance = i - actualHashValue[i];
        indexOfFarthestWord = i;
      }
    }
  }

  cout << "The word that is farthest away is " << table[indexOfFarthestWord] << " it is " << greatestDistance << " away from where it is supposed to be" << endl;
}
