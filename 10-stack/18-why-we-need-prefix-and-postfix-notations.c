/*
 Title: Why We Need Prefix and Postfix
 Author: Inam Ul Haq

 Description:
 In mathematics and computer science, we usually write expressions in infix form,
 where operators are written between operands, for example:

     8 + 3 * (8 - 4) / 2 + 6 / 2

 Humans can easily evaluate such expressions because we know operator precedence
 rules (BODMAS / PEMDAS):
     1. Brackets
     2. Division and Multiplication (left to right)
     3. Addition and Subtraction (left to right)

 Evaluating the above expression step by step:
     8 + 3 * (8 - 4) / 2 + 6 / 2
     8 + 3 * 4 / 2 + 6 / 2
     8 + 12 / 2 + 3
     8 + 6 + 3
     17

 For humans, this is simple. But for a computer, infix expressions create a problem.
 A program must:
     - Check brackets first
     - Then find higher-precedence operators
     - Scan the expression multiple times
     - Jump back and forth in the expression

 This makes infix evaluation complex and time-consuming for computers.

 To solve this problem, prefix and postfix notations were introduced.
 In these notations:
     - Operator precedence rules are not needed
     - Brackets are not required
     - Expressions can be evaluated in a single scan using a stack

 Example:
     Infix:   8 + 3
     Postfix: 8 3 +

 Because of these advantages, prefix and postfix notations are widely used in
 compilers and expression evaluation algorithms.
*/
