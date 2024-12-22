//Calculate the total number of connected components
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

vector<vector<int> > connected_com;
vector<int>current_com;

 vector<int>g[N];
 bool vis[N];

 void dfs(int vertex){
     if(vis[vertex]) return;

     vis[vertex]=true;
     current_com.push_back(vertex);

     for(auto child:g[vertex]){
         dfs(child);
     }
 }
int main(){

   int n,e;
   cout<<"Enter the vertex number abd Edge number: ";
   cin>>n>>e;

    cout<<"Enter the edge: \n";
    for(int i=0;i<e;i++){
      int v1,v2;cin>>v1>>v2;
      g[v1].push_back(v2);
      g[v2].push_back(v1);
    }
    int ct=0;
    for(int i=1;i<=n;i++){
      if(vis[i]) continue;
      current_com.clear();
      dfs(i);
      connected_com.push_back(current_com);
      ct++;
    }

    cout<<"Total Number of connected components= "<<ct<<"\n";

    for(auto c_cc:connected_com){
         for(auto vertex:c_cc){
           cout<<vertex<<" ";
        }
        cout<<"\n";
    }

   return 0;
}
