#include<bits/stdc++.h>
using namespace std;

int n;
int a[101][101];
int fix[101];
int d[101],parent[101];
#define INF int(1e9)


void dijkstra(int s,int f){
  for(int i=0;i<=n;i++)
    d[i]=INF,
    fix[i]=0,
    parent[i]=0;

  priority_queue<pair<int,int> >q;
  q.push(make_pair(0,s));
  d[s]=0;
  fix[s]=1;


  while(!q.empty()){
    int now = q.top().second;
    q.pop();

    if(fix[now])
      continue;
    fix[now] = 1;

    for(int i=1;i<=n;i++){
      if(fix[i])
        continue;
      if(a[now][i] == 0)
        continue;

      if(d[i] > d[now] + a[now][i]){
        d[i] = d[now] + a[now][i];
        parent[i] = now;
        q.push(make_pair(-d[i],i));
      }
    }
  }

  if(d[f] == INF){
    cout<<"Node "<< f <<" is unreachable!!"<<endl;
    return;
  }


  vector<int>path;
  int now = f;


  while(now != s){
    path.push_back(now);
    now = parent[now];
  }

  path.push_back(s);
  reverse(path.begin(), path.end());

  cout<<"Shortest Distance from "<<s<< " to "<<f<<" is ";
  cout<<d[f]<<endl;
  cout<<"The path:"<<endl;
  for(int i=0;i<path.size();i++)
    cout<<path[i]<<" ";
  cout<<endl;
  for(int i=1;i<path.size();i++)
    cout<<path[i-1]<<" to "<<path[i]<<" by distance "<<a[path[i-1]][path[i]]<<endl;
  cout<<endl;
}


main()
{
  ifstream myfile ("a.in");

  myfile>>n;
  for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
    myfile>>a[i][j];

  cout<<n<<endl;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++)
      cout<<a[i][j]<<" ";
    cout<<endl;
  }

  cout<<endl;
  cout<<endl;
  cout<<endl;


  int start,end;
  cout<<"Input Starting Node: ";
  cin>>start;
  cout<<"Input Final Node: ";
  cin>>end;


  cout<<endl;
  cout<<endl;
  cout<<endl;

  dijkstra(start,end);
}
