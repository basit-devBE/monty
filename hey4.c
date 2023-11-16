#include "levels.h"
/**
  *subtract- sustration
  *@heat: stack heat
  *@counter: line_number
  *Return: no return
 */
void subtract(stack_t **heat, unsigned int counter)
{
	stack_t *len;
	int sus, nodes;

	len = *heat;
	for (nodes = 0; len != NULL; nodes++)
		len = len->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.line_c);
		stack_free(*heat);
		exit(EXIT_FAILURE);
	}
	len = *heat;
	sus = len->next->n - len->n;
	len->next->n = sus;
	*heat = len->next;
	free(len);
}

/**
  *f_rotr- rotates the stack to the bottom
  *@heat: stack heat
  *@counter: line_number
  *Return: no return
 */
void devfest(stack_t **heat, __attribute__((unused)) unsigned int counter)
{
	stack_t *cpy;

	cpy = *heat;
	if (*heat == NULL || (*heat)->next == NULL)
	{
		return;
	}
	while (cpy->next)
	{
		cpy = cpy->next;
	}
	cpy->next = *heat;
	cpy->prev->next = NULL;
	cpy->prev = NULL;
	(*heat)->prev = cpy;
	(*heat) = cpy;
}

/**
 * swap - adds the top two elements of the stack.
 * @heat: stack heat
 * @counter: line_number
 * Return: no return
*/
void swap(stack_t **heat, unsigned int counter)
{
	stack_t *x;
	int len = 0;

	x = *heat;
	while (x)
	{
		x = x->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.line_c);
		stack_free(*heat);
		exit(EXIT_FAILURE);
	}
	x = *heat;
	len = x->n;
	x->n = x->next->n;
	x->next->n = len;
}
