#include "levels.h"
/**
 * divide - divides the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void divide(stack_t **head, unsigned int counter)
{
	stack_t *a;
	int length = 0, level;

	a = *head;
	while (a)
	{
		a = a->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.line_c);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	a = *head;
	if (a->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.line_c);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	level = a->next->n / a->n;
	a->next->n = level;
	*head = a->next;
	free(a);
}

/**
 * chars - prints the char at the top of the stack,
 * followed by a new line
 * @heat: stack heat
 * @counter: line_number
 * Return: no return
*/
void chars(stack_t **heat, unsigned int counter)
{
	stack_t *x;

	x = *heat;
	if (!x)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.line_c);
		stack_free(*heat);
		exit(EXIT_FAILURE);
	}
	if (x->n > 127 || x->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus.file);
		free(bus.line_c);
		stack_free(*heat);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", x->n);
}
