/*
 Title: Infix to Postfix Conversion using Stack (ISP & OSP Method)
 Author: Inam Ul Haq

 Description:
	The expression we will convert is:
		((a+b)*c)-d^e^f

	This program converts an infix expression into a postfix expression
	using a stack and the concept of:

	1- In-Stack Precedence (ISP)
	2- Out-Stack Precedence (OSP)

	The program supports:
		+  -  *  /  ^  ( )

 Important Notes:
	- Operands (a, b, c, d, e, f) are NOT pushed into the stack.
	- Operands are directly appended to the postfix expression.
	- Only operators and parentheses are pushed into the stack.
	- Right-to-left associativity of '^' is handled automatically
	  using ISP and OSP values.

 Operator Precedence Tables used in Program

 In-Stack Precedence (inStkPrece):

	Operator | ISP
	   + -   |  2
	   * /   |  4
	   ^     |  5
	   (     |  0

 Out-Stack Precedence (outStkPrece):

	Operator | OSP
	   + -   |  1
	   * /   |  3
	   ^     |  6
	   (     |  7
	   )     |  0

 Explanation:
	- Higher value means higher precedence
	- OSP(^) > ISP(^) ensures RIGHT to LEFT associativity
	- '(' has lowest ISP so nothing pops over it
	- '(' has highest OSP so it is always pushed
	- ')' forces popping until '(' is found

 Rules Followed by the Program

 1- If the scanned character is an operand,
   -> append it directly to postfix expression.

 2- If the scanned character is an operator or '(' :

   - If stack is empty,
     -> push the operator.

   - If OSP(current operator) > ISP(stack top),
     -> push the operator.

   - If OSP(current operator) == ISP(stack top),
     -> pop the stack top and discard it
        (used for matching parentheses).

   - If OSP(current operator) < ISP(stack top),
     -> pop from stack and append to postfix.
     -> repeat comparison.

 3- If the scanned character is ')',
   -> pop and append operators until '(' is found.
   -> pop '(' and discard it.

 4- After the expression ends,
   -> pop all remaining operators from stack
      and append them to postfix.

 Step-by-Step Conversion for ((a+b)*c)-d^e^f

 Given equation:
	((a+b)*c)-d^e^f

 Current stack -> stack=|empty
 Current postfix -> postfix=|empty

 1- First element is '('
   -> push '('

	stack=|(       && postfix=|

 2- Next element is '('
   -> push '('

	stack=|(|(     && postfix=|

 3- Next element is 'a'
   -> operand, append to postfix

	stack=|(|(     && postfix=|a

 4- Next element is '+'
   -> OSP(+) > ISP('('), push '+'

	stack=|(|(|+   && postfix=|a

 5- Next element is 'b'
   -> operand, append to postfix

	stack=|(|(|+   && postfix=|ab

 6- Next element is ')'
   -> pop until '('

	pop '+' -> postfix

	stack=|(|(     && postfix=|ab+

	pop '(' and discard

	stack=|(       && postfix=|ab+

 7- Next element is '*'
   -> OSP(*) > ISP('('), push '*'

	stack=|(|*     && postfix=|ab+

 8- Next element is 'c'
   -> operand, append to postfix

	stack=|(|*     && postfix=|ab+c

 9- Next element is ')'
   -> pop until '('

	pop '*' -> postfix

	stack=|(       && postfix=|ab+c*

	pop '(' and discard

	stack=|        && postfix=|ab+c*

 10- Next element is '-'
    -> stack empty, push '-'

	stack=|-       && postfix=|ab+c*

 11- Next element is 'd'
    -> operand, append to postfix

	stack=|-       && postfix=|ab+c*d

 12- Next element is '^'
    -> OSP(^) > ISP('-'), push '^'

	stack=|-|^     && postfix=|ab+c*d

 13- Next element is 'e'
    -> operand, append to postfix

	stack=|-|^     && postfix=|ab+c*de

 14- Next element is '^'
    -> OSP(^) > ISP(^), push '^'

	stack=|-|^|^   && postfix=|ab+c*de

  15- Next element is 'f'
    -> operand, append to postfix

	stack=|-|^|^   && postfix=|ab+c*def

 16- Expression ends
    -> pop remaining operators

	pop '^' -> postfix

	stack=|-|^     && postfix=|ab+c*def^

	pop '^' -> postfix

	stack=|-       && postfix=|ab+c*def^^

	pop '-' -> postfix

	stack=|        && postfix=|ab+c*def^^-

 Final Postfix Expression:
	ab+c*def^^-

 Conclusion

	This program demonstrates an efficient and professional
	approach to infix-to-postfix conversion using
	In-Stack and Out-Stack precedence.

*/
