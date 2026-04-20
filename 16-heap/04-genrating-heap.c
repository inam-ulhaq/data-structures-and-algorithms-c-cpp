 Title: Genrating Heap
 Author: Inam Ul Haq
 Description:
	Assume that we have a heap of three element i.e. 
					30
				   /  \
				  10   20
	and it store in array i.e.
	
	----------------------------
	| 30 | 10 | 20 |   |   |   | 
	----------------------------
	  1     2    3   4   5   6
	  
	This is heap now i want to insert new element into the array i.e. 50
	               |
	-----------------------------
	| 30 | 10 | 20 | 50 |   |   | 
	-----------------------------
	  1     2    3 | 4   5   6
	
	Now the left side of the array is max heap but the right side is not heap.
	can we insert that new key 50 to the max heap? yes we can by just arranging
	the elements in max heap. 
	Now let me extend the idea i.e insert tow more keys into the array.
	
	               |
	------------------------------
	| 30 | 10 | 20 | 50 | 15 | 4 | 
	------------------------------
	  1     2    3 | 4    5    6
	  
	Now the left side of the array is max heap and the right side elements are
	just there in the array but those are not in the heap. How to make that 
	also the part of heap? by just inserting them one by one in the heap using 
	a the following function:
		
	void insert(int A[],int n){
		int temp,i;
		i=n;
		temp=A[n];
		
		while(i>1 && temp>A[i/2]){
			A[i]=A[i/2];
			i=i/2;
		}
		A[i]=temp;
	}
	
	It's mean that by calling this function we can insert element form right side
	one by one and can include in the heap.So this mean that the first three elements
	in the heap will be also included like this, then how many elements will be there 
	intially in the heap? one element will be there. So this is the idea 'One by one 
	we inserting elements form left hand side to right hand side and go on creating a 
	heap'. So we don't need any extra array for creating a heap, within the array the 
	elements can be adjusted to form a heap. So that's how this is called Inplace heap
	creation, When it is happening inside the same array we called it inplace, So heap
	can be created inplace.
	
	Now i will take some element and try to genrate a heap form it.
		 |
	-----------------------------------
	| 10 | 20 | 30 | 25 | 5 | 40 | 35 |
	-----------------------------------
	  1  |   2    3   4    5   6    7   
	
	Consider the first element in the array is already heap and ignore all other
	elements. 
	Now let me insert the second element also in the heap. So i will call the insert()
	function on second element and it will adjust the element in the heap.
	i.e
			  | 
	-----------------------------------
	| 20 | 10 | 30 | 25 | 5 | 40 | 35 |
	----------------------------------- 
	  1     2 |   3   4    5   6    7   
	
	Daigramitically it will be like:
											20
										   /
										  10
	
    Now insert the thrid element in heap which is 30:
	
	---------------|-------------------
	| 30 | 10 | 20 | 25 | 5 | 40 | 35 |
	---------------|------------------- 
	  1     2    3   4    5   6    7   
	  
	Daigramitically it will be like:
											30
										   /  \
										  10   20
										  
	Now let me insert the 4 elmenet i.e. 25:
	
	--------------------|-------------
	| 30 | 25 | 20 | 10 | 5 | 40 | 35 |
	--------------------|------------- 
	  1     2    3   4    5   6    7
	     
	Daigramitically it will be shwon like:
											30
										   /  \
										  25   20
										 /
										10
    Note i suposing to just call the insert fuction the elements one by one 
    which we seen in first lessons and we also seen there how it will adjust 
    the elements for this.
    
    And I think this is quite enought to wirte a procedure for genrating heap
    now, and also let me finesh the rest work in one step.
    
	-----------------------------------
	| 40 | 25 | 35 | 10 | 5 | 20 | 30 |
	----------------------------------- 
	  1     2    3   4    5   6    7  
	  
	Daigramitically it will be shwon like:
											 40
										   /    \
										  25     35
										 /  \   /  \
										10	5  20  30
										
	So finally the heap will look like the above structre.
	
	
	Now let me write the procedure for genrating the max heap
	
	
	
	void insert(int A[],int n){
		int temp,i;
		i=n;
		temp=A[n];
		
		while(i>1 && temp>A[i/2]){
			A[i]=A[i/2];
			i=i/2;
		}
		A[i]=temp;
	}
	
	Note: we do this for index starting for 1 the array indexing is started here
	form zero, therefor we will keep index zero vecant.
	
	void create(){
		int A={0,10,20,30,25,5,40,35};
		for(int i=2;i<=7;i++){
			insert(A,i);
		}
	}
	
	I started form index 2 because we assume the first element in array is already
	heap.
	
	Analysis:
		As we know from first inserting one element take log(n) time but here
		we are inserting n elements so the time complexity of creating heap will
		be O(n-log (n)).
		
	And we do this only for max heap, by just chaning the conditions we can also
	converted this for min heap.


	
	
	
										
	
		
	  
	
	
