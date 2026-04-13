/*
 Title: How to Calculate Balance Factor for a Node
 Author: Inam Ul Haq
 Description:
 	For example we have tree given


									40
								  /    \
								30      60
							   /  \    /  \
							 20   35  50   70
							/      \    \    
						   10      38   55  
						   
						   
	Assume that Balance Factor is b.f, height of left sub tree is l.h and height of right
	tree is r.h.
						   
    Node	Height				    Balance Factor(b.f=l.h-rh)
	40   |  l.h is 3 and r.h is 3  | b.f=3-3=0
	30   |  l.h is 2 and r.h is 2  | b.f=2-2=0
	60   |  l.h is 2 and r.h is 2  | b.f=2-2=0
    20   |  l.h is 1 and r.h is 0  | b.f=1-0
    35   |  l.h is 0 and r.h is 1  | b.f=0-1=-1
	50   |  l.h is 0 and r.h is 1  | b.f=0-1=-1
	70   |  l.h is 0 and r.h is 0  | b.f=0-0=0
	10   |  l.h is 0 and r.h is 0  | b.f=0-0=0
    38   |  l.h is 0 and r.h is 0  | b.f=0-0=0
    55   |  l.h is 0 and r.h is 0  | b.f=0-0=0

	Actually the height is started form 0 but we counting it here form 1 becuse we are
	just cound edges just below that node.
	
	Now if we look to balance factors all of them are either 0, either 1 or either -1
	so the is height balance binary tree which is  consider as AVL Tree.
*/
    		