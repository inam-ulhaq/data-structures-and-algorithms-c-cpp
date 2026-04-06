/*
 Title: Height of a Strict (Full) Binary Tree When Number of Nodes Is Given
 Author: Inam Ul Haq
 Description:
    In a strict (also called full) binary tree, each node
    has either exactly two children or no children at all.
    No node is allowed to have only one child.

    When the total number of nodes (n) of a strict binary
    tree is fixed, the height of the tree depends on how
    the tree is structured. There are two extreme cases:
        1) Minimum height
        2) Maximum height


    Minimum Height of a Strict Binary Tree

    The minimum height occurs when the strict binary tree
    is perfectly balanced. In this structure, every
    internal node has exactly two children and all levels
    are completely filled.

    Example Structure (Perfect Strict Binary Tree):

                A
              /   \
             B     C
            / \   / \
           D   E F   G

    Analysis:
        - The tree is perfectly balanced.
        - Total number of nodes follows:
              n = 2^(h + 1) - 1
        - Solving for height h in terms of n:

              h = log2(n + 1) - 1

    Formula:
        Minimum height = log2(n + 1) - 1


    Maximum Height of a Strict Binary Tree

    The maximum height occurs when the strict binary tree
    is as unbalanced as possible while still maintaining
    the strict property.

    Example Structure (Maximum Height - Strict Binary Tree):

            A
           / \
          B   C
             / \
            D   E
               / \
              F   G

    Analysis:
        - Every internal node has exactly two children.
        - Let i be the number of internal nodes.
        - In a strict binary tree:
              n = 2i + 1
        - The longest path is formed by chaining internal
          nodes one after another.
        - Height equals the number of internal nodes.

    Formula:
        Maximum height = (n - 1) / 2


    Conclusion

    For a strict binary tree with n nodes:
        - Minimum height = log2(n + 1) - 1
          (Perfect strict binary tree)
        - Maximum height = (n - 1) / 2
          (Unbalanced strict binary tree)

    Thus, for a fixed number of nodes, the height of a
    strict binary tree varies based on how balanced
    the structure is.
*/
