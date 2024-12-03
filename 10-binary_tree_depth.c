#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: A pointer to the node to measure the depth
 *
 * Return: The depth of the node, or 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL || tree->parent == NULL)
		return (0);

	/* Depth is 1 + depth of the parent node */
	return (binary_tree_depth(tree->parent) + 1);
}
