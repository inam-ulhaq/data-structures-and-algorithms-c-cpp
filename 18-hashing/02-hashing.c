
 Title: Hashing
 Author: Inam Ul Haq
 Description:

	Assume that I have a list of keys:
	A: 3, 5, 6, 2, 4, 8.
	
	If I store these keys in the same order inside an array, the data is not 
	sorted. Still, I can search for any element using linear search. In linear 
	search, I start from the first element and check one by one until I find 
	the required key. There is no need for the data to be in any specific order, 
	but the drawback is that it can take more time because in the worst case 
	I may have to check all elements.
	
	Now if I take the same keys and arrange them in sorted order like:
	 2, 3, 4, 5, 6, 8, then I can apply binary search. Binary search is faster 
	because instead of checking elements one by one, it repeatedly divides the 
	data into halves. However, the important condition here is that the data 
	must be sorted first. That means I have to do extra work before searching.
	So we are improving searching time, but at the cost of sorting.
	
	Now the question is: instead of checking elements one by one like in linear 
	search, or sorting first and then searching like in binary search, can we 
	directly go to the position of the element in one step? This idea leads to 
	hashing.
	
	In hashing, we do not search in the traditional way. Instead, we calculate 
	the position where the element should be stored. For this, we use an array 
	called a hash table, and a rule called a hash function.
	
	For example, if we use a simple hash function like
	h(x) = x
	then the key itself becomes the index. So key 3 is stored at index 3, key 5 
	at index 5, and so on. After placing all elements, each key is stored at 
	its corresponding index, and the remaining positions are empty.
	
	The main advantage appears during searching. If I want to search for key 5, 
	I do not need to check all elements or divide the array. I directly go to 
	index 5 and check whether the value is present or not. If it is present, 
	the key is found; otherwise, it is not present. So searching takes only 
	one step.
	
	The main concept is that every key has a fixed position, and that position 
	is calculated using a rule called a hash function. Because of this, we do 
	not actually search through the data, we directly jump to the location. 
	That is why hashing gives constant time.
	
	Now since we are using a function, it can have two types of mapping: one-to-one 
	and many-to-one. In the case of h(x) = x, this is one-to-one mapping, meaning 
	each key is stored in a unique position, and each position holds only one 
	key. This situation is called ideal hashing because searching is always 
	done in constant time without any conflict.
	
	But there is a problem. Suppose we only have 5 elements, but the largest 
	element is 8, so we need an array of size 9 (index 0 to 8). This may seem 
	fine here, but imagine if the largest key is 1000. Then we would need an 
	array of size 1001 just to store a few elements. This wastes a lot of 
	space. So the limitation of ideal hashing is high space consumption.
	
	This problem is caused by the hash function because it generates very large 
	indices. So we modify the rule. Instead of using h(x) = x, we use a new hash 
	function like
	h(x) = x % 10.
	
	Now consider the list: 2, 14, 18, 5, 28, 9, 10.
	
	Applying the hash function:
	
	Key    Index
	2%10   2
	14%10  4
	18%10  8
	5%10   5
	28%10  8
	9%10   9
	10%10  0
	
	Here, the largest index generated is 9. This is not just for this list, 
	but for any key, because when we take modulus 10, the remainder will always 
	be between 0 and 9. So the hash table size is fixed to 10, which saves space.
	
	However, a new problem arises. Two different keys, 18 and 28, both give the 
	same index 8. This means multiple keys are mapped to the same position. 
	This is called many-to-one mapping, and the situation is known as collision.
	
	So, collision happens when two different keys produce the same index using 
	the hash function.
	
	Now if the function is many to one then difinetly there is a chance of collision 
	and for solving that problem there are two major methods i.e open hashing and closed
	hasing.