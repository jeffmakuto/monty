#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: head of stack
 * @line_number: line_number
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = *stack;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
