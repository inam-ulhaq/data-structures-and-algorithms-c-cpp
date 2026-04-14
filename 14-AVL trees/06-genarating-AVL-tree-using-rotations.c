#include <stdio.h>
#include <stdlib.h>

struct Node{
	struct Node * lChild;
	int data;
	int height;
	struct Node * rChild;
};

struct Node* root=NULL;

int nodeHeight(struct Node* ptr){
	int h1,h2;
	h1=ptr && ptr->lChild?ptr->lChild->height:0;
	h2=ptr&& ptr->rChild?ptr->rChild->height:0;
	
	int result=h1>h2?h1+1:h2+1;
	return result;
	
}

int balanceFactor(struct Node* ptr){
	int h1=ptr && ptr->lChild?ptr->lChild->height:0;
	int h2=ptr && ptr->rChild?ptr->rChild->height:0;
	
	return h1-h2;
}

struct Node* LLRotation(struct Node* ptr){
	struct Node* pl=ptr->lChild;
	struct Node* plr=pl->rChild;
	
	pl->rChild=ptr;
	ptr->lChild=plr;
	ptr->height=nodeHeight(ptr);
	pl->height=nodeHeight(pl);
	if(ptr==root){
		root=pl;
	}
	return pl;
}

struct Node* LRRotation(struct Node* ptr){
	
	struct Node* pl=ptr->lChild;
	struct Node* plr=pl->rChild;
	
	
	pl->rChild=plr->lChild;
	ptr->lChild=plr->rChild;
	plr->lChild=pl;
	plr->rChild=ptr;
	
	plr->lChild->height=nodeHeight(plr->lChild);
	plr->rChild->height=nodeHeight(plr->rChild);
	plr->height=nodeHeight(plr);
	
	if(ptr==root)
		root=plr;
		
	return plr;
}

struct Node* RRRotation(struct Node* ptr){
	struct Node* pr=ptr->rChild;
	struct Node* prl=pr->lChild;
	
	pr->lChild=ptr;
	ptr->rChild=prl;
	pr->lChild->height=nodeHeight(pr->lChild);
	pr->height=nodeHeight(pr);
	
	if(ptr==root)
		root=pr;
		
	return pr;
	
}

struct Node* RLRotation(struct Node* ptr){
	struct Node* pr=ptr->rChild;
	struct Node* prl=pr->lChild;
	
	ptr->rChild=prl->lChild;
	pr->lChild=prl->rChild;
	prl->lChild=ptr;
	prl->rChild=pr;
	
	prl->lChild->height=nodeHeight(prl->lChild);
	prl->rChild->height=nodeHeight(prl->rChild);
	prl->height=nodeHeight(prl);
	
	if(ptr==root)
		root=prl;
	
	return prl;
}

struct Node *insert(struct Node *root,int value){
	struct Node* ptr=root;
	if(ptr==NULL){
		ptr=malloc(sizeof(struct Node));
		ptr->lChild=ptr->rChild=NULL;
		ptr->height=1;
		ptr->data=value;
		return ptr;
	}
	if(value<ptr->data){
		ptr->lChild=insert(ptr->lChild,value);
	}else if(value>ptr->data){
		ptr->rChild=insert(ptr->rChild,value);
	}
	ptr->height=nodeHeight(ptr);
	if(balanceFactor(ptr)==2 && balanceFactor(ptr->lChild)==1)
		return LLRotation(ptr);
	else if(balanceFactor(ptr)==2 && balanceFactor(ptr->lChild)==-1)
		return LRRotation(ptr);
	else if(balanceFactor(ptr)==-2 && balanceFactor(ptr->rChild)==-1)
		return RRRotation(ptr);
	else if(balanceFactor(ptr)==-2 && balanceFactor(ptr->rChild)==1)
		return RLRotation(ptr);
		
	return ptr;
}



void inorder(struct Node* root){
	if(root){
		inorder(root->lChild);
		printf("vlaue= %d  ",root->data);
		printf("height= %d\n",root->height);
		inorder(root->rChild);
	}
}


int main(){
	
	int n;
	printf("Enter Number of Nodes to insert: ");
	scanf("%d",&n);
	int n1=20;

	for(int i=0;i<n;i++){
		int value;
		printf("Enter value: ");
		scanf("%d",&value);
		root=insert(root,value);
		n1=n1-2;
	}	
	
	
	inorder(root);
	
}