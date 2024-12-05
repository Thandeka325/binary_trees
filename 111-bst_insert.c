#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a Binary Search Tree (BST).
 * @tree: Double pointer to the root node of the BST.
 * @value: Value to insert into the tree.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current, *new_node;

	if (!tree)
		return (NULL);
	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree); }
	current = *tree;

	while (current)
	{
		if (value == current->n)
			return (NULL);
		if (value < current->n)
		{
			if (current->left)
				current = current->left;
			else
			{
				new_node = binary_tree_node(current, value);
				if (!new_node)
					return (NULL);
				current->left = new_node;
				return (new_node); }}
		else
		{
			if (current->right)
				current = current->right;
			else
			{
				new_node = binary_tree_node(current, value);
				if (!new_node)
					return (NULL);
				current->right = new_node;
				return (new_node); }}}
	return (NULL);
}
