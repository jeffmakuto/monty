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
		fclose(interpreter.file);
		free(interpreter.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(interpreter.file);
		free(interpreter.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
