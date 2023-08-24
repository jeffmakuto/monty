#include "monty.h"

/**
 * swap - adds top two elements of the stack.
 * @stack: head of stack
 * @line_number: line_number
*/
void swap(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_resources_and_exit();
	}
	h = *stack;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
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
