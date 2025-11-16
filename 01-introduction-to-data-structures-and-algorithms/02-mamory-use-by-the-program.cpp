/*
Title: Main Memory and their usage by Program
Author: Inam Ul Haq
Description:
	Main Memory:
		Main memory is a collection of addressable units called bytes,
		each with a unique linear address, used to store data and program 
		instructions that the CPU actively uses. It serves as the primary 
		workspace of the computer during program execution, holding 
		variables, arrays, objects, the stack, the heap, and the code 
		segment.
	How a Program Uses Memory

		Code Section:
			When we run a program, the first step is to load the program code
			into the code section of memory. The code section is not fixed in size;
			its size depends on the size of the program. Once the code is loaded,
			it starts managing and utilizing other memory segments that can be used
			by the program during execution.
	
		Stack Segment:
			Static memory allocation means that the compiler decides the size
			of memory during compilation, not at runtime. This memory is not
			allocated immediately at compile time, but the compiler determines
			how much memory will be needed.
			
			Memory that is statically allocated in the program is stored in
			the stack segment of main memory. It is called a stack because
			it behaves similarly to the stack data structure (LIFO - Last In, First Out).
			
			The program uses the stack segment to store function call frames
			(also called stack frames or activation records). Each activation
			record of a function contains:
			  - Local variables
			  - Function parameters
			  - Return address of the function call
			
			The lifetime of an activation record depends on the function scope.
			When the function ends, its activation record is automatically deleted.
			
			Memory can be allocated in the stack as follows:
			  - data_type variableName;      -> allocates a single variable
			  - data_type arrayName[size];   -> allocates an array
			  
			  
		Heap Segment:
			Run-time or dynamic memory allocation means the size of the memory
			will be decided by the compiler at run time of the program, not at 
			compilation time. It can be stored in a segment of memory called 
			the heap.

			Heap memory can be treated as a resource by the program, just like 
			the program uses other resources, for example a printer. First, the 
			program will request the printer, use it, and when it is free, the 
			program will release it. In the same way, the program will request 
			heap memory, use it, and when it is no longer needed, it should 
			release it.

			Heap memory cannot be accessed directly by the program, but it can 
			be accessed through pointers.
		Data Segment:
			Data segment is a portion of the main memory that stores global 
			and static variables which are explicitly initialized with a 
			non-zero value. These variables exist for the entire duration of 
			program execution, meaning they are created when the program 
			starts and destroyed only when the program terminates. Because 
			of this, the data segment allows variables to be accessed from 
			anywhere in the program after their declaration. Variables in 
			this segment are stored in a fixed location, and their values 
			remain persistent throughout the program’s runtime. Examples of 
			variables stored in the data segment include a global initialized 
			variable like int g = 10; and a static initialized variable like 
			static int x = 5;. The data segment plays a critical role in 
			storing program-level persistent data that must retain its value 
			across function calls and throughout the execution of the program.
			
		Constant Segment:
			Constant segment is a part of the main memory that stores 
			read-only constants used in the program. Variables stored in 
			this segment cannot be modified during program execution, 
			which helps protect the integrity of constant data. Some compilers
			may place the constant segment inside the text segment along with 
			the program code. Examples include constants like const int PI = 3.14; 
			or other fixed values that should remain unchanged. The constant 
			segment ensures that important fixed data remains consistent and 
			cannot be accidentally altered by the program.
			
		String Literal Pool:
			String literal pool is a part of the main memory that stores all 
			string values written in double quotes in a program. These strings 
			are read-only, meaning the program cannot change them while running. 
			The system often stores the same string only once in this pool, so 
			if the same text is used multiple times, it shares the same memory, 
			saving space. For example, the string "Hello World" would be stored 
			in the pool. This pool helps the program manage and protect text data 
			efficiently.
			
----------------------------------------------------
Typical Layout (Top to Bottom in memory):

    High Addresses
    ---------------------------
    |        Stack            |
    | (local variables, calls)|
    ---------------------------
    |         Heap            |
    | (dynamic allocations)   |
    ---------------------------
    |         BSS             |
    | (uninitialized globals) |
    ---------------------------
    |         Data            |
    | (initialized globals)   |
    ---------------------------
    |         Text            |
    | (machine instructions)  |
    ---------------------------
    Low Addresses

*/		 