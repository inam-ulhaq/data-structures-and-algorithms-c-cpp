/*
 Title: Quick Sort
 Author: Inam Ul Haq

 Description:

    Assume that we have the following list of numbers:

        50, 70, 60, 90, 40, 80, 10, 20, 30

    and we want to sort this list using the Quick Sort technique.

    ---------------------------------------------------------
    FIRST PARTITION
    ---------------------------------------------------------

    Step 1:
    Select the first element as pivot.

        Pivot = 50

    Pivot is the element that will find its correct position in the list.
    All elements smaller than the pivot will be placed on the left side
    and all elements greater than the pivot will be placed on the right side.

    Step 2:
    Take two pointers:

        i ? start from the element next to pivot
        j ? start from the last element of the list

    ---------------------------------------------------------
    | 50 | 70 | 60 | 90 | 40 | 80 | 10 | 20 | 30 |
    ---------------------------------------------------------
      P    i                                   j


    Step 3:
    Move i toward the right until an element greater than pivot is found.

        i stops at 70

    Move j toward the left until an element smaller than or equal to pivot
    is found.

        j stops at 30

    Swap the elements at i and j.

    ---------------------------------------------------------
    | 50 | 30 | 60 | 90 | 40 | 80 | 10 | 20 | 70 |
    ---------------------------------------------------------
      P    i                                   j


    Step 4:
    Move i again.

        i moves from 30 to 60
        since 60 > 50, stop

    Move j again.

        j moves from 70 to 20
        since 20 < 50, stop

    Swap the elements at i and j.

    ---------------------------------------------------------
    | 50 | 30 | 20 | 90 | 40 | 80 | 10 | 60 | 70 |
    ---------------------------------------------------------
           P         i              j


    Step 5:
    Move i again.

        i stops at 90

    Move j again.

        j moves from 60 to 10
        since 10 < 50, stop

    Swap the elements at i and j.

    ---------------------------------------------------------
    | 50 | 30 | 20 | 10 | 40 | 80 | 90 | 60 | 70 |
    ---------------------------------------------------------
                P         i        j


    Step 6:
    Move i again.

        i moves from 10 to 40
        since 40 < 50 continue
        next element is 80 so stop

    Move j again.

        j moves from 90 to 40
        since 40 < 50 stop

    Now i becomes greater than j, so scanning stops.


    Step 7:
    Swap the pivot with element at position j.

    ---------------------------------------------------------
    | 40 | 30 | 20 | 10 | 50 | 80 | 90 | 60 | 70 |
    ---------------------------------------------------------

    Now pivot 50 is at its correct position.


    ---------------------------------------------------------
    SECOND PARTITION (LEFT SIDE)
    ---------------------------------------------------------

    Now apply Quick Sort on the left sublist:

        40, 30, 20, 10

    Pivot = 40

    ---------------------------------------------------------
    | 40 | 30 | 20 | 10 |
    ---------------------------------------------------------
      P    i         j

    Move i until element > 40 (none found)
    Move j until element <= 40

    j stops at 10

    Now i > j, so swap pivot with 10

    ---------------------------------------------------------
    | 10 | 30 | 20 | 40 |
    ---------------------------------------------------------

    Pivot 40 is fixed.


    ---------------------------------------------------------
    THIRD PARTITION
    ---------------------------------------------------------

    Now sort the sublist:

        30, 20

    Pivot = 30

    Swap 30 and 20

    ---------------------------------------------------------
    | 10 | 20 | 30 | 40 |
    ---------------------------------------------------------

    Left side is now completely sorted.


    ---------------------------------------------------------
    FOURTH PARTITION (RIGHT SIDE)
    ---------------------------------------------------------

    Now sort the right sublist:

        80, 90, 60, 70

    Pivot = 80

    ---------------------------------------------------------
    | 80 | 90 | 60 | 70 |
    ---------------------------------------------------------
      P    i         j

    i stops at 90
    j stops at 70

    Swap 90 and 70

    ---------------------------------------------------------
    | 80 | 70 | 60 | 90 |
    ---------------------------------------------------------

    Move i again ? stops at 90
    Move j again ? stops at 60

    Now i > j

    Swap pivot with 60

    ---------------------------------------------------------
    | 60 | 70 | 80 | 90 |
    ---------------------------------------------------------


    ---------------------------------------------------------
    FINAL SORTED LIST
    ---------------------------------------------------------

    | 10 | 20 | 30 | 40 | 50 | 60 | 70 | 80 | 90 |

*/