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

//Level Order Traversal

void levelOrderTraversal(Node* root){
    if(root==NULL){
         return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    ll level=0;
    cout<<"Level "<<level<<": ";
    while(!q.empty()){
        Node* node=q.front();
        
        if(node==NULL){
            level++;
            q.pop();
            if(!q.empty()){
                cout<<"\nLevel "<<level<<": ";
                q.push(NULL);
            }

        }
        else{
        cout<<node->data<<" ";
        q.pop();

        if(node->left){
            q.push(node->left);
        }
        if(node->right){
             q.push(node->right);
        }
      }
        
    }
}

//Sum at k-th Level

ll sumAtK(Node* root,ll k){

     if(root==NULL){
        return -1;
     }

     queue<Node*> q;
     q.push(root);
     q.push(NULL);
     ll llevel=0,sum=0;

     while(!q.empty()){
        //cout<<llevel<<"\n";
        Node* node = q.front();
        q.pop();

        if(node!=NULL){
            if(llevel==k){
                sum+=node->data;
            }
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        else if(!q.empty()){
              
              llevel++;
              q.push(NULL);
        }
     }
     return sum;
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

   levelOrderTraversal(root); 

   ll sum=sumAtK(root,2);
   if(sum==-1){
      cout<<"\nInvalid Level\n";
   }
   else{
      cout<<"\n"<<sum<<"\n";
   }

   
   
   
   
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