#include "levels.h"
/**
 * modulos - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void modulos(stack_t **head, unsigned int counter)
{
	stack_t *x;
	int len = 0;


	x = *head;
	while (x)
	{
		x = x->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.line_c);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	x = *head;
	if (x->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.line_c);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	len = x->next->n % x->n;
	x->next->n = len;
	*head = x->next;
	free(x);
}
/**
* stack_free - frees a doubly linked list
* @head: head of the stack
*/
void stack_free(stack_t *head)
{
	stack_t *len;

	len = head;
	while (head)
	{
		len = head->next;
		free(head);
		head = len;
	}
}

