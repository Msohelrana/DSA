
//Detect cyle in a graph
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

 vector<int>g[N];
 bool vis[N];

 bool dfs(int vertex,int par){

     vis[vertex]=true;

     bool isCycle=false;

     for(auto child:g[vertex]){
         if(vis[child] && child==par){
             continue;
         }
         if(vis[child]) return true;
         isCycle |=dfs(child,vertex);//jekono akta true holei hbe.jehetu or kortechi;
     }
     return isCycle;
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
    bool isCycle=false;
    for(int i=1;i<=n;i++){

      if(vis[i]) continue;
      if(dfs(i,0)){
         isCycle=true;
         cout<<isCycle<<" "<<i<<"\n";
         break;

      }
    }

    cout<<isCycle<<"\n";




   return 0;
}
