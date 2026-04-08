/* Title: Linked Representation of Binary Tree
 Author: Inam Ul Haq
 Description:
	Linked representation mean we will be using nodes like nodes of linked
	list. Node structure will be contain on data and two pointers i.e. left
	child and right child.

		    +----------------------+
	Node = |L child| Data | R child|
	 	   +-----------------------+
	
	The node structure is same as like doubly linked list. This node will
	be contain on self refrencial structure i.e have pointers of it's own 
	type. We say this is linked representation not linked list representation 
	becuase list is linear data structure and tree is non linear data structure.
	i.e
	 
							+--------+
							| | A | |
							+-------+
						/             \
			+--------+                  +--------+
			| | B | |                   | | C | |
			+-------+				   +--------+	
			/		\	               /       \
+--------+        +--------+     +--------+      +--------+
|N| D |N|         |N| E |N|      |N| F |N|       |N| G |N|
+-------+	     +--------+		+--------+      +--------+

	This structure can be only created in heap. For n number of nodes 
	there will be n+1 NULL pointers in any structrue of binary tree.
	
*/						