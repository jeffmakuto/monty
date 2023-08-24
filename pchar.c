#include "monty.h"

/**
 * pchar - print char at the top of the stack
 * @stack: head node
 * @line_number: line_number
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *h;

	h = *stack;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_resources_and_exit();
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_resources_and_exit();
	}
	printf("%c\n", h->n);
}
