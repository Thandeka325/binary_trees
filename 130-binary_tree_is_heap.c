#include "binary_trees.h"
#include <stdbool.h>

/**
 * count_nodes - Counts the number of nodes in a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: Number of nodes in the tree.
 */
int count_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * is_complete - Checks if the binary tree is complete.
 * @tree: Pointer to the root node of the tree.
 * @index: Index of the current node in the complete tree.
 * @node_count: Total number of nodes in the tree.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
bool is_complete(const binary_tree_t *tree, int index, int node_count)
{
	if (!tree)
		return (true);
	if (index >= node_count)
		return (false);
	return (is_complete(tree->left, 2 * index + 1, node_count) &&
			is_complete(tree->right, 2 * index + 2, node_count));
}

/**
 * is_max_heap - Checks if the binary tree satisfies the max-heap property.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 1 if the tree satisfies the max-heap property, 0 otherwise.
 */
bool is_max_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (true);
	if (tree->left && tree->n < tree->left->n)
		return (false);
	if (tree->right && tree->n < tree->right->n)
		return (false);
	return (is_max_heap(tree->left) && is_max_heap(tree->right));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int node_count;

	if (!tree)
		return (0);

	node_count = count_nodes(tree);

	if (!is_complete(tree, 0, node_count))
		return (0);
	if (!is_max_heap(tree))
		return (0);
	return (1);
}
