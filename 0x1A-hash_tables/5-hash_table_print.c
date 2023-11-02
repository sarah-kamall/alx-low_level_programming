#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table
 * @ht: hash table to print
 *
 * Return: void
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	int n;
	hash_node_t *tmp;

	n = 0;
	if (!ht || ht->size == 0 || ht->array == NULL)
	       return ;	
	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		tmp = ht->array[i];
		while(tmp)
		{
			if (n)
				printf(", ");
			printf("'%s': '%s'", tmp->key, tmp->value);
			n = 1;
			tmp = tmp->next;
		}
	}
	printf("}\n"); 
}
