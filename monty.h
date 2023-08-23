#ifndef MONTY_H
#define MONTY_H

/* Header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "macros.h"

/* Struct definitions */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct info_s - a structure to hold information for program execution
 * @file: file pointer to the input source file
 * @line: current line being processed in the input file
 * @stack: pointer to the stack structure for data storage
 * @line_number: current line number being processed in the input file
 * @instructions: flexible array member for storing program instructions
 */
typedef struct info_s
{
	FILE *file;
	char *line;
	stack_t *stack;
	unsigned int line_number;
	instruction_t instructions[50];
} info_t;

/* Global variable */
extern info_t interpreter;

/* Prototype functions */
void execute(char *line, stack_t **stack, unsigned int line_number);
instruction_t *find_instruction(char *opcode);
void free_resources(void);
void free_stack(stack_t *stack);
void process_file(FILE *file);

void push(stack_t **stack, unsigned int line_number);
int is_numeric(const char *str);
void push_stack(stack_t **stack, int value);
void pall(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
