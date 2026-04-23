 Title: Insertion Sort
 Author: Inam Ul Haq
 Description:
	This is one of the important sorting technique, for understanding the insertion
	sort we must understand the name insertion is taken. If we understand that
	then the sorting become very easy. So insertion mean what? For understanding
	this i will take a list of elements and stored it in array in sorted form.
	i.e. 
	--------------------------------
	| 2 | 6 | 10 | 15 | 20 | 25 |  |
	--------------------------------
	
	and a new key i.e 13 to inserting in the list. So it should be inserted in 
	way where it should come in a sorted position. So here inserting mean inserting
	an element in a sorted in a sorted position. Now let's insert 13, so it should
	be inserted? In a position where all the element in the right side are greater
	while on the left side are smaller. i.e between 10 and 5. but there is no space
	between 10 and 15? So we should to shift the elements from to right side. Which 
	elements should be shifted? all the elmenet that are greater than 13 i.e
	
	--------------------------------
	| 2 | 6 | 10 |  | 15 | 20 | 25 |
	--------------------------------
	Now what i did? First i found the position of insertion of 13 i.e between 10 and 
	15, then I shift the elements. But the important thing here is we don't need to
	find the position first, but we can dirtectly start shifting i.e. compare 25 with 
	13, 25 is greater, ok shift it, now compare 20 with 13 and again 20 is greater so
	we will shift again and shift till the comparing element is greater then key. now 
	when we are come to 10 and compare it with 13 so 10 is not greater then 13 therefore
	we will not shift but insert the element after 10 i.e.
	
	----------------------------------
	| 2 | 6 | 10 | 13 | 15 | 20 | 25 |
	----------------------------------
	So i don't need to search and find out it's position but from the last going on 
	and shifting the largest elements and whenever a smaller element come then don't
	shift but insert the element there. So all the larger elements are shift to right
	side and insert the element. So that's all about inserting in array.
	
 Now let's insert in linked list:
	So I will take a linked list i.e:
		
	-----        -----      ------      ------      ------      
	|2| | --->   |6| | ---> |10| | ---> |15| | ---> |20| |  
	-----		 -----      ------      ------      ------  
	So this is a singly linked list and this is the list of sorted elements.
	And in this list I want to insert 18, So in a linked list i don't have to
	shift the elements, so as shifting is not requird then I have to find the 
	position of element and insert the new node by modifiying the links.
	i.e. here in the above linked list the position of new node 18 is between
	15 and 20. So I modified like this:
	
	-----        -----      ------      ------      ------	   ------      
	|2| | --->   |6| | ---> |10| | ---> |15| | ---> |18| |---> |20| |  
	-----		 -----      ------      ------      ------     ------ 
	
	So how to find the position of new node? For finding the position of new 
	node i will take a pointer on first for travarsing the linked list and 
	also one tail pointer i.e pointer p pointing on node 2 and a tail pointer
	pointing null at the very starting. Now compare p's data with 18 i.e 2 with
	18 so 18 is greater therefore move the pointer p to next node, but before 
	this i will assigain the address store in p to tail pointer q, so now  q
	will hold the address of node 2 and p will hold the address of node 6. This 
	will contineoue till p's data become greater then new key i.e p pointing on 
	node 20 here, so as q follow pointer p therefore it will pointing on 18. So 
	now as the p's data is greater and q's data is less than new key therefore 
	this is the perfect position of new node i.e 18. therefore we insert it there.
	So this is how we are inserting an element in linked list in sorted position.
	
	Now i you in array are not finding the position but start shifting and perfect 
	position come automatically while shift the elements. And in linked list we 
	don't shif the elements but find sutible position and insert the elements by 
	modifying the the nodes.
	
	Analysis:
		How much time insertion taking in array and linked list?
		in array we are shifting the element, so shifting how many element?
		in worst case n while in best case no element so therefore we will 
		say the minimume time here is constant i.e O(1) while the maximume 
		time is O(n).
		And in linked list we are traversing the element, so again how many 
		elements? again in worst case n and in best case no elements. this is
		also taking O(1) in best case while O(n) in worst case.

		
 
	