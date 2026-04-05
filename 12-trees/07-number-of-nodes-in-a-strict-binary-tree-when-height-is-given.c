/*
 Title: Number of Nodes in a Strict (Full) Binary Tree When Height Is Given
 Author: Inam Ul Haq
 Description:
    In a strict (also called full) binary tree, each node
    has either exactly two children or no children at all.
    No node is allowed to have only one child.

    When the height (h) of a strict binary tree is fixed,
    the total number of nodes depends on how the tree
    is structured. There are two extreme cases:
        1) Minimum number of nodes
        2) Maximum number of nodes


    Minimum Number of Nodes in a Strict Binary Tree

    The minimum number of nodes occurs when the strict
    binary tree is as unbalanced as possible while still
    satisfying the strict property. In this structure,
    every internal node has exactly two children, but
    only one subtree continues deeper at each level.

    Example Structure (Minimum Nodes - Strict Binary Tree):

            A
           / \
          B   C
             / \
            D   E
               / \
              F   G

    Analysis:
        - Every internal node has exactly two children.
        - Height h is measured in number of edges.
        - At each level, only one node continues the height.
        - Each internal node contributes two children.
        - Number of internal nodes = h
        - Number of leaf nodes = h + 1

    Formula:
        Minimum number of nodes = 2h + 1


    Maximum Number of Nodes in a Strict Binary Tree

    The maximum number of nodes occurs when the strict
    binary tree is also a perfect binary tree. In this
    structure, every internal node has exactly two children
    and all levels are completely filled.

    Example Structure (Perfect Strict Binary Tree):

                A
              /   \
             B     C
            / \   / \
           D   E F   G

    Analysis:
        - Level 0 contains 1 node
        - Level 1 contains 2 nodes
        - Level 2 contains 4 nodes
        - Each internal node has exactly two children
        - The number of nodes at each level doubles
        - This forms a geometric progression (GP)

    GP Series:
        1 + 2 + 4 + 8 + ... + 2^h

    Formula:
        Maximum number of nodes = 2^(h + 1) - 1


    Conclusion

    For a strict binary tree of height h:
        - Minimum number of nodes = 2h + 1
          (Unbalanced strict binary tree)
        - Maximum number of nodes = 2^(h + 1) - 1
          (Perfect strict binary tree)

    Hence, even under the strict condition, the number
    of nodes depends on how balanced the tree is.
*/
