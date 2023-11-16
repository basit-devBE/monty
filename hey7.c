#include "levels.h"
/**
 * queue - prints the top
 * @heat: stack heat
 * @counter: the line_number
 * Return: no return
*/
void queue(stack_t **heat, unsigned int counter)
{
	(void)heat;
	(void)counter;
	bus.stack_filo = 1;
}

/**
 * queueme - add node to the tail stack
 * @x: new_value
 * @heat: heat of the stack
 * Return: no return
*/
void queueme(stack_t **heat, int x)
{
	stack_t *new_node, *len;

	len = *heat;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = x;
	new_node->next = NULL;
	if (len)
	{
		while (len->next)
			len = len->next;
	}
	if (!len)
	{
		*heat = new_node;
		new_node->prev = NULL;
	}
	else
	{
		len->next = new_node;
		new_node->prev = len;
	}
}
