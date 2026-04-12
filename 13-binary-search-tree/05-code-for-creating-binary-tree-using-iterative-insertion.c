#include <stdio.h>
#include <stdlib.h>
struct Node{
	struct Node* lChild;
	int data;
	struct Node* rChild;
};


int insert(struct Node** root,int key){
	struct Node* ptr=*root;
	struct Node* tail=NULL;
	if(ptr==NULL){
		ptr=malloc(sizeof(struct Node));
		ptr->data=key;
		ptr->rChild=ptr->lChild=NULL;
		*root=ptr;
		return 1;
	}
	while(ptr!=NULL){
		tail=ptr;
		if(ptr->data==key){
			return 0;
		}else if(ptr->data>key){
			ptr=ptr->lChild;
		}else
			ptr=ptr->rChild;	
	}
	ptr=malloc(sizeof(struct Node));
	ptr->data=key;
	ptr->rChild=ptr->lChild=NULL;
	if(tail->data>key)
		tail->lChild=ptr;
	else
		tail->rChild=ptr;
		return 1;
}


void inOrder(struct Node* ptr){
	if(ptr!=NULL){
		inOrder(ptr->lChild);
		printf("%d, ",ptr->data);
		inOrder(ptr->rChild);
	}
}


int main(){
	struct Node* root=NULL;
	for(int i=0;i<6;i++){
		printf("Enter value: ");
		int key;
		scanf("%d",&key);
		insert(&root,key);
	}
	inOrder(root);
	
}