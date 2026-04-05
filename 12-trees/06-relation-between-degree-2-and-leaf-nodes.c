/*
 Title: Relationship Between Degree 0 and Degree 2 Nodes in a Binary Tree
 Author: Inam Ul Haq
 Description:
    In a binary tree, each node can have at most two children.
    Based on the number of children, nodes are classified as:
        - Degree 0 nodes (leaf nodes)
        - Degree 1 nodes (nodes with one child)
        - Degree 2 nodes (nodes with two children)

    Let:
        n0 = number of degree 0 nodes (leaf nodes)
        n2 = number of degree 2 nodes

    In any binary tree, the total number of edges is always
    one less than the total number of nodes. Nodes of degree
    2 contribute two edges, nodes of degree 1 contribute one
    edge, and leaf nodes contribute no edges. To balance the
    total number of edges in the tree, the number of leaf
    nodes must be exactly one more than the number of nodes
    having two children.

    Therefore, the fundamental relationship is:
        n0 = n2 + 1

    This relationship holds for every binary tree, regardless
    of its shape or size.


    Example 1: Binary Tree

                O
               / \
              O   O
                   \
                    O
                     \
                      O

        Degree Count:
            Degree 0 nodes (n0) = 2
            Degree 2 nodes (n2) = 1

        Verification:
            n0 = n2 + 1  ->  2 = 1 + 1


    Example 2: Binary Tree

                    O
                   /
                  O
                 / \
                O   O
                     \
                      O

        Degree Count:
            Degree 0 nodes (n0) = 2
            Degree 2 nodes (n2) = 1

        Verification:
            n0 = n2 + 1  ->  2 = 1 + 1


    Example 3: Binary Tree

                        O
                       / \
                      O   O
                     / \
                    O   O

        Degree Count:
            Degree 0 nodes (n0) = 3
            Degree 2 nodes (n2) = 2

        Verification:
            n0 = n2 + 1  ->  3 = 2 + 1


    Conclusion:

        In every binary tree, the number of leaf nodes is
        always one greater than the number of nodes having
        exactly two children. This is a fundamental property
        of binary trees and is independent of their structure.
*/
