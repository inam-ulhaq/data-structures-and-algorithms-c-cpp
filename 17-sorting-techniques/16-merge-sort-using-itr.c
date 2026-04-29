/*
 Title: Merge Sort using Iteration
 Author: Inam Ul Haq
 Description:
    Assume that I have a list i.e

        7, 2, 6, 3, 8, 1, 5, 4

    The problem is that this is an unsorted list containing 8 elements and
    we have to sort it. But the problem is that merge sort works on multiple
    sorted lists. So what do we need to do to make this comfortable for merge
    sort? First we have to convert this into multiple lists, and the second
    requirement is that these lists must be sorted.

    Now the question is: how can we divide this into multiple sorted lists?

    Let's try dividing the list into two lists:

        list1: 7, 2, 6, 3
        list2: 8, 1, 5, 4

    Oh! these lists are not sorted. This approach is wrong. Then what should
    we do?

    Let's try another method. Divide the list into n number of lists. This
    means if there are n elements in the list, then the number of lists will
    also be n. Since there are 8 elements in the list, we will convert the
    list into 8 lists:

        list1: 7
        list2: 2
        list3: 6
        list4: 3
        list5: 8
        list6: 1
        list7: 5
        list8: 4

    Now if we analyse these lists, we are getting both things: multiple lists
    and sorted lists. Each list contains only one element, and a single
    element is always considered sorted.

    Now the question is: how do we merge these lists into a single sorted
    list?

    Suppose we apply m-sorting directly, meaning 8-way sorting since we
    have 8 lists. In this case we would compare the first element of all
    the lists (although there is only one element in each list) and copy
    the smallest element into a new sorted list.

    But this is not a good approach because copying each element will take
    n units of time, and since there are n elements, the overall time will
    become n^2. This will behave more like Selection Sort.

    Then what should we do?

    Let's try the two-way sorting method and solve the problem in passes.

    First Pass:
        merge list1 with list2
        merge list3 with list4
        merge list5 with list6
        merge list7 with list8

        lists become:

        list1: 2, 7
        list2: 3, 6
        list3: 1, 8
        list4: 4, 5

    Second Pass:
        merge list1 with list2
        merge list3 with list4

        lists become:

        list1: 2, 3, 6, 7
        list2: 1, 4, 5, 8

    Third Pass:
        merge list1 with list2

        final list:
        1, 2, 3, 4, 5, 6, 7, 8
        
   Now Analysis:

    We sorted 8 elements in how many passes? Only 3 passes. If we observe
    carefully, 3 is actually log2(8). So the number of passes required to
    sort n elements will be log2(n).

    But is the time complexity only log n? No.

    Because in every pass we are dealing with all the elements of the list.
    That means in each pass we process n elements.

    Therefore the total work done will be:

        (number of passes) into   (work in each pass)
              log n * n

    So the overall time complexity of merge sort becomes:

        n log(n)
        
        
*/


#include <stdio.h>
void merge(int A[],int l,int mid, int h){
	int i,j,k;
	i=l,j=mid+1,k=0;
	int B[100];
	while(i<=mid && j<=h){
		if(A[i]<A[j]){
			B[k++]=A[i++];
		}else{
			B[k++]=A[j++];
		}
	}
	while(i<=mid){
		B[k++]=A[i++];
	}
	while(j<=h){
		B[k++]=A[j++];
	}
	for(i=l,k=0;i<=h;i++){
		A[i]=B[k++];
	}
}
void mergeSort(int A[],int n){
	
	int p,l,mid,h;
	for(p=2;p<=n;p=p*2){
		
		for(int i=0;i+p-1<n;i+=p){
			l=i;
			h=i+(p-1);
			mid=(l+h)/2;
			merge(A,l,mid,h);
			
		}
	}
	if(p/2<n){
		merge(A,0,p/2,h-1);
	}
	for(int i=0;i<n;i++){
		printf("%d ",A[i]);
	}
}

int main(){
	
	int A[]={7,2,6,3,8,1,5,4};
	mergeSort(A,8);
	
}