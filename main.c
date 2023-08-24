#include "monty.h"

/* Global data structure to hold shared information across functions */
info_t interpreter = {NULL, NULL, 0, NULL};

/**
* main - starting point
* @ac: argument count
* @av: array of arguments
* Return: 0 on success
*/
int main(int ac, char *av[])
{
	FILE *file;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	interpreter.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	process_file(file);

	fclose(file);
	return (0);
}

/**
 * process_file - process a Monty bytecode file
 * @file: pointer to the input bytecode file
 */
void process_file(FILE *file)
{
	char *line = NULL;
	size_t size = 0;
	ssize_t bytes_read = 1;
	stack_t *stack = NULL;
	unsigned int count = 0;

	while (1)
	{
		bytes_read = getline(&line, &size, file);
		interpreter.line = line;
		count++;

		if (bytes_read <= 0)
			break;
		execute(line, &stack, count, file);
	}
	free(line);
	free_stack(stack);
}

/**
* execute - executes operations based on the opcode
* @line: line to be executed
* @stack: pointer to the top of the stack
* @count: line_number
* @file: pointer to Monty file being read from
* Return: 0 on sucess, 1 on failure
*/
int execute(char *line, stack_t **stack, unsigned int count, FILE *file)
{
	instruction_t opcode_str[] = {
				{"push", push}, {"pall", pall}, {"pint", pint},
				{"pop", pop}, {"swap", swap}, {"add", add},
				{"nop", nop}, {"sub", sub}, {"div", _div},
				{"mul", mul}, {"mod", mod}, {"pchar", pchar},
				{"pstr", pstr}, {"rotl", rotl}, {"rotr", rotr},
				{"queue", _queue}, {"stack", _stack}, {NULL, NULL}
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
	fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
	free_and_exit(file, line, stack);
	return (1);
}

/**
 * free_stack - frees a doubly linked list.
 * @stack: pointer to the head node of the list.
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack, *next;

	while (current)
	{
		next = current->next;
		free(current);
		current = next;  /* Move to the next node */
	}
}

/**
 * free_and_exit - frees resources and exits with failure status
 * @file: monty file to read from
 * @line: line to read from
 * @stack: pointer to head of stack
 */
void free_and_exit(FILE *file, char *line, stack_t **stack)
{
	fclose(file);
	free(line);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
