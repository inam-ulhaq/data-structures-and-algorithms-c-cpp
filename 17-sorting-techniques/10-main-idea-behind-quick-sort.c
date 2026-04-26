/*
 Title: Idea Behind Quick Sort
 Author: Inam Ul Haq

 Description:
    Assume that we have three lists:

        list 1: 10, 20, 30, 70, 40, 90, 80
        list 2: 80, 70, 40, 30, 20, 10, 90
        list 3: 40, 30, 20, 50, 90, 70, 80

    Now suppose I ask a question: tell me one element in the first list
    which is already in its sorted position.

    In list 1, the answer is 10. This is correct because 10 is the smallest
    element and it is already at the beginning of the list.

    Now the second question: which element is already sorted in the
    second list?

    The answer is 90. This is correct because 90 is the largest element
    and it is placed at the end of the list.

    Now consider the third list: 40, 30, 20, 50, 90, 70, 80

    Which element is already in the correct sorted position?

    The answer is 50. The reason is that all the elements on the left side
    of 50 are smaller than 50, and all the elements on the right side are
    greater than 50. Therefore, 50 is already at its correct position in
    the sorted list.

    The same logic can also be applied to the first and second lists.

    In list 1, 10 is sorted because all the elements greater than 10 are
    on the right side, and there is no element smaller than 10 to place
    on the left side.

    In list 2, 90 is sorted because all the elements smaller than 90 are
    on the left side, and there is no greater element to place on the
    right side.

    Now let us summarize the main idea.

    Quick Sort works on the idea that an element is in its sorted position
    if all the elements before it are smaller and all the elements after
    it are greater. When this condition is satisfied, we say that the
    element is in its correct sorted position.

    Example (Real Life Analogy):

    Suppose there are some students with different heights in a school,
    and a teacher wants them to stand in a line in increasing order of
    their heights.

    The teacher has two options.

    Option 1:
    The teacher decides the exact position of every student and places
    them one by one in the correct order.

    Option 2:
    The teacher asks the students to arrange themselves according to
    their heights.

    Obviously, the second option is faster because students can quickly
    find their appropriate positions.

    You might have heard teachers saying:
    "Students, quickly form a line according to your heights."

    Now how will the students arrange themselves?

    Assume that you are a student. Where will you stand in the line?
    You should stand in such a position that all students shorter than
    you are on your left side and all students taller than you are on
    your right side.

    This means you try to find your correct position in the line.
    To do this, you compare your height with other students and adjust
    yourself until you reach the correct position.

    This is exactly the approach used in Quick Sort. Elements compare
    themselves with others and try to move toward their correct positions.

    One important thing to remember is that the name "Quick Sort"
    does not mean that it is always the fastest sorting algorithm.
    However, in many practical situations it performs very efficiently.

    Quick Sort is called "Quick" because it quickly places elements
    into their correct positions by partitioning the list around a pivot.
*/