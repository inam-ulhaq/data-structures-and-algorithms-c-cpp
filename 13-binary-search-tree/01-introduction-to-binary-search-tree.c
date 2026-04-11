 Title: Binary Search Tree
 Author: Inam Ul Haq
 Description:
 	A binary tree in which for every node all elements in their left sub tree is smallar
 	then that node and all the elements in their right sub tree is greater than that node.
 	This tree is known as binary search tree becuase this is useful searching. i.e
 					
 						
 						50
 					  /   \
 				    40     60
 			       /  \    /  \
 				 35   45  55   70
 				 
  Now if i want to search the key =55 i have compare this key with root node i.e 50 so the key is
  greater than root i will goto right side child, now compare with 60 so key is less than
  60, So therefore i will goto left side of that node and finaly the key is found only in 3
  comparisons instead of searching the whole tree. So this is usefule for searching in less
  number of comparisions, and this behaviour is more like binary search but binary search is
  implemented on array but this is upon binary tree, so the search time defend on hight of tree.
  Bineary search tree will not have duplicates and if we take the inorder traversal of binary tree
  we get list of elements in sorted order. i.e.
  
 						50
 					  /   \
 				    40     60
 			       /  \    /  \
 				 35   45  55   70
 				 
 	inorder is left child -> parent -> right child.
 	inorder: 35, 40, 45, 50, 60, 55, 70
 	
 for n number of nodes only number of trees can be genarated is equal to catalon number.
 