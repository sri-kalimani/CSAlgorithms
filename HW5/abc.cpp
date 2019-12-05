#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<string> v[1000];
//map<string, int> mymap, fix;
string table[1000];
int actualHashValue[1000];
int fixTable[1000];

int main()
{
  freopen("Raven.txt", "r", stdin);

  string input;
  int C = 123;
  int m = 1000;
  int placedNot = 1;
  int newHash;
  while (cin >> input)
  {
    int h = 0;
    int flag = 0;
    string parsed = "";
    for (int i = 0; i < input.size(); i++)
    {
      char c = input[i];
      if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || c == '\'')
      {
        flag = 1;
        parsed += c;
        h = (h * C + int(c)) % m;
      }
    }
    if (flag == 1)
    {
      /*   //cout<<input<<" "<<parsed<<" "<<h<<endl;
      if (fix[parsed] != 0)
        continue;
      v[h].push_back(parsed);
*/
      if (fixTable[h] == 0)
      {
        fixTable[h] = 1;
        table[h] = parsed;
        actualHashValue[h] = h;
      }
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

      /* fix[parsed] = 1;
      mymap[parsed] = h;
      */
    }
  }

  /*for (int i = 0; i < 1000; i++)
  {
    cout << "String with hash " << i << " : ";
    for (int j = 0; j < v[i].size(); j++)
      cout << v[i][j] << " ";
    cout << endl;
  }*/

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
}
