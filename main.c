#define _GNU_SOURCE

#include "levels.h"
#include <stdio.h>

defo bus = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 if success
*/
int main(int argc, char *argv[])
{
    char *line_c = NULL;
    FILE *file;
    size_t size = 0;
    ssize_t read_line = 1;
    stack_t *stack = NULL;
    unsigned int counter = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while (read_line > 0)
    {
        line_c = NULL;
        read_line = getline(&line_c, &size, file);
        counter++;
        if (read_line > 0)
        {
            display(line_c, &stack, counter, file);
        }
        free(line_c);
    }
    stack_free(stack);
    fclose(file);
    return (0);
}
