#include "binary_trees.h"

int binary_tree_balance(const binary_tree_t *tree);
avl_t *avl_insert(avl_t **tree, int value);
avl_t *avl_rebalance(avl_t *tree);

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the balance factor.
 *
 * Return: Balance factor, or 0 if tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (!tree)
		return (0);
	if (tree->left)
		left_height = height(tree->left);
	if (tree->right)
		right_height = height(tree->right);

	return (left_height - right_height);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: Double pointer to the root node of the AVL,
 * tree for inserting the value.
 * @value: Value to insert in the AVL tree.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node = NULL;

	if (!tree)
		return (NULL);

	/* If tree is empty, create a new root node */
	if (!*tree)
		return (*tree = binary_tree_node(NULL, value));

	/* Recursive insertion in the left or right subtree */
	if (value < (*tree)->n)
	{
		if (!(*tree)->left)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			node = (*tree)->left;
		}
		else
		{
			node = avl_insert(&(*tree)->left, value); }}
	else if (value > (*tree)->n)
	{
		if (!(*tree)->right)
		{
			(*tree)->right = binary_tree_node(*tree, value);
			node = (*tree)->right;
		}
		else
		{
			node = avl_insert(&(*tree)->right, value); }}
	else
	{
		/* Duplicate values are not allowed in an AVL tree */
		return (NULL); }
	/* Rebalance the tree after insertion */
	*tree = avl_rebalance(*tree);
	return (node);
}

/**
 * avl_rebalance - Rebalances an AVL tree after insertion or deletion.
 * @tree: Pointer to the root node of the tree to rebalance.
 *
 * Return: Pointer to the new root node after rebalancing.
 */
avl_t *avl_rebalance(avl_t *tree)
{
	int balance;

	if (!tree)
		return (NULL);
	balance = binary_tree_balance(tree);

	/* Left-heavy case */
	if (balance > 1)
	{
		if (binary_tree_balance(tree->left) < 0)
			tree->left = binary_tree_rotate_left(tree->left);
		return (binary_tree_rotate_right(tree));
	}
	/* Right-heavy case */
	if (balance < -1)
	{
		if (binary_tree_balance(tree->right) > 0)
			tree->right = binary_tree_rotate_right(tree->right);
		return (binary_tree_rotate_left(tree));
	}
	return (tree);
}
