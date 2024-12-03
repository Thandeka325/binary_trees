# __Project: 0x1D. C - Binary trees__

This is an introduction to Binary tree, Data structure and algorithms- Tree, Tree traversal, Binary search tree, and Data structures: Binary Tree.

# __More Info__

# __Data structures__

We used the following data structures and types for binary trees.

```
Basic Binary Tree
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
```

# __Binary Search Tree__

```
typedef struct binary_tree_s bst_t;
```

# __AVL Tree__

```
typedef struct binary_tree_s avl_t;
```

# __Max Binary Heap__

```
typedef struct binary_tree_s heap_t;
```

Note: For tasks 0 to 23 (included), we had to deal with simple binary trees. They are not BSTs, thus they don’t follow any rules.

# __Print function__
To match the examples in the tasks, we are given this [function](https://github.com/alx-tools/0x1C.c)

This function is used only for visualization purposes.

# __Resources__

[Binary tree (note the first line: Not to be confused with B-tree.)](https://en.wikipedia.org/wiki/Binary_tree)

[Data Structure and Algorithms - Tree](https://www.tutorialspoint.com/data_structures_algorithms/tree_data_structure.htm)

[Tree Traversal](https://www.programiz.com/dsa/tree-traversal)

[Binary Search Tree](https://en.wikipedia.org/wiki/Binary_search_tree)

[Data structures: Binary Tree](https://www.youtube.com/watch?v=H5JubkIy_p8)
