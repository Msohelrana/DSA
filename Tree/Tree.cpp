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
public:
     ll data;
     struct Node* left;
     struct Node* right;

     Node(ll val){
        data=val;
        left=NULL;
        right=NULL;
    }

};

void preorder(struct Node* root){
   if(root==NULL){
       return;
   }

   cout<<root->data<<" ";
   preorder(root->left);
   preorder(root->right);
}

void inorder(struct Node* root){
    if(root==NULL){
       return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(struct Node* root){
    if(root==NULL)return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
 
void solve(){


   /*        1
            / \
           2   3
          / \
         4   5


   */


   struct Node* root = new Node(1);
   root->left= new Node(2);
   root->right= new Node(3);
   root->left->left=new Node(4);
   root->left->right=new Node(5);

   cout<<"Preorder: ";
   preorder(root);

   cout<<"\nInorder: ";
   inorder(root);

   cout<<"\nPostorder: ";
   postorder(root);
   
   
   
   
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