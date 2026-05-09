#include <stdio.h>
#include <stdlib.h>
struct Node{
	int data;
	struct Node *next;
};

void hash(int A[],int size){
	struct Node **hashTable=calloc(10,sizeof(struct Node*));
	for(int i=0;i<size;i++){
		int key=A[i];
		int index=key%10;
		if(hashTable[index]==NULL){
			struct Node *element=malloc(sizeof(struct Node));
			element->data=key;
			element->next=NULL;
			hashTable[index]=element;	
		}
		else{
			struct Node *ptr=hashTable[index];
			struct Node *tail=NULL;
			while(ptr && ptr->data<key){
				tail=ptr;
				ptr=ptr->next;
			}
			struct Node *element=malloc(sizeof(struct Node));
			element->data=key;
			if(tail){
				tail->next=element;
				element->next=ptr;
			}
			else{
				hashTable[index]=element;
				element->next=ptr;
			}
		}
	}
	
	int key;
	printf("Enter the key you want to search: ");
	scanf("%d",&key);
	int index=key%10;
	
	struct Node* ptr=hashTable[index];
	int found=0;
	while(ptr){
		if(ptr->data==key){
			printf("key: %d found",ptr->data);
			found=1;
			break;
		}
		else{
			ptr=ptr->next;
		}
	}
	if(!found){
		printf("Key: %d not found!",key);
	}
	
}


int main(){
	int A[]={2,4,8,30,20,15,25,17,28,37};
	hash(A,10);

}