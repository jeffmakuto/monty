#include "monty.h"

/**
 * pop - removes the top element from the stack
 * @stack: pointer to the head node of the stack
 * @line_number: line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_resources_and_exit();
	}

	temp = *stack;
	*stack = temp->next;
	free(temp);
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

