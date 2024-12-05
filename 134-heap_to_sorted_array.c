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
 * heap_to_sorted_array - Converts a Max Binary Heap to a sorted array.
 * @heap: Pointer to the root of the heap.
 * @size: Pointer to store the size of the array.
 *
 * Return: Pointer to the sorted array, or NULL on failure.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	size_t i = 0;
	int value;

	if (!heap || !size)
		return (NULL);

	*size = binary_tree_size(heap);
	array = malloc(*size * sizeof(int));

	if (!array)
		return (NULL);

	while (heap)
	{
		value = heap_extract(&heap);
		array[i++] = value;
	}
	return (array);
}
