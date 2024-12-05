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

/**
 * array_to_heap - Builds a Max Binary Heap from an array.
 * @array: Pointer to the first element of the array.
 * @size: The number of elements in the array.
 *
 * Return: Pointer to the root of the created Max Binary Heap,
 * or NULL on failure.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *heap = NULL;

	size_t i;

	if (!array || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		if (!heap_insert(&heap, array[i]))
			return (NULL);
	}
	return (heap);
}
