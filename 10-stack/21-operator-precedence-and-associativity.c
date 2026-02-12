/*
 Title: Operator Precedence and Associativity (Implicit Parenthesization)
 Author: Inam Ul Haq
 Description:
	In computer science, arithmetic expressions written in infix form must be
	grouped before they can be evaluated. This grouping process is called
	parenthesization and is performed during parsing.

	If an expression already contains parentheses, the grouping is explicit.
	If parentheses are not present, the compiler or interpreter uses operator
	precedence and associativity rules to implicitly parenthesize the
	expression.

 Operator Precedence:
	Operator precedence determines how operators are grouped when parentheses
	are not explicitly written. Operators with higher precedence bind their
	operands more tightly and are grouped first.

	Common precedence order (highest to lowest):

		1. Parentheses      ( )
		2. Exponentiation   ^
		3. Multiplication   *   Division /
		4. Addition         +   Subtraction -

	Example:
		A + B * C

	Since multiplication (*) has higher precedence than addition (+), the
	expression is implicitly parenthesized as:

		A + ( B * C )

 Associativity:
	Associativity determines the grouping direction when two or more operators
	have the same precedence level.

	Most arithmetic operators are left associative, meaning grouping proceeds
	from left to right.

	Example:
		A - B + C

	This expression is implicitly parenthesized as:

		( A - B ) + C

	Some operators, such as exponentiation (^), are right associative.

	Example:
		A ^ B ^ C

	This expression is implicitly parenthesized as:

		A ^ ( B ^ C )

 Conclusion:
	Operator precedence and associativity are used during parsing to
	implicitly parenthesize infix expressions when explicit parentheses are
	not present. Once the expression is fully parenthesized, evaluation is
	performed according to this structure.
*/
