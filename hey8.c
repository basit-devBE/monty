#include "levels.h"
/**
 * stack_them - prints the top
 * @heat: stack heat
 * @counter: the line_number
 * Return: no return
*/
void stack_them(stack_t **heat, unsigned int counter)
{
	(void)heat;
	(void)counter;
	bus.stack_filo = 0;
}


/**
 * add_me - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
*/
void add_me(stack_t **head, int n)
{

	stack_t *fresh_node, *level;

	level = *head;
	fresh_node = malloc(sizeof(stack_t));
	if (fresh_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (level)
		level->prev = fresh_node;
	fresh_node->n = n;
	fresh_node->next = *head;
	fresh_node->prev = NULL;
	*head = fresh_node;
}


/**
 * lapoid - prints the stack
 * @heat: stack heat
 * @counter: no used
 * Return: no return
*/
void lapoid(stack_t **heat, unsigned int counter)
{
	stack_t *x;
	(void)counter;

	x = *heat;
	if (x == NULL)
		return;
	while (x)
	{
		printf("%d\n", x->n);
		x = x->next;
	}
}

/**
 * multiply - multiplies the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void multiply(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int length = 0, len;

	h = *head;
	while (h)
	{
		h = h->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.line_c);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	len = h->next->n * h->n;
	h->next->n = len;
	*head = h->next;
	free(h);
}
