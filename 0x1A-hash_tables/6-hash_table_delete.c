#include "hash_tables.h"
/**
 * hash_table_delete - deletes a hash table
 * @ht: hash table to delete
 *
 * Return: void
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned int i;
	hash_node_t *tmp, *tp;

	if(!ht || ht->size == 0)
		return ;

	for (i = 0; i < ht->size ; i++)
	{
		tmp = ht->array[i];
		while(tmp)
		{
			tp = tmp;
			tmp = tmp->next;
			if (tp->key)
				free(tp->key);
			if (tp->value)
				free(tp->value);
			free(tp);
		}
	}
	free(ht->array);
	free(ht);
}


