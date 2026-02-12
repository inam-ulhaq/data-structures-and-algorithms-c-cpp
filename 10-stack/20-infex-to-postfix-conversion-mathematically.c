/*
 Title: Conversion of Infix Expression (Conceptual Explanation)
 Author: Inam Ul Haq
 Description:
	Consider an arithmetic expression written in infix form, where operators
	appear between operands. To rewrite this expression in another form, we
	must first understand the actual order in which mathematical operations
	are performed.

	This order is decided by:
		1. Brackets
		2. Operator precedence
		3. Associativity (left to right for same precedence)

	The conversion process is purely mathematical. We do not apply any
	algorithm, stack, or programming technique here. We only follow the
	order of evaluation.

 Example:
	Given expression:
		A + B * ( C - D )

 Step 1: Identify the operation performed first.
	The expression inside the brackets is evaluated first:
		C - D

 Step 2: Write this operation with the operator placed before its operands:
		- C D

 Step 3: Substitute this result back into the expression:
		A + B * - C D

 Step 4: Identify the next operation according to precedence.
		Multiplication is performed next:
		B * ( - C D )

	Write it with operator before operands:
		* B - C D

 Step 5: Substitute again:
		A + * B - C D

 Step 6: Perform the remaining operation:
		A + ( * B - C D )

	Write it with operator before operands:
		+ A * B - C D

 Final Result:
		+ A * B - C D

 Conclusion:
	The conversion is done by following the mathematical order of evaluation.
	Each operator is written before its operands at the moment it is applied.
	This makes the execution order explicit and removes the need for brackets
	and precedence rules during evaluation.
*/
