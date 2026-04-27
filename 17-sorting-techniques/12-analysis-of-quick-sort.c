/*
 Title: Quick Sort Step-by-Step Explanation
 Author: Inam Ul Haq

 Description:

 EXAMPLE 1: RANDOM UNSORTED LIST (Best/Average Case)

 Let's take this list of numbers:

        40 10 50 20 30

 We will use the Quick Sort algorithm and always select the first element as the pivot.

 STEP 1:
 The first pivot is 40. We use two pointers (i and j) to partition the list.

 Compare and swap as needed:

 i moves over elements smaller than pivot:
    10 < 40 -> move
    50 > 40 -> stop

 j moves over elements greater than pivot:
    30 < 40 -> stop

 Swap the elements at i and j (50 and 30):

        40 10 30 20 50

 Continue scanning:

 i moves over 20 < 40 -> move
 50 > 40 -> stop
 j moves over 20 < 40 -> stop

 i > j -> stop partition
 Swap pivot 40 with A[j] = 30

 The list now looks like:

        30 10 20 40 50

 Pivot 40 is now at its correct position (index 3)

 Comparisons made in this step: 4

 STEP 2: Left sublist = 30 10 20
 Pivot = 30

 Partition:

 i = 10 < 30 -> move
 j = 20 < 30 -> stop
 Swap 10 and 20:

        30 20 10

 i > j -> stop partition
 Swap pivot 30 with A[j] = 20

 List after partition:

        20 10 30 40 50

 Comparisons in this step: 2

 STEP 3: Left sublist = 20 10
 Pivot = 20

 Partition:

 i = 10 < 20 -> move
 j = 10 < 20 -> stop
 i > j -> swap pivot 20 with A[j] = 10

 List after partition:

        10 20 30 40 50

 Comparisons in this step: 1

 STEP 4: Right sublist is empty -> done
 STEP 5: Right sublist of 40 = 50 -> single element, done

 Total comparisons for this example: 4 + 2 + 1 = 7

 Observation: Random unsorted lists usually give a balanced recursion tree and a time complexity of O(n log n)


 EXAMPLE 2: ALREADY SORTED LIST (Worst Case)

 Now, let's take an already sorted list:

        10 20 30 40 50

 Pivot selection: first element = 10

 STEP 1:

 Compare pivot 10 with the rest:

        10 vs 20, 10 vs 30, 10 vs 40, 10 vs 50

 Total comparisons = 4
 Partition result:

        () 10 (20 30 40 50)

 Left sublist: empty
 Right sublist: 20 30 40 50

 STEP 2:

 Pivot = 20

 Compare pivot 20 with remaining elements:

        20 vs 30, 20 vs 40, 20 vs 50

 Total comparisons = 3
 Partition: () 20 (30 40 50)

 STEP 3:

 Pivot = 30

 Compare with 40, 50 -> 2 comparisons
 Partition: () 30 (40 50)

 STEP 4:

 Pivot = 40
 Compare with 50 -> 1 comparison
 Partition: () 40 (50)

 STEP 5:

 Right sublist = 50 -> single element, done

 Total comparisons = 4 + 3 + 2 + 1 = 10
 Recursion tree is completely unbalanced -> Time complexity = O(n^2)

 Observation: Already sorted or reverse sorted lists give the worst case when the first element is always chosen as pivot


 SOLUTIONS TO AVOID THE WORST CASE

 1) Random Pivot:
    - Choose the pivot randomly from the current sublist.
    - Example: 10 20 30 40 50
      Random pivot = 30
      Partition: (10 20) 30 (40 50)
    - This ensures a more balanced partition -> O(n log n)

 2) Median-of-Three:
    - Choose the pivot as the median of the first, middle, and last element.
    - Example: 10 20 30 40 50
      first = 10, middle = 30, last = 50
      Pivot = 30
    - Partitions are now more balanced -> O(n log n)

 3) Shuffle the array before sorting:
    - Randomly shuffle the input list to avoid worst-case arrangement

 Using these techniques, Quick Sort rarely reaches O(n^2) and usually performs efficiently in practice.
*/