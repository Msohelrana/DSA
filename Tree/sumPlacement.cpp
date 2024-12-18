//Update each node with the sum of it's left subtree and right subtree including itself


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

void sumPlacement(Node* root){
    if(root==NULL) return;

    sumPlacement(root->left);
    sumPlacement(root->right);

    if(root->left){
        root->data+=root->left->data;
    }
    if(root->right){
        root->data+=root->right->data;
    }
}

void inorder(Node* root){
    if(root==NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

 
void solve(){


   /*        1
            / \
           2   3
          / \
         4   5


   */


   Node* root= new Node(1);
   root->left=new Node(2);
   root->right=new Node(3);
   root->left->left=new Node(4);
   root->left->right=new Node(5);
   root->right->left=new Node(6);
   root->right->right=new Node(7);

   sumPlacement(root);
   inorder(root);

   

   
   
   
   
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