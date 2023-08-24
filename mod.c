#include "monty.h"

/**
 * mod - divide the second top element of the stack by the top element
 * @stack: head of stack
 * @line_number: line_number
*/
void mod(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_resources_and_exit();
	}
	h = *stack;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_resources_and_exit();
	}
	aux = h->next->n % h->n;
	h->next->n = aux;
	*stack = h->next;
	free(h);
}
