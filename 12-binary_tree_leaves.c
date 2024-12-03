#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: A pointer to the root node of the tree to count the number of leaves
 *
 * Return: The number of leaves, or 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* A leaf node has no left or right children */

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* Recursively count leaves in the left & right subtrees */
	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
