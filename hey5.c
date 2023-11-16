#include "levels.h"
/**
* display - displays the opcode
* @stack: the head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @line_c: line line_c
* Return: no return
*/
int display(char *line_c, stack_t **stack, unsigned int counter, FILE *file)
{
instruction_t opst[] = {
{"push", pushing_p}, {"pall", lapoid}, {"pint", f_pint},
{"pop", pop_up},
{"swap", swap},
{"add", add_up},
{"nop", f_nop},
{"sub", subtract},
{"div", divide},
{"mul", multiply},
{"mod", modulos},
{"pchar", chars},
{"pstr", point_string},
{"rotl", rotme},
{"rotr", devfest},
{"queue", queue},
{"stack", stack_them},
{NULL, NULL}
};
unsigned int x = 0;
char *op;

op = strtok(line_c, " \n\t");
if (op && op[0] == '#')
return (0);
bus.arg = strtok(NULL, " \n\t");
while (opst[x].opcode && op)
{
if (strcmp(op, opst[x].opcode) == 0)
{  opst[x].f(stack, counter);
return (0);
}
x++;
}
if (op && opst[x].opcode == NULL)
{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
fclose(file);
free(line_c);
stack_free(*stack);
exit(EXIT_FAILURE); }
return (1);
}
