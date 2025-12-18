/*
 Title: Some Important Syntaxes for Linked List
 Author: Inam Ul Haq
 Description:
	  Let's head is pointer pointing the first node of a Linked list
		and a pointer of the same type i.e struct Node *ptr;
	  1) ptr=head
	 	 	This mean that what is there will be also in ptr pointer
	 		i.e if Head==0xFF, then ptr will be also ptr==0xFF
	  2) head=ptr->next;
	 		This mean that The head pointer will be now pointing on 
	 		the next node of ptr.
	  
	 Cheeking that while the pointer pointing to Null
		
		1) if(ptr==0) -> the condition will be true when the poiter 
	 		pointing to NULL
	 	2) if(ptr==NULL) -> This is also the same condition and will
	 		be true when the pointer pointing to NULL
	 	3) if(!Ptr) -> This condition doing the same stucks and cheek 
	  
	 cheeking while the pointer pointing to the valid node
	  1) if(ptr!=0) -> The condition will be true if the pointer is not
			NULL
	 	2) if(ptr!=NULL) -> The condition will be true if the pointer is not
			NULL
	  3) if(ptr!=0) -> The condition will be true if the pointer is not
			NULL
	 Moving the pointer to the next node
	  1) ptr= ptr->next  -> This statment will be move the same pointer 
	 		to the next node 
	  2) ptr= ptr->next->next -> ptr will double jumped i.e. skip one node in
	 the middle
*/