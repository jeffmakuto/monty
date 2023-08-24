#include "monty.h"

/**
 * pint - prints the value of the top element in the stack
 * @stack: pointer to the head node of the stack
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_resources_and_exit();
	}

	printf("%d\n", (*stack)->n);
}

/**
 * free_resources_and_exit - frees resources and exits with failure status
 */
void free_resources_and_exit(void)
{
	fclose(interpreter.file);
	free(interpreter.line);
	free_stack(interpreter.stack);
	exit(EXIT_FAILURE);
}

