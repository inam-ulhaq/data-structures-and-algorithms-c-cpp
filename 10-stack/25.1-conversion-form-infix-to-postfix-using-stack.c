/*
 Title: Infix to Postfix Conversion using Stack
 Author: Inam Ul Haq
 Description:
	The expression we will convert is:
		a + b * c - d / e
	Will try this simple infix expression to easily understand the way of for
	converting, then if we want we can also add other operators. Before to start
	conversion we will draw a precedence and associtivity table for the above 
	expression.
	assume that the operand have more precedence then all operators.
		
		 symbole |Precedence | associtivity
		-----------------------------------
		a,b,c,d,e| 		1	 |	L to R
		-----------------------------------
			*,/	 | 		2	 |	L to R
		-----------------------------------
			+,-	 | 		3	 |	L to R
		
	Now we will define some rules for push and pop operations to stack.
		-1 if the stack is empty we can push with any precedence.
		-2 if the top element in the stack having lower precedence then
			the next comming one then we can push.
		-3 if the top element having higher or same precedence then we will
			first pop the top element and send it into postfix expression then
			we can push the next comming elment to the stack.
		4 we will push till the equation ends, after ending we will pop whatever
			there in the stack, and send it into postfix expression.
			
	now let's convert it.
	given equation is:
		a + b * c - d / e
	current stack is -> stack=|empty
	current postfix is -> postfix|empty
	
	1- The first element is "a" here stack is empty so we will not check precdence,
		just push the element into stack.
	
	stack=|a 	&&  postfix=|
	
	2- the second element is +, So compeare it's precedence with +, their the top 
		element "a" having precedence 3 and + having 1 so first pop "a" from stack and 
		send to postfix, then push + to stack.
	
	stack=|+    && postfix=|a
	
	3- the third element "b" having precdence 3 and the top element "+" has precdence 1
		so we can push the "b" to stack.
	
	stack=|+|b    && posfix=|a
	
	4- fourth element is "*" which have less precedence i.e 2 then top element in stack which
		is "b" 3, so we will pop "b" and send to postfix then  again compeare the current element
		"*" with top element which is now "+", So "*" having higher precedence, now we can push.
		
	stack=|+|*   && posfix=|ab
	
	5- next element "c"	is again operand with 3 precdence and the top element "*" having 2 precdence
		so we can push,
	
	stack=|+|*|c   && posfix=|ab
	
	6- next element is "-" having percedence 1, compeare with top element "c" precedence i.e 3, so the 
		percdence is less therefore we will pop, and send it post.
	stack=|+|*   && posfix=|abc
		Now compare "-" with "*" again the percedence is less so we will pop again.
	stack=|+   && posfix=|abc*
		Now again compare with "-" with next top element "+", so its precdence is same we will pop again.
	stack=|   && posfix=|abc*+
		Now the stack is empty so we can push "-".
		
	stack=|-   && posfix=|abc*+

	7- the next element is "d" having percedence is "3" higher then top element so we will push it.
	
	stack=|-|d   && posfix=|abc*+
	
	8- then next element is "/"	having percedence is "2", compare with top element "d" with percdence 3.
		so its precendce is less then "d" therefore we will pop "d".
	stack=|-|   && posfix=|abc*+d
		then again we will compare with new top element which is "-" so "/" percdence is higher therefore
		we will push "/" to the stack.
		
	stack=|-|/   && posfix=|abc*+d
	
	9- the last element "e" with precedence 3 higher then top element "/" precedence i.e 2, so we will push.
	
	stack=|-|/|e   && posfix=|abc*+d
	
	10- Now the equation is ended so we will pop form and append it to postfix until the stack become empty.
	
		stack=|-|/   && posfix=|abc*+de
		
		stack=|-    && posfix=|abc*+de/
		
		stack=|    && posfix=|abc*+de/-
		
	So the stack become empty and the final postfix eqauation is ready.
	
		abc*+de/-
		
	I "Inam Ul Haq" wrote this in a deep night at 4:47 am.
	sitting alone in my room but working deeply.
*/