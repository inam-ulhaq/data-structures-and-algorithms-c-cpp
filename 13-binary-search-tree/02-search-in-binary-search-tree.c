/*
 Title: Searching in Binary Search Tree
 Author: Inam Ul Haq
 Description:
	Suppose we have a Binary Search Tree (BST) and we want to search for a key.

	Search Procedure:
	1. Start from the root node.
	2. Compare the key with the current node's data.
	   - If both are equal, return the node (search successful).
	   - If the key is smaller than the node's data, move to the left child.
	   - If the key is greater than the node's data, move to the right child.
	3. Repeat this process until:
	   - The key is found, or
	   - We reach a NULL pointer (search unsuccessful).
	
	Example Tree:
	
	                 50
	                /  \
	              40    60
	            /  \   /  \
	          35   45 55  70
	
	Searching for key = 45

	Step 1:
	Compare 45 with 50
	45 < 50
	Move to left child (40)

	Step 2:
	Compare 45 with 40
	45 > 40
	Move to right child (45)

	Step 3:
	Compare 45 with 45
	Match found
	Return node
	
	Unsuccessful Search:
	If the key does not exist, we will eventually reach a NULL pointer.
	At this point, traversal stops and we return NULL or 0.

	Time Complexity:
	The time taken depends on the height of the tree.

	Worst Case:
	Tree is skewed (left or right skewed)
	Height = n
	Time Complexity = O(n)

	Best or Average Case:
	Tree is balanced
	Height = log(n)
	Time Complexity = O(log n)

	Conclusion:
	Since skewed trees are rare, we generally consider
	the time complexity of BST search as O(log n).

*/
#include <stdio.h>
#include <stdlib.h>

struct Node{
	struct Node *lChild;
	int data;
	struct Node *rChild;
};

// Implementation using iterative verison
struct Node *search(struct Node *root,int key){
	struct Node *temp=root;
	while(temp){
		if(key==temp->data)
			return temp;
		else if(key<temp->data)
			temp=temp->lChild;
		else
			temp=temp->rChild;
	}
	return NULL;
}

// implementation using recursion

struct Node *recSearch(struct Node *temp,int key){
	if(!temp){
		return NULL;
	}
	if(key==temp->data){
		return temp;
	}else if(key<temp->data){
		recSearch(temp->lChild,key);
	}else
		recSearch(temp->rChild,key);
}

int main(){
	struct Node* root=malloc(sizeof(struct Node));
	root->data=50;
	root->lChild=NULL;
	root->rChild=NULL;
	
	struct Node *temp=root;
	temp->lChild=malloc(sizeof(struct Node));
	temp->lChild->data=40;
	temp->lChild->lChild=NULL;
	temp->lChild->rChild=NULL;
	
	temp->rChild=malloc(sizeof(struct Node));
	temp->rChild->data=60;
	temp->rChild->lChild=NULL;
	temp->rChild->rChild=NULL;
	
	temp=root->lChild;
	temp->lChild=malloc(sizeof(struct Node));
	temp->lChild->data=35;
	temp->lChild->lChild=NULL;
	temp->lChild->rChild=NULL;
	
	temp->rChild=malloc(sizeof(struct Node));
	temp->rChild->data=45;
	temp->rChild->lChild=NULL;
	temp->rChild->rChild=NULL;
	
	
	temp=root->rChild;
	temp->lChild=malloc(sizeof(struct Node));
	temp->lChild->data=55;
	temp->lChild->lChild=NULL;
	temp->lChild->rChild=NULL;
	
	temp->rChild=malloc(sizeof(struct Node));
	temp->rChild->data=65;
	temp->rChild->lChild=NULL;
	temp->rChild->rChild=NULL;
	
	int key=45;
	if(search(root,key)){
		printf("%d is found in binary search tree.\n",key);
	}else{
		printf("%d is not found in binary search tree.\n",key);
	}
	
	key=65;
	if(recSearch(root,key)){
		printf("%d is found in binary search tree.\n",key);
	}else{
		printf("%d is not found in binary search tree.\n",key);
	}
	
}
