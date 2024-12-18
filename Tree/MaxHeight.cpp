//Inorder and preorder Traversal


#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ppb pop_back
#define ll long long
#define vbe v.begin(),v.end()
const ll M=1e9+7; 
const ll N=2*1e5+9;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
 
struct Node{
    ll data;
    struct Node* left;
    struct Node* right;

    Node(ll val){
         data=val;
         left=NULL;
         right=NULL;
    }
};

//Count of total nodes in tree

ll maxHeight(Node* root){

    if(root==NULL) return 0;

    ll left=maxHeight(root->left);
    ll right=maxHeight(root->right);

    
    return max(left,right)+1;
}





 
void solve(){


   /*        1
            / \
           2   3
          / \   \
         4   5   6
                /
               7  


   */


   Node* root= new Node(1);
   root->left=new Node(2);
   root->right=new Node(3);
   root->left->left=new Node(4);
   root->left->right=new Node(5);
   root->right->right=new Node(6);
   root->right->right->left=new Node(7);

   ll Height=maxHeight(root);
   cout<<"MAximum height of the Tree: "<<Height<<"\n";

   
   
   
   
}
 
int main(){ 
  fast;
  // ll tc;cin>>tc;
  // while(tc--){

  //    solve();
     
 // }
 solve();
  
  return 0;
  
}