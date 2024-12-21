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
//insert a value to the BST
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
//Find the minimum value of the tree
ll minVal(Node* root){
	if(root==NULL){
		return -1;
	}
	ll min=root->data;
	while(root->left!=NULL){
         min=root->data;
         root=root->left;
	}

	return min;
}

//Delete a node from the BST
Node* deleteInBST(Node* root,ll val){
	if(root==NULL){
		 return NULL;
	}

	if(root->data==val){
		//case1-> 0 childe
		if(root->left==NULL and root->right==NULL){
			delete root;
			return NULL;
		}

		//case2-> 1 child
		
		if(root->left!=NULL and root->right==NULL){
			Node* temp=root->left;
			delete root;
			return temp;
		}
		if(root->left==NULL and root->right!=NULL){
			Node* temp=root->right;
			delete root;
			return temp;
		}

		//case3-> 2 child

		if(root->left!=NULL and root->right!=NULL){
			ll min=minVal(root->right);//find the inorder successor
			root->data=min;
			root->right=deleteInBST(root->right,min);

			return root;
		}
	}

	else if(val<root->data){
		root->left=deleteInBST(root->left,val);
		return root;

	}
	else{
		root->right=deleteInBST(root->right,val);
		return root;

	}
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

	//Print inorder traversal(Before deletion)
	cout<<"Before Deletion: ";
	inorderPrint(root);

	root=deleteInBST(root,9);

	//Print inorder traversal(After deletion)
	cout<<"\nAfter deletion 9: ";
	inorderPrint(root);


	


}
