/*
Title: Linear Probing
Author: Inam Ul Haq

Description:

    Linear Probing is a technique used in hashing to resolve collisions. 
    A collision occurs when two or more keys hash to the same index in a hash table.
    Instead of using linked lists (like in chaining), linear probing handles collisions 
    by checking the next available slot sequentially. It "probes" the table linearly (hence the name) 
    until an empty slot is found.

    Key Concepts:
    1. Hash Function: A hash function is used to calculate the index where each key should be stored.
    2. Collision Resolution: If the computed index is occupied, linear probing checks the next index (i + 1) until it finds an empty slot.
    3. Load Factor: The performance of linear probing depends on the load factor, which is the ratio of keys to slots in the hash table. A high load factor causes more collisions.

    Steps for Linear Probing:
    - When inserting a key, compute its index using the hash function.
    - If the index is empty, place the key at that index.
    - If the index is occupied (collision), check the next index (index + 1) and keep checking until an empty slot is found.
    - Wrap-around: If you reach the end of the table, wrap around to the beginning and continue probing.

    Example:

    Keys: [15, 25, 35, 45]
    Hash Table Size: m = 10
    Hash Function: h(x) = x % 10

    Step-by-step Example:

    1. Insert 15:
       - Compute hash: h(15) = 15 % 10 = 5.
       - Index 5 is empty ? insert 15 at index 5.
       - Table: [_, _, _, _, _, 15, _, _, _, _]

    2. Insert 25:
       - Compute hash: h(25) = 25 % 10 = 5.
       - Index 5 is occupied by 15 ? check next index (6).
       - Index 6 is empty ? insert 25 at index 6.
       - Table: [_, _, _, _, _, 15, 25, _, _, _]

    3. Insert 35:
       - Compute hash: h(35) = 35 % 10 = 5.
       - Index 5 is occupied by 15, index 6 is occupied by 25 ? check next index (7).
       - Index 7 is empty ? insert 35 at index 7.
       - Table: [_, _, _, _, _, 15, 25, 35, _, _]

    4. Insert 45:
       - Compute hash: h(45) = 45 % 10 = 5.
       - Index 5 is occupied by 15, index 6 is occupied by 25, index 7 is occupied by 35 ? check next index (8).
       - Index 8 is empty ? insert 45 at index 8.
       - Final Table: [_, _, _, _, _, 15, 25, 35, 45, _]

    Key Concepts in Linear Probing:
    
    1. Clustering: Linear probing may cause primary clustering. This means that when multiple keys hash to the same index or adjacent indexes, the probe sequence becomes longer, reducing efficiency.
    2. Table Resizing: When the table is nearly full (i.e., the load factor is high), the performance of linear probing declines. In such cases, it's common to resize the table (double its size) and rehash the keys.

    Best Case:
    - No collisions occur.
    - Each key hashes to a unique index.
    - Time Complexity: O(1) for insertion and searching, because there's no need to probe for an empty slot.

    Average Case:
    - Keys are evenly distributed across the table.
    - Time Complexity: O(1 + a), where a is the load factor (n/m). For a small load factor, the time complexity remains close to O(1).

    Worst Case:
    - The table is nearly full, causing many collisions.
    - Time Complexity: O(n), where n is the number of keys. If most slots are full, the algorithm may need to probe almost every slot.

    Performance:
    - Good for small load factors and smaller tables.
    - Degrades when the load factor becomes large (i.e., more than 70-80% full).

    Comparison to Other Methods:
    - Chaining: In chaining, collisions are handled by storing the keys in a linked list at each index. Linear probing uses only one array (no extra memory), but can suffer from clustering.
    - Resizing: Linear probing often requires resizing the hash table to avoid clustering, which incurs extra cost.

    In conclusion, linear probing is a simple and efficient collision resolution method for hash tables, but it can suffer from performance degradation due to clustering when the table is too full.

    Example of Linear Probing in Code:

    // Define the hash table size
    int tableSize = 10;
    
    // Array representing the hash table
    int hashTable[tableSize];
    
    // Initialize the table with empty values (-1)
    for (int i = 0; i < tableSize; i++) {
        hashTable[i] = -1;
    }
    
    // Insert function using linear probing
    void insert(int key) {
        int index = key % tableSize;
        while (hashTable[index] != -1) {
            index = (index + 1) % tableSize;  // Linear probing
        }
        hashTable[index] = key;
    }
    
    // Search function using linear probing
    int search(int key) {
        int index = key % tableSize;
        while (hashTable[index] != -1) {
            if (hashTable[index] == key) {
                return index;  // Key found
            }
            index = (index + 1) % tableSize;  // Linear probing
        }
        return -1;  // Key not found
    }
*/