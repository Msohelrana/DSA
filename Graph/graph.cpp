//Create a graph using adjacencey List representation

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;



 vector<int>g[N];

void printGrapList(vector<int>g[],int n){
 	for(int i=1;i<=n;i++){
 		cout<<"child of "<<i<<": ";
 		for(auto child:g[i]){
 			cout<<child<<" ";
 		}
 		cout<<"\n";
 	}

 }
int main(){

	int n,m;
	cout<<"Enter the vertex number abd Edge number: ";
	cin>>n>>m;

    cout<<"Enter the edge: \n";
    for(int i=0;i<m;i++){
	 	int v1,v2;cin>>v1>>v2;
	 	g[v1].push_back(v2);
	 	g[v2].push_back(v1);
	 }
	 printGrapList(g,n);
	return 0;
}
