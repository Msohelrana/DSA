//Make a balanced binary search Tree from inorder

#include<bits/stdc++.h>

using namespace std;
#define ll long long

struct Node{
	ll data;
	Node* left;
	Node* right;

	Node(ll val){
		data=val;
		left=NULL;
		right=NULL;
	}
};

Node* makeBalanceBST(Node* root,ll v[],ll start,ll end){
	  if(start>end){
	  	return NULL;
	  }

	  ll mid=(start+end)/2;
	  root=new Node(v[mid]);
	  root->left=makeBalanceBST(root->left,v,start,mid-1);
	  root->right=makeBalanceBST(root->right,v,mid+1,end);

	  return root;

}



void inorderPrint(Node* root){
	if(root==NULL){
		 return;
	}
	inorderPrint(root->left);
	cout<<root->data<<" ";
	inorderPrint(root->right);
}

void preorderPrint(Node* root){
	if(root==NULL){
		 return;
	}
	cout<<root->data<<" ";
	preorderPrint(root->left);
	preorderPrint(root->right);
}


int main(){
    Node* root=NULL;
    
	ll inorder[]={1,2,3,4,5,6,7};

	root=makeBalanceBST(root,inorder,0ll,6ll);
	preorderPrint(root);

	


}