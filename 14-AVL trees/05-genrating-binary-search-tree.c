#include <stdio.h>
#include <stdlib.h>
struct Node{
	struct Node * leftChild;
	int data;
	int height;
	struct Node * rightChild;
};


void insert(struct Node** root,int value){
	if(*root==NULL){
		*root=malloc(sizeof(struct Node));
		(*root)->leftChild=(*root)->rightChild=NULL;
		(*root)->data=value;
		(*root)->height=1;
		return;
	}
	struct Node* ptr=*root;
	struct Node* tail=NULL;
	while (ptr!=NULL){
		tail=ptr;
		if(ptr->data==value){
			printf("Value already exist!\n");
			return;
		}else if(ptr->data<value)
			ptr=ptr->rightChild;
		else
			ptr=ptr->leftChild;
	struct Node *temp=malloc(sizeof(struct Node));
	temp->leftChild=temp->rightChild=NULL;
	temp->data=value;
	if(tail->data>value)
		tail->leftChild=temp;
	else
		tail->rightChild=temp;
	
	
}

void Inorder(struct Node* root)
{
	if(root!=NULL){
		Inorder(root->leftChild);
		printf("%d ",root->data);
		Inorder(root->rightChild);
	}
}
int main(){
		struct Node * root=NULL;
		printf("Enter how many nodes to insert: ");
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			int value;
			printf("Enter value: ");
			scanf("%d",&value);
			insert(&root,value);
		}
		Inorder(root);
}