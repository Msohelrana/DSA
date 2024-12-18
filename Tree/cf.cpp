#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ppb pop_back
#define ll long long
#define vbe v.begin(),v.end()
const ll M=1e9+7; 
const ll N=2*1e5+9;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);



 
void solve(){
   ll n,k,m,a,b,c,ans=0,target,ot=0,div;
   string s;cin>>s;
   n=s.length();

   // if(n==1){
   //   cout<<-1<<"\n";
   //   return;
   // }
  
   for(ll i=0;i<n-1;i++){
     if(s[i]==s[i+1]){
        cout<<s[i]<<s[i+1]<<"\n";
        return;
     }
   }
   for(ll i=0;i<n-2;i++){
     if(s[i]!=s[i+1] and s[i+1]!=s[i+2] and s[i]!=s[i+2]){
          cout<<s[i]<<s[i+1]<<s[i+2]<<"\n";
          return;
     }
   }

   cout<<-1<<"\n";
    
    
  }
     
  

   


  
   
   
   

 
int main(){ 
  fast;
  ll tc;cin>>tc;
  while(tc--){

     
     solve();
     
  }
  // solve();
  
  return 0;
  
}