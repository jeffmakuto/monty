#include "monty.h"

/* Initialize an 'info_t' structure for program execution */
info_t interpreter = {NULL, NULL, NULL, 0};

/**
 * main - starting point
 * @ac: number of arguments
 * @av: array of arguments
 * Return: 0 on success
 */
int main(int ac, char *av[])
{
	FILE *file;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	interpreter.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	process_file(file);

	return (0);
}

/**
 * process_file - processes commands from a file
 * @file: pointer to the FILE stream containing the commands to execute
 */
void process_file(FILE *file)
{
	size_t buffer = 0;
	ssize_t bytes_read;
	char *line = NULL;
	stack_t *stack = NULL;
	unsigned int count = 0;

	while (1)
	{
		bytes_read = getline(&line, &buffer, file);
		if (bytes_read == -1)
			break;
		interpreter.file = file;
		interpreter.line = line;
		count++;
		if (bytes_read > 0)
			execute(line, &stack, count, file);
	}
	free(line);
	free_stack(stack);
	fclose(file);
    
}

/**
 * free_stack - free the stack
 * @stack: pointer to the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
