#include "levels.h"
/**
 * pushing_p - add node to the stack
 * @heat: stack heat
 * @counter: line_number
 * Return: no return
*/
void pushing_p(stack_t **heat, unsigned int counter)
{
	int x, y = 0, error = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			y++;
		for (; bus.arg[y] != '\0'; y++)
		{
			if (bus.arg[y] > 57 || bus.arg[y] < 48)
				error = 1; }
		if (error == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.line_c);
			stack_free(*heat);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.line_c);
		stack_free(*heat);
		exit(EXIT_FAILURE); }
	x = atoi(bus.arg);
	if (bus.stack_filo == 0)
		add_me(heat, x);
	else
		queueme(heat, x);
}
