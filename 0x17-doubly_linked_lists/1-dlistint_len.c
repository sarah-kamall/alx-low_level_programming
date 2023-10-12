#include "lists.h"
/**
* dlistint_len - Prints all the elements of a doubly linked list.
*
* @h: A pointer to the head of the doubly linked list.
*
* Return: The number of nodes in the list.
*/
size_t dlistint_len(const dlistint_t *h)
{
	size_t s;
	
	s = 0;
	while (h)
	{
		s++;
	}
	return (s);
}

