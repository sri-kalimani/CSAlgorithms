#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<string> v[1000];
map<string,int>mymap,fix;
string table[1000];
int fixTable[1000];

main()
{
  freopen("Raven.txt","r",stdin);

  string input;
  int C = 123;
  int m = 1000;
  while(cin>>input){
    int h = 0;
    int flag = 0;
    string parsed="";
    for(int i=0;i<input.size();i++){
      char c = input[i];
      if(  ('a'<=c && c<='z')
        || ('A'<=c && c<='Z')
        || c=='\''){
            flag = 1;
            parsed += c;
            h = (h*C + int(c)) % m;
        }
    }
    if(flag == 1){
      //cout<<input<<" "<<parsed<<" "<<h<<endl;
      if(fix[parsed]!=0)
        continue;
      v[h].push_back(parsed);

      if(fixTable[h]==0){
        fixTable[h] = 1;
        table[h] = parsed;
      }

      fix[parsed] = 1;
      mymap[parsed] = h;
    }
  }


//    for(int i=0;i<1000;i++)
//    {
//      cout<<"String with hash "<<i<<" : ";
//      for(int j=0;j<v[i].size();j++)
//        cout<<v[i][j]<<" ";
//      cout<<endl;
//    }

    for(int i=0;i<1000;i++)
    {
      cout<<"String with hash "<<i<<" : ";
      cout<<table[i]<<endl;
    }
}
