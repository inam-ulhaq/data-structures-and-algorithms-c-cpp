/*
 Title: Insertion in Binary Search Tree
 Author: Inam Ul Haq

 Description:
	Insertion in a Binary Search Tree (BST) means adding a new key
	at its correct position while maintaining BST properties.

	Insertion Conditions:

	1. Insert the key if it does NOT exist in the tree.
	2. Do NOT insert if the key already exists (no duplicates allowed).

	Insertion Algorithm:

	1. If the tree is empty:
	   Create a new node
	   Make it the root
	   Stop

	2. Otherwise:
	   Start from the root node.

	3. Compare key with current node:
	
	   a) If key == node->data
	      Stop
	      Do NOT insert (duplicate)
	
	   b) If key < node->data
	      Move to left subtree
	
	   c) If key > node->data
	      Move to right subtree
	
	4. Repeat Step 3 until a NULL pointer is found.
	
	5. When NULL is found:
	   Create a new node
	   Insert key at this position

	Example:
	
	                     50
	                    /  \
	                  40    60
	                /  \   /  \
	              35   45 55  70
	
	Insert key = 42

	Path followed:
	50 -> 40 -> 45 -> NULL

	42 < 45
	Insert as left child of 45

	Time Complexity:

	Worst Case:
	Tree is skewed
	O(n)

	Best or Average Case:
	Tree is balanced
	O(log n)

	Conclusion:
	BST insertion efficiently maintains
	sorted data structure.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
	struct Node *lChild;
	int data;
	struct Node *rChild;
};

// Implementation using iterative verison
void insert(struct Node **root,int key){
	struct Node *temp=*root, *tail=NULL;
	if(*root==NULL){
		(*root)=malloc(sizeof(struct Node));
		(*root)->lChild=(*root)->rChild=NULL;
		(*root)->data=key;
		return;
	}
	while(temp){
		tail=temp;
		if(key==temp->data)
			return;
		else if(key<temp->data)
			temp=temp->lChild;
		else
			temp=temp->rChild;
	}
	temp=malloc(sizeof(struct Node));
	temp->lChild=temp->rChild=NULL;
	temp->data=key;
	if(key<tail->data)
		tail->lChild=temp;
	else
		tail->rChild=temp;
		
		
}

// implementation using recursion

struct Node *recInsert(struct Node **ptr,int key){
	struct Node *temp;
	if((*ptr)==NULL){
		temp=malloc(sizeof(struct Node));
		temp->lChild=NULL;
		temp->rChild=NULL;
		temp->data=key;
		return temp;
	}
	
	if(key<(*ptr)->data){
		(*ptr)->lChild=recInsert(&(*ptr)->lChild,key);
	}else if(key>(*ptr)->data)
		(*ptr)->rChild=recInsert(&(*ptr)->rChild,key);
		
	return *ptr;
}


void inOrder(struct Node *temp){
	if(temp){
		inOrder(temp->lChild);
		printf("%d ",temp->data);
		inOrder(temp->rChild);
	}
}
int main(){
	struct Node* root=malloc(sizeof(struct Node));
	root->data=50;
	root->lChild=NULL;
	root->rChild=NULL;
	
	int data;
	for(int i=0;i<4;i++){
		printf("Enter data: ");
		scanf("%d",&data);
		recInsert(&root,data);
	}
	
	inOrder(root);
	
	return 0;
}
