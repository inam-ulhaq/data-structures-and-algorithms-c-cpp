/*
 Title:Number of Nodes in a Binary Tree When Height Is Given
 Author: Inam Ul Haq
 Description:
    In a binary tree, each node can have at most two children.
    When the height (h) of a binary tree is fixed, the total
    number of nodes depends on how the tree is structured.
    There are two extreme cases:
        1) Minimum number of nodes
        2) Maximum number of nodes


    Minimum Number of Nodes in a Binary Tree

    The minimum number of nodes occurs when the binary tree
    is skewed (left-skewed or right-skewed). In this structure,
    every node has only one child, so the tree grows in a
    single direction like a linked list.

    Example Structure (Skewed Binary Tree):

            A
           /
          B
         /
        C
       /
      D

    Analysis:
        - Each level contains exactly one node.
        - Height h is measured in number of edges.
        - From the root to the deepest leaf, there are h edges.
        - Number of nodes is always one more than the edges.

    Formula:
        Minimum number of nodes = h + 1


    Maximum Number of Nodes in a Binary Tree

    The maximum number of nodes occurs when the binary tree
    is a perfect binary tree. In this structure, every
    internal node has exactly two children and all levels
    are completely filled.

    Example Structure (Perfect Binary Tree):

                A
              /   \
             B     C
            / \   / \
           D   E F   G

    Analysis:
        - Level 0 contains 1 node
        - Level 1 contains 2 nodes
        - Level 2 contains 4 nodes
        - The number of nodes at each level doubles
        - This forms a geometric progression (GP)

    GP Series:
        1 + 2 + 4 + 8 + ... + 2^h

    Formula:
        Maximum number of nodes = 2^(h + 1) - 1


    Conclusion

    For a binary tree of height h:
        - Minimum number of nodes = h + 1
          (Skewed binary tree)
        - Maximum number of nodes = 2^(h + 1) - 1
          (Perfect binary tree)

    Thus, for a fixed height, the structure of the binary
    tree determines whether the number of nodes is minimum
    or maximum.
*/
