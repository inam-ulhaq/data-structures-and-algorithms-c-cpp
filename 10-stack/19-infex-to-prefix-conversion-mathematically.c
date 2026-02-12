/*
 Title: Infix to Prefix Conversion (Mathematical Explanation)
 Author: Inam Ul Haq

 Description:
	Prefix notation is a way of writing mathematical expressions in which
	the operator is written before its operands. This form removes the
	need for brackets and precedence rules.

	Mathematically, converting an infix expression to prefix means deciding
	the order in which operations will be performed and then writing the
	operator before its operands according to that order.

 Basic Idea:
	In infix notation, the operator is written between operands:
		A + B

	In prefix notation, the operator is written before operands:
		+ A B

	The conversion is done by following the rules of precedence and
	associativity used in mathematics.

 Mathematical Rules Used:

	1. Brackets have the highest priority.
	   Any expression inside brackets is converted first.

	2. Operators with higher precedence are applied before lower
	   precedence operators.
	   For example:
	       * and / before + and -

	3. If operators have the same precedence, evaluation is done from
	   left to right.

 Conversion Method (Mathematical View):

	- Start from the innermost brackets.
	- Convert each small infix sub-expression into prefix form.
	- Replace the sub-expression with its prefix result.
	- Continue until the whole expression is converted.

 Example:
	Infix Expression:
		A + B * ( C - D )

 Step 1: Solve the bracket part first:
		( C - D ) ? - C D

	Expression becomes:
		A + B * - C D

 Step 2: Apply multiplication:
		B * ( - C D ) ? * B - C D

	Expression becomes:
		A + * B - C D

 Step 3: Apply addition:
		A + ( * B - C D ) ? + A * B - C D

 Final Prefix Expression:
		+ A * B - C D

 Conclusion:
	Mathematically, infix to prefix conversion is simply rewriting the
	expression according to the actual order of evaluation. Prefix notation
	makes this order explicit, removing the need for brackets and precedence
	rules.
*/
