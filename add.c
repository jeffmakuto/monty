#include "monty.h"

/**
 * add - add top two elements of the stack.
 * @stack: head of stack
 * @line_number: line_number
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	int len = 0, sum;

	h = *stack;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(interpreter.file);
		free(interpreter.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	sum = h->n + h->next->n;
	h->next->n = sum;
	*stack = h->next;
	free(h);
}
