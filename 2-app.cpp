#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int graph[1000][1000];
vector<int>odds;
vector<int>path;
vector<int>*adjlist;
int visiting[1000];
set<int>st;
vector<int>preorder;
void dfs(int x)
{
  if(st.find(x)==st.end())
  {
      preorder.push_back(x);
      st.insert(x);
  }
  visiting[x]=1;
  for(int i=0;i<adjlist[x].size();i++)
  {
      if(visiting[adjlist[x][i]]==0)
      {
          dfs(adjlist[x][i]);
      }
  }
}
int getMinIndex(int key[],bool mst[],int n)
{
  int min = std::numeric_limits<int>::max();
  int min_index;
  for (int i = 0; i < n; i++) {
    if (mst[i] == false && key[i] < min) {
      min = key[i];
      min_index = i;
    }
  }
return min_index;
}
void mst(int n)
{
  int *key = new int[n];
  bool *included = new bool[n];
  int *parent = new int[n];
  adjlist = new vector<int>[n];
  for (int i = 0; i < n; i++) {
    key[i] = std::numeric_limits<int>::max();
    included[i] = false;

  }
  key[0] = 0;
  
  parent[0] = -1;

  for (int i = 0; i < n - 1; i++) {

    int k = getMinIndex(key, included,n);
    included[k] = true;
    for (int j = 0; j < n; j++) {
      if (graph[k][j] && included[j] == false && graph[k][j] < key[j]) {

         
          parent[j] = k;
          key[j] = graph[k][j];

      }
    }

  }
  for (int i = 0; i < n; i++) {
    int j = parent[i];
    if (j != -1) {
      adjlist[i].push_back(j);
      adjlist[j].push_back(i);
    }
  }
}
int main()
{
    int t;
    t=1;
    while(t--)
    {
   cout<<"ENTER THE NUMBER OF CITIES"<<"\n";
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
       cout<<"ENTER THE DISTANCE B/W CITIES"<<i+1<<" "<<j+1<<"\n";
       cin>>graph[i][j];
       }
   }
   mst(n);
   dfs(0);
   cout<<"preorder"<<"\n";
   for(int i=0;i<preorder.size();i++)
   {
       cout<<preorder[i]+1<<" ";
   }
   cout<<1<<"\n";
   cout<<"Cost obtained is "<<"\n";
   int ans=0;
   for(int i=0;i<preorder.size()-1;i++)
   {
       ans+=graph[preorder[i]][preorder[i+1]];
   }
   ans+=graph[preorder[preorder.size()-1]][0];
   cout<<ans<<"\n";
    }
}

