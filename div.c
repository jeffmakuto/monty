#include "monty.h"

/**
 * div - divide top two elements on the stack.
 * @stack: head of the stack
 * @line_number: line_number
*/
void div(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	int len = 0, aux;

	h = *stack;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_resources_and_exit();
	}
	h = *stack;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_resources_and_exit();
	}
	aux = h->next->n / h->n;
	h->next->n = aux;
	*stack = h->next;
	free(h);
}
