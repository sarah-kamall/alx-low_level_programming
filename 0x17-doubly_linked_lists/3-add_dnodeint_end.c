#include "lists.h"
/**
* dlistint_len - Prints all the elements of a doubly linked list.
*
* @h: A pointer to the head of the doubly linked list.
*
* Return: The number of nodes in the list.
*/
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *s, *h;

	h = *head;
	s = malloc(sizeof(dlistint_t));
	if (!s)
		return (NULL);
	s->n = n;
	if (!h)
	{
		h = s;
		h->next = NULL;
		h->prev = NULL;
		return (h);
	}
	while (h && h->next)
	{
		h = h->next;
	}
	h->next = s;
	s->prev = h;
	s->next = NULL;
	return (s);
}

