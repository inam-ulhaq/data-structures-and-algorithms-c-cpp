/*
 Title: Conversion from Infix to Postfix After Parenthesization
 Author: Inam Ul Haq
 Description:
	To convert an infix expression to postfix:
	1. First, handle parentheses, precedence, and associativity to determine 
	   the exact order of operations (implicit parenthesization).
	2. Then, write each operation after its operands instead of between them.

 Rule of thumb:
	- Postfix (RPN): operand1 operand2 operator
	- Left-to-right associativity -> process leftmost first
	- Right-to-left associativity -> process rightmost first

 Example 1:

	Infix: A + B * C
	Step 1: Check parentheses -> none
	Step 2: Check precedence:
			 * > +, so B * C happens first
			 -> Implicit parenthesized: (A + (B * C))
	Step 3: Convert to postfix:
			 - B * C -> B C *
			 - Then (A + (B * C)) -> A B C * +
	Postfix: A B C * +

 Example 2:

	Infix: (A + B) * C
	Step 1: Parentheses first -> (A + B)
	Step 2: Convert inside parentheses to postfix:
			 A + B -> A B +
	Step 3: Then multiply by C:
			 ((A + B) * C) -> A B + C *
	Postfix: A B + C *

 Example 3:

	Infix: A ^ B ^ C
	Step 1: Exponentiation is right-to-left
			 -> Implicitly parenthesized: (A ^ (B ^ C))
	Step 2: Convert to postfix:
			 B ^ C -> B C ^
			 Then (A ^ (B ^ C)) -> A B C ^ ^
	Postfix: A B C ^ ^

 Summary Steps:
	1. Parenthesize expression using precedence & associativity
	2. Start with innermost operations
	3. Write operands first, then operator for each operation
	4. Continue until full expression is converted
*/
