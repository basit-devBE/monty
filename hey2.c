#include "levels.h"
/**
 * pop_up - prints the top
 * @heat: stack heat
 * @counter: line_number
 * Return: no return
*/
void pop_up(stack_t **heat, unsigned int counter)
{
	stack_t *x;

	if (*heat == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.line_c);
		stack_free(*heat);
		exit(EXIT_FAILURE);
	}
	x = *heat;
	*heat = x->next;
	free(x);
}

/**
  *rotme- rotates the stack to the top
  *@heat: stack heat
  *@counter: line_number
  *Return: no return
 */
void rotme(stack_t **heat,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *heat, *len;

	if (*heat == NULL || (*heat)->next == NULL)
	{
		return;
	}
	len = (*heat)->next;
	len->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *heat;
	(*heat)->next = NULL;
	(*heat)->prev = tmp;
	(*heat) = len;
}


/**
 * f_pint - prints the top
 * @heat: stack heat
 * @counter: line_number
 * Return: no return
*/
void f_pint(stack_t **heat, unsigned int counter)
{
	if (*heat == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.line_c);
		stack_free(*heat);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*heat)->n);
}
