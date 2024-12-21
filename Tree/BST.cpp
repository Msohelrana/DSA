//Build BST(Binary search tree) from an array

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

Node* insertBST(Node* root,ll val){

	if(root==NULL){
		return new Node(val);
	}


	if(val<root->data){
        root->left=insertBST(root->left,val);
	}
	if(val>root->data){
		root->right=insertBST(root->right,val);
	}
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


int main(){
    Node* root=NULL;
	ll arr[10]={2,3,10,4,7,9,1,5,6,8,};
	root=insertBST(root,arr[0]);
	for(ll i=1;i<10;i++){
		insertBST(root,arr[i]);
		
	}

	//Print inorder traversal
	inorderPrint(root);


}