/*
 Title: m-way merging
 Author: Inam Ul Haq

 Description:
	Assume that we have 4 sorted lists and we are trying to merge them into
	a single list.

		-------------	    --------------	    --------------
	A | 2 | 10 | 18 |    B | 4 | 9 | 19 |	 C | 1 | 7 | 20 |
	  --------------	   --------------	   --------------
	    i					j					p


	   --------------		-----------------------------------------
	D | 3 | 6 | 25 | 	 E |   |   |   |   |   |   |   |   |   |   |
	  --------------	   -----------------------------------------
	    q					k

	In the first step we compare the first elements from all the lists and
	copy the smallest one into list E.

	Compare: 2, 4, 1, 3

	The smallest element is 1, therefore copy 1 to E[k] and increment p and k.

		-------------	    --------------	    --------------
	A | 2 | 10 | 18 |    B | 4 | 9 | 19 |	 C | 1 | 7 | 20 |
	  --------------	   --------------	   --------------
	    i					j						p


	   --------------		-----------------------------------------
	D | 3 | 6 | 25 | 	 E | 1 |   |   |   |   |   |   |   |   |   |
	  --------------	   -----------------------------------------
	    q						k

	Now in the second step again compare A[i], B[j], C[p], and D[q].

	Compare: 2, 4, 7, 3

	The smallest element is 2, therefore copy 2 to E[k] and increment i and k.

		-------------	    --------------	    --------------
	A | 2 | 10 | 18 |    B | 4 | 9 | 19 |	 C | 1 | 7 | 20 |
	  --------------	   --------------	   --------------
	    	i				j						p


	   --------------		-----------------------------------------
	D | 3 | 6 | 25 | 	 E | 1 | 2 |   |   |   |   |   |   |   |   |
	  --------------	   -----------------------------------------
	    q							k

	Continue this process with all the remaining elements.

	The final merged list will look like:

		----------------------------------------------------
	 E | 1 | 2 | 3 | 4 | 6 | 7 | 9 | 10 | 18 | 19 | 20 | 25 |
	   ----------------------------------------------------
															  k

	Since we are comparing 4 elements from 4 lists at a time and copying
	the smallest one into list E, this method is called 4-way merging.

---------------------------------------------------------------------

	Now suppose we compare elements from 3 lists at a time and merge them
	into a single list. This is called 3-way merging.

	Similarly, if we merge elements from m lists at a time into a single
	list, this method is called m-way merging.

---------------------------------------------------------------------

	Reduction to Two-Way Merging:

	In practice, instead of comparing many lists at once, we usually reduce
	the problem to two-way merging.

	For example, if we have four lists:

	A, B, C, D

	First merge A and B:

		A + B -> F

	Then merge C and D:

		C + D -> G

	Finally merge F and G:

		F + G -> Final List

	This approach repeatedly applies two-way merging until all lists are
	merged into one sorted list.

	This technique is used in the Merge Sort algorithm.
*/