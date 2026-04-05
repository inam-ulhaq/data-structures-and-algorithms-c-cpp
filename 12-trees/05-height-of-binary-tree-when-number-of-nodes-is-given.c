/*
 Title: Height of a Binary Tree When Number of Nodes Is Given
 Author: Inam Ul Haq
 Description:
    In a binary tree, each node can have at most two children.
    When the total number of nodes (n) in a binary tree is fixed,
    the height of the tree depends on how the nodes are arranged.
    There are two extreme cases:
        1) Minimum height
        2) Maximum height


    Maximum Height of a Binary Tree

    The maximum height occurs when the binary tree is skewed
    (left-skewed or right-skewed). In this structure, each node
    has only one child, so the tree grows in a single direction
    like a linked list.

    Example Structure (Skewed Binary Tree):

            A
           /
          B
         /
        C
       /
      D

    Analysis:
        - Each node contributes exactly one level.
        - The tree grows linearly.
        - For n nodes, there are n - 1 edges.
        - Height is measured in number of edges.

    Formula:
        Maximum height = n - 1


    Minimum Height of a Binary Tree

    The minimum height occurs when the binary tree is a perfect
    binary tree. In this structure, nodes are distributed as
    evenly as possible, minimizing the height.

    Example Structure (Perfect Binary Tree):

                A
              /   \
             B     C
            / \   / \
           D   E F   G

    Why We Use Geometric Progression (GP):

        - In a perfect binary tree, each node has two children.
        - The number of nodes doubles at every level.
        - Level 0 has 1 node
        - Level 1 has 2 nodes
        - Level 2 has 4 nodes
        - Level h has 2^h nodes

        This doubling behavior forms a geometric progression:
            1 + 2 + 4 + 8 + ... + 2^h


    Analysis and Conversion to log n:

        - The total number of nodes in a perfect binary tree is:
              n = 1 + 2 + 4 + ... + 2^h
        - This is the sum of a GP:
              n = 2^(h + 1) - 1
        - To find height in terms of n, we rearrange:

              n + 1 = 2^(h + 1)

        - Taking log base 2 on both sides:

              log2(n + 1) = h + 1

        - Solving for height:

              h = log2(n + 1) - 1

        - This shows why height grows logarithmically with n.


    Formula:
        Minimum height = log2(n)


    Conclusion

    For a binary tree with n nodes:
        - Maximum height = n - 1
          (Skewed binary tree)
        - Minimum height is proportional to log2(n)
          (Perfect binary tree)

    Thus, the use of GP explains the doubling of nodes at each
    level, and converting the GP sum into logarithmic form
    shows why the minimum height of a binary tree is O(log n).
*/
