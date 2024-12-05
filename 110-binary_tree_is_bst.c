#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst_helper - Helper function to check BST properties recursively.
 * @tree: Pointer to the current node in the tree.
 * @min: Minimum value allowed for the current subtree.
 * @max: Maximum value allowed for the current subtree.
 *
 * Return: 1 if subtree is a valid BST, 0 otherwise.
 */
int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	/* Check current node value */
	if (tree->n <= min || tree->n >= max)
		return (0);

	/* Recursively check left and right subtrees with updated min/max */
	return (is_bst_helper(tree->left, min, tree->n) &&
			is_bst_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
