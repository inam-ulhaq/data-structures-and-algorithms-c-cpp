#include <stdio.h>
#define SIZE 10

int linearProb(int HT[],int index){
	
	int i=1;
	while(HT[index+i]!=0)
		i++;
	return (index+i);
}

int hash(int key){
	return key%SIZE;
}

void insert(int HT[],int key){
	int index=hash(key);
	if(HT[index]!=0)
		index=linearProb(HT,index);
		HT[index]=key;
}

int search(int HT[],int key){
	int index=hash(key);
	if(HT[index]==key)
		printf("key %d found at index %d",HT[index],index);
	else{
		int i=0;
		while(i<SIZE && (HT[index+i]!=key && HT[index+i]!=0))
			i++;
		if(i<SIZE && HT[index+i]==key)
			printf("key %d found at index %d",HT[index],index);
		else
			printf("key not found!");

	}
}

int main(){
	int HT[SIZE]={0};
	insert(HT,23);
	insert(HT,27);
	insert(HT,23);
	insert(HT,13);
	insert(HT,20);
	insert(HT,30);
	
	search(HT,27);
	
	
} 