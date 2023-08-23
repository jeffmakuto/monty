#include "monty.h"

/**
 * pop - pops a value from the stack
 * @stack: a pointer to the pointer to the stack's top node
 * @line_number: the line number where the pop operation is performed
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_resources();
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(temp);
}
