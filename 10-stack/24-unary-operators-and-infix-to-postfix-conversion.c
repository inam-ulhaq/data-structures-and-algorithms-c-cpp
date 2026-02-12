/*
 Title: Unary Operators & Infix to Postfix
 Author: Inam Ul Haq
 Description:
    Unary operators work on only one operand.
    Common ones:
        + Unary plus    : +A   (just shows positive)
        + Unary minus   : -A   (negation)
        + Logical NOT   : !A   (boolean NOT)
        + Increment    : ++A or A++
        + Decrement    : --A or A--
    Precedence: higher than most binary operators
    Associativity: right-to-left (do closest first)

 2. How to Convert Infix -> Postfix with Unary Operators
    Step 1: Parenthesize the expression fully
            - Use explicit parentheses
            - Follow operator precedence
            - Respect associativity
    Step 2: Start with unary operators (innermost first)
            - Write operand first, then unary operator
    Step 3: Handle binary operators next (according to precedence & associativity)
    Step 4: Repeat until expression is fully converted

 3. Examples

    - Infix: -A + B
      Parenthesized: ((-A) + B)
      Unary first: -A -> A -
      Combine with addition: ((-A) + B) -> A - B +
      Postfix: A - B +

    - Infix: A * -B
      Parenthesized: (A * (-B))
      Unary first: -B -> B -
      Combine: (A * (-B)) -> A B - *
      Postfix: A B - *

    - Infix: !A + B
      Parenthesized: ((!A) + B)
      Unary first: !A -> A !
      Combine: ((!A) + B) -> A ! B +
      Postfix: A ! B +

 4. Key Points
    - Unary operators have highest precedence after parentheses
    - Associativity is right-to-left
    - Postfix: always operands first, operator after
    - Parentheses only help decide order, they don't appear in postfix
*/
