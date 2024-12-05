#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: Size of the tree (number of nodes).
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * find_parent - Finds the parent node for the next insertion.
 * @root: Pointer to the root node of the tree.
 * @index: The index to find the parent for in level order.
 *
 * Return: Pointer to the parent node.
 */
heap_t *find_parent(heap_t *root, size_t index)
{
	size_t parent_index = (index - 1) / 2;

	if (index == 1)
		return (root);
	if (parent_index % 2 == 0)
		return (find_parent(root, parent_index / 2)->right);
	return (find_parent(root, parent_index / 2)->left);
}

/**
 * bubble_up - Restores the Max Heap property after insertion.
 * @node: Pointer to the inserted node.
 */
void bubble_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: Double pointer to the root node of the Heap.
 * @value: The value to store in the node to be inserted.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	size_t size;

	if (!root)
		return (NULL);
	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	size = binary_tree_size(*root);
	parent = find_parent(*root, size + 1);
	new_node = binary_tree_node(parent, value);

	if (parent->left == NULL)
		parent->left = new_node;
	else
		parent->right = new_node;

	bubble_up(new_node);
	return (new_node);
}
