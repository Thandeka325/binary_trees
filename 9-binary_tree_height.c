#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	/* Measure the height of the left subtree */
	left_height = tree->left ? binary_tree_height(tree->left) + 1 : 0;

	/* Measure the height of the right subtree */
	right_height = tree->right ? binary_tree_height(tree->right) + 1 : 0;

	/* Return the larger of the two heights */
	return (left_height > right_height ? left_height : right_height);
}
