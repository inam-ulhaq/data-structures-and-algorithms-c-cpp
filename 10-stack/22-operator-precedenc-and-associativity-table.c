/*
 Title: Table for Operator Precedence and Associativity 
 Author: Inam Ul Haq
 Description:
	In computer science, infix expressions must be grouped before evaluation.
	Parentheses define explicit grouping. If parentheses are absent, the
	parser uses operator precedence and associativity to implicitly
	parenthesize the expression.

 Operator Precedence and Associativity Table:

	| Precedence | Operators       | Associativity      | Description                     |
	|------------|----------------|------------------|---------------------------------|
	| 1          | ( )            | N/A              | Parentheses, highest priority   |
	| 2          | ^              | Right-to-Left    | Exponentiation                  |
	| 3          | * , /          | Left-to-Right    | Multiplication, Division        |
	| 4          | + , -          | Left-to-Right    | Addition, Subtraction           |
	| 5          | =              | Right-to-Left    | Assignment                      |
	| 6          | <, <=, >, >=   | Left-to-Right    | Relational operators            |
	| 7          | ==, !=         | Left-to-Right    | Equality operators              |
	| 8          | &&             | Left-to-Right    | Logical AND                     |
	| 9          | ||             | Left-to-Right    | Logical OR                      |

 Examples:

	1. A + B * C -> ( A + ( B * C ) )  // '*' higher precedence than '+'
	2. A - B + C -> ( ( A - B ) + C )   // Left-to-right associativity
	3. A ^ B ^ C -> ( A ^ ( B ^ C ) )   // Right-to-left associativity

 Conclusion:
	The table shows how different operators are prioritized and grouped
	when parentheses are absent. Precedence and associativity are used
	to implicitly parenthesize expressions for correct evaluation.
*/
