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
 * heapify_down - Ensures the Max Binary Heap property is maintained.
 * @root: Pointer to the root of the heap.
 *
 * Return: None
 */
void heapify_down(heap_t *root)
{
	heap_t *largest = root;
	heap_t *left = root->left;
	heap_t *right = root->right;
	int temp;

	if (left && left->n > largest->n)
		largest = left;
	if (right && right->n > largest->n)
		largest = right;
	if (largest != root)
	{
		temp = root->n;
		root->n = largest->n;
		largest->n = temp;
		heapify_down(largest);
	}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 *
 * Return: The value stored in the root node, or 0 on failure.
 */
int heap_extract(heap_t **root)
{
	heap_t *last_node;
	int value;
	size_t size;

	if (!root || !*root)
		return (0);
	size = binary_tree_size(*root);

	if (size == 1)
	{
		value = (*root)->n;
		free(*root);
		*root = NULL;
		return (value);
	}
	last_node = get_last_node(*root, size);
	value = (*root)->n;
	(*root)->n = last_node->n;

	if (last_node->parent && last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else if (last_node->parent)
		last_node->parent->right = NULL;
	free(last_node);
	heapify_down(*root);
	return (value);
}

/**
 * get_last_node - Returns the last node in a binary tree.
 * @root: Pointer to the root node.
 * @size: The size of the tree.
 *
 * Return: Pointer to the last node.
 */
heap_t *get_last_node(heap_t *root, size_t size)
{
	size_t level = 0, max_level = 0;
	heap_t *node = root;
	size_t idx = size;

	while (node)
	{
		max_level++;
		node = node->left;
	}
	return (node);
}
