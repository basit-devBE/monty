#include "levels.h"
/**
 * add_up - adds the top two elements of the stack.
 * @heat: stack heat
 * @counter: line_number
 * Return: no return
*/
void add_up(stack_t **heat, unsigned int counter)
{
	stack_t *a;
	int length = 0, level;

	a = *heat;
	while (a)
	{
		a = a->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.line_c);
		stack_free(*heat);
		exit(EXIT_FAILURE);
	}
	a = *heat;
	level = a->n + a->next->n;
	a->next->n = level;
	*heat = a->next;
	free(a);
}

/**
  *f_nop- nothing
  *@heat: stack heat
  *@counter: line_number
  *Return: no return
 */
void f_nop(stack_t **heat, unsigned int counter)
{
	(void) counter;
	(void) heat;
}

/**
 * point_string - prints the string starting at the top of the stack,
 * followed by a new
 * @heat: stack heat
 * @counter: line_number
 * Return: no return
*/
void point_string(stack_t **heat, unsigned int counter)
{
	stack_t *x;
	(void)counter;

	x = *heat;
	while (x)
	{
		if (x->n > 127 || x->n <= 0)
		{
			break;
		}
		printf("%c", x->n);
		x = x->next;
	}
	printf("\n");
}
