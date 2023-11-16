#ifndef LEVELS_H
#define LEVELS_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

typedef struct level
{
    char *arg;
    FILE *file;
    char *line_c;
    int stack_filo;
} defo;

extern defo bus;

typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char *_rebel(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getup(char **lineptr, int file);
char *clean_line(char *line_c);

void pushing_p(stack_t **head, unsigned int number);
void lapoid(stack_t **head, unsigned int number);
void f_pint(stack_t **head, unsigned int number);
int display(char *line_c, stack_t **head, unsigned int counter, FILE *file);
void stack_free(stack_t *head);
void pop_up(stack_t **head, unsigned int counter);
void swap(stack_t **head, unsigned int counter);
void add_up(stack_t **head, unsigned int counter);
void f_nop(stack_t **head, unsigned int counter);
void subtract(stack_t **head, unsigned int counter);
void divide(stack_t **head, unsigned int counter);
void multiply(stack_t **head, unsigned int counter);
void modulos(stack_t **head, unsigned int counter);
void chars(stack_t **head, unsigned int counter);
void point_string(stack_t **head, unsigned int counter);
void rotme(stack_t **head, unsigned int counter);
void devfest(stack_t **head, __attribute__((unused)) unsigned int counter);
void add_me(stack_t **head, int n);
void queueme(stack_t **head, int n);
void queue(stack_t **head, unsigned int counter);
void stack_them(stack_t **head, unsigned int counter);

#endif
