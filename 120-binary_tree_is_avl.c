#include "binary_trees.h"
#include <limits.h>

/**
 * height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: Height of the tree, or 0 if tree is NULL.
 */
int height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * is_bst - Checks if a binary tree is a valid Binary Search Tree.
 * @tree: Pointer to the root node of the tree to check.
 * @min: Minimum allowable value.
 * @max: Maximum allowable value.
 *
 * Return: 1 if tree is a valid BST, otherwise 0.
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst(tree->left, min, tree->n) &&
			is_bst(tree->right, tree->n, max));
}

/**
 * is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is AVL, otherwise 0.
 */
int is_avl(const binary_tree_t *tree)
{
	int left_height, right_height, balance_factor;

	if (!tree)
		return (1);

	/* Check BST property */
	if (!is_bst(tree, INT_MIN, INT_MAX))
		return (0);

	/* Calculate height and balance factor */
	left_height = height(tree->left);
	right_height = height(tree->right);
	balance_factor = left_height - right_height;

	/* Check AVL property: balance factor must be -1, 0, or 1 */
	if (balance_factor < -1 || balance_factor > 1)
		return (0);

	/* Recursively check left and right subtrees */
	return (is_avl(tree->left) && is_avl(tree->right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is AVL, otherwise 0.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_avl(tree));
}
