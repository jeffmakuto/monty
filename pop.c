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
		fclose(interpreter.file);
		free(interpreter.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = temp->next;
	free(temp);
}
