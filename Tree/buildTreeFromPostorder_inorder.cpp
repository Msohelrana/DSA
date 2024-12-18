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

ll search(ll inorder[],ll start,ll end,ll cur){

    for(ll i=start;i<=end;i++){
          if(inorder[i]==cur){
             return i;
          }
    }
    return -1;
}

Node* buildTree(ll postorder[],ll inorder[],ll start,ll end){
    static ll ind=end;

    if(start>end){
         return NULL;
    }

    ll cur=postorder[ind];
    ind--;

    Node* node=new Node(cur);
    if(start==end){
         return node;
    }
    ll pos=search(inorder,start,end,cur);

    node->right=buildTree(postorder,inorder,pos+1,end);
    node->left=buildTree(postorder,inorder,start,pos-1);

    return node;
}

void inorderTree(Node* root){
     if(root==NULL){
        return;
     }
     inorderTree(root->left);
     cout<<root->data<<" ";
     inorderTree(root->right);
}


 
void solve(){


   /*        1
            / \
           2   3
          / \
         4   5


   */


   ll postorder[]={4,5,2,3,1};
   ll inorder[]={4,2,5,1,3};

   Node* root= buildTree(postorder,inorder,0,4);
   inorderTree(root);


   
   
   
   
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