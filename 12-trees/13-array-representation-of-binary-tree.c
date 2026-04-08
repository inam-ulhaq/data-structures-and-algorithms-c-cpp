/*
 Title: Representation of binary Tree
 Author: Inam Ul Haq
 Description:
	Binary tree can be represented on two ways:
	-1 Array based representation
	-2 Linked based representation

	Array  Based Representation of binary tree
		For storing  a binary tree we have to store two things about the
		the binary tree, storing all the elements of the tree and the 
		relationship between those elements (i.e child , parent), because
		if we store the relationship then we can back create the tree.
	Now 
		How to store the elements and relations of elements?
		For storing element we can take an array and then store them in that
		array. i.e i will store the elements level by level in array.
		
		
						 A
					   /  \
					  B    C
					 / \  / \
					D  E F  G
							
				 +---+---+---+---+---+---+---+
		   arr = | A | B | C | D | E | F | G |
				 +---+---+---+---+---+---+---+
				   1   2   3   4   5   6   7  ---> indices
		
		How to store realations ?
		For storing realtion the indices may helpful for us, let's analyise it.
		We will anaylyise this through table
		i.e

		+----------------------------------+
		|element | index | L child| R child|
		|   A    |  1    |    2   |   3    |
		|   B    |  2    |    4   |   5    |
		|   C    |  3    |    6   |   7    |
		+----------------------------------+
		
		When the element is at 1 then L child is at 2 and R child is at 3,
		when element is at 2 then it's L child is at 4 and R child is at 5,
		when element is at 3 then it's L child is at 6 and R child is at 7.
		if we analyise this then it looks like when the element is at i then
		their L child is at 2i and their R child is 2i+1 so yes form this we 
		can derive a formula. i.e
		
		If any element is at index i then It's 
		L child index = 2*i
		R child index = 2*i+1
		So these formula use for child relations of an element.
		
		Now what about parent relation.
		i.e F is child of c, and the index for F is 6 while for C is 3,
		now if we look to D is child of B, index for D is 4 while for B
		is 2. If we analyise this it's look like when we divide the child
		index by 2 it give us it parent index. So yes this is true.
		
		parent index = (child index)/2.
		
		But wait for filling the above array from the tree i didn't follow these
		formula's but i just fill it level by level? yes it works if you either
		follow these formulas or just fill it level by level it will work.
		
*/
		
		
		
		
		