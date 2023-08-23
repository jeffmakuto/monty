#include "monty.h"

/* Initialize an 'info_t' structure for program execution */
info_t interpreter = {
	NULL,
	NULL,
	NULL,
	0,
	{
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{NULL, NULL}
	}
};

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
	char *line = NULL;
	size_t size = BUFFER, len;
	stack_t *stack = NULL;
	unsigned int line_number = 0, count = 0;

	line = malloc(size);
	if (!line)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	while (fgets(line, size, file))
	{
		len = strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0'; /* Remove the newline character */
                interpreter.line = line;
                count++;
                execute(line, &stack, line_number);
        }
        free(line);
        free_resources();
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
