 Title: Sparse Matrix
 Author: Inam Ul Haq
 Description:
 	A matrix is a two-dimensional data object made of m rows and n columns, 
	  therefore having total m x n values. If most of the elements of the 
	  matrix have 0 value, then it is called a sparse matrix.
	
	Example:
		
			|0 0 0 0 0 1 0|
	        |0 0 0 0 0 0 0|
	        |4 0 0 0 0 0 0|
	        |0 0 0 7 0 0 0|
	        |2 0 0 3 0 0 0|
	        |0 0 0 0 0 0 0|
	        |0 0 0 5 0 0 0|
	        
	
	Storage: There are lesser non-zero elements than zeros and thus lesser 
	 memory can be used to store only those elements.
	 
	Computing time: Computing time can be saved by logically designing a data 
	 structure traversing only non-zero elements.
	
 Representation:
 	There are two ways to represent a sparse matrix:
 	-1 Three columns representation/Cordinate List:
 		In cordiante list for every non-zero elemnts we need three things i.e. row
 		number, column number and the element itself. And need one row for the
 		information of whole matrix i.e. total number row, columns and non-zero elements.
 		
 	Example: Ther are 7 rows, 7 columns and 6 non-zero elements in the above example.
 	
 	rows | columns | elemenets
 	--------------------------
 	 7   |    7    |   6
 	--------------------------
 	 1   |    6    |   1
 	--------------------------
 	 3   |    1    |   4
 	--------------------------
 	 4   |    4    |   7
 	--------------------------
 	 5   |    4    |   3
 	--------------------------
 	 7   |    4    |   5
 	 
 		This is three columns representation of a sparse matrix.
 	
 -2 Compressed Sparse Rows (CSR):
     In this method the sparse matrix is represented using three arrays.

     1) Values Array:
        This array stores all non-zero elements of the sparse matrix
        in row-wise order.
        values[] = {1, 4, 7, 2, 3, 5}

     2) Column Index Array:
        This array stores the column numbers corresponding to each
        non-zero element in the values array.
        col_index[] = {6, 1, 4, 1, 4, 4}

     3) Row Pointer Array:
        This array stores the index in the values array where each
        row starts. Its size is (number of rows + 1).
        row_ptr[] = {0, 1, 1, 2, 3, 5, 5, 6}

     Using the row pointer array, we can easily locate all non-zero
     elements of any row without traversing the entire matrix.

     This is called Compressed Sparse Row (CSR) representation of
     a sparse matrix	