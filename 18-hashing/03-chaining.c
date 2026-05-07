/*
Title: Chaining
Author: Inam Ul Haq

Description:

	Chaining is a technique used in hashing to handle collisions. 
	A collision occurs when two or more keys map to the same index 
	in a hash table. In chaining, each index stores a linked list 
	(or chain) of elements instead of trying to find another empty slot.
	
	Load Factor (lambda, ?):
	- ? = n / m, where n = number of keys, m = size of the hash table.
	- Represents the average number of keys per slot.
	- A lower ? means shorter chains and faster operations.
	- ? is used to estimate average case performance in chaining.
	- When ? is kept small, search, insertion, and deletion are close to O(1).
	
	Example:
	
	Keys: 16, 12, 25, 39, 6, 122, 5, 68, 75
	Hash Function: h(x) = x % 10
	Assume hash table size m = 10
	
	Step 1: Insert 16
	    Compute hash: h(16) = 16 % 10 = 6
	    Index 6 is empty ? insert directly.
	    Table:
	    Index   Data
	    0
	    1
	    2
	    3
	    4
	    5
	    6       16
	    7
	    8
	    9
	    Explanation: Best case occurs here because the slot was empty. Load factor ? = 1/10.
	
	Step 2: Insert 12
	    Compute hash: h(12) = 12 % 10 = 2
	    Index 2 is empty ? insert directly.
	    Table:
	    Index   Data
	    0
	    1
	    2       12
	    3
	    4
	    5
	    6       16
	    7
	    8
	    9
	    Explanation: Still no collision. ? = 2/10 = 0.2.
	
	Step 3: Insert 25
	    Compute hash: h(25) = 25 % 10 = 5
	    Index 5 is empty ? insert directly.
	    Table:
	    Index   Data
	    0
	    1
	    2       12
	    3
	    4
	    5       25
	    6       16
	    7
	    8
	    9
	    Explanation: No collision, best case continues.
	
	Step 4: Insert 39
	    Compute hash: h(39) = 39 % 10 = 9
	    Index 9 is empty ? insert directly.
	    Table:
	    Index   Data
	    0
	    1
	    2       12
	    3
	    4
	    5       25
	    6       16
	    7
	    8
	    9       39
	    Explanation: No collision, ? = 4/10 = 0.4.
	
	Step 5: Insert 6
	    Compute hash: h(6) = 6 % 10 = 6 ? collision
	    Index 6 has 16 ? append 6 to chain.
	    Table:
	    Index   Data
	    0
	    1
	    2       12
	    3
	    4
	    5       25
	    6       16 -> 6
	    7
	    8
	    9       39
	    Explanation: First collision occurs. ? = 5/10 = 0.5. Average case starts to appear.
	
	Step 6: Insert 122
	    Compute hash: h(122) = 122 % 10 = 2 ? collision
	    Index 2 has 12 ? append 122 to chain.
	    Table:
	    Index   Data
	    0
	    1
	    2       12 -> 122
	    3
	    4
	    5       25
	    6       16 -> 6
	    7
	    8
	    9       39
	    Explanation: Chain length = 2 at index 2. Average case continues. ? = 6/10 = 0.6.
	
	Step 7: Insert 5
	    Compute hash: h(5) = 5 % 10 = 5 ? collision
	    Index 5 has 25 ? append 5 to chain.
	    Table:
	    Index   Data
	    0
	    1
	    2       12 -> 122
	    3
	    4
	    5       25 -> 5
	    6       16 -> 6
	    7
	    8
	    9       39
	    Explanation: Another chain grows. Average search time now depends on chain length. ? = 7/10 = 0.7.
	
	Step 8: Insert 68
	    Compute hash: h(68) = 68 % 10 = 8
	    Index 8 is empty ? insert directly.
	    Table:
	    Index   Data
	    0
	    1
	    2       12 -> 122
	    3
	    4
	    5       25 -> 5
	    6       16 -> 6
	    7
	    8       68
	    9       39
	    Explanation: No collision here. ? = 8/10 = 0.8.
	
	Step 9: Insert 75
	    Compute hash: h(75) = 75 % 10 = 5 ? collision
	    Index 5 has 25 -> 5 ? append 75.
	    Table:
	    Index   Data
	    0
	    1
	    2       12 -> 122
	    3
	    4
	    5       25 -> 5 -> 75
	    6       16 -> 6
	    7
	    8       68
	    9       39
	    Explanation: Longest chain appears at index 5. ? = 9/10 = 0.9.
	
	Final Table:
	Index   Chain
	0
	1
	2       12 -> 122
	3
	4
	5       25 -> 5 -> 75
	6       16 -> 6
	7
	8       68
	9       39
	
	Conceptual Analysis:
	
	Best Case:
	- Element is found immediately at the computed hash index without traversing a chain.
	- Occurs when each key hashes to a unique slot.
	- Time complexity: O(1).

	Average Case:
	- Keys are assumed to be evenly distributed among all slots.
	- Each chain has length approximately equal to ? = n/m.
	- Search requires traversing chain at hash index.
	- Time complexity: O(1 + ?), which is much smaller than O(n) if ? is small.

	Worst Case:
	- All keys hash to the same index, forming a single long chain.
	- Time complexity: O(n) because entire chain must be traversed.
	- This occurs with a poor hash function or when table size is too small relative to number of keys.

	Role of Load Factor:
	- Maintaining ? small ensures short chains and faster average case operations.
	- As ? increases, chains become longer and average search time increases.
	- Proper table sizing and a good hash function distribute keys evenly, minimizing ? and improving performance.
*/  