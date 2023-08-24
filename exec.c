#include "monty.h"

/**
 * execute - execute Monty bytecode instructions.
 * @line: the instruction line
 * @stack: a pointer to the stack
 * @count: the line number of the instruction
 * @file: the Monty bytecode file
 * Return: 0 on success, 1 on failure
 */
int execute(char *line, stack_t **stack, unsigned int count, FILE *file)
{
	instruction_t opcode_str[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub}, {"div", div},
		{"mul", mul}, {"mod", mod}, {"pchar", pchar},
		{"pstr", pstr}, {"rotl", rotl}, {"rotr", rotr},
		{"queue", queue}, {"stack", stack},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(line, " \n\t");
	if (op && op[0] == '#')
		return (0);
	interpreter.operand = strtok(NULL, " \n\t");
	while (opcode_str[i].opcode && op)
	{
		if (strcmp(op, opcode_str[i].opcode) == 0)
		{	opcode_str[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (op && opcode_str[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
		fclose(file);
		free(line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
