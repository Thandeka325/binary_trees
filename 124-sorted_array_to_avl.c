#include "binary_trees.h"

/**
 * sorted_array_to_avl_helper - Recursively builds an AVL tree
 * @array: A pointer to the first element of the array
 * @start: Starting index of the subarray
 * @end: Ending index of the subarray
 * @parent: A pointer to the parent node.
 *
 * Return: A pointer to the root node of the subtree,
 * or NULL on failure
 */
avl_t *sorted_array_to_avl_helper(int *array, int start, int end,
		avl_t *parent)
{
	avl_t *node;
	int mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	node = binary_tree_node(parent, array[mid]);

	if (!node)
		return (NULL);

	node->left = sorted_array_to_avl_helper(array, start, mid - 1, node);
	node->right = sorted_array_to_avl_helper(array, mid + 1, end, node);

	return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: A pointer to the first element of the array to be converted
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node of the created AVL tree,
 * or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (sorted_array_to_avl_helper(array, 0, size - 1, NULL));
}
