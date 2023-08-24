#include "monty.h"

/**
 * sub - subtracts the top element from the second-top element in the stack
 * @stack: pointer to the head  node of the stack
 * @line_number: line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;
	int difference, node_count = 0;

	aux = *stack;

	while (aux)
	{
		aux = aux->next;
		node_count++;
	}

	if (node_count < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(interpreter.file);
		free(interpreter.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	aux = *stack;
	difference = aux->next->n - aux->n;
	aux->next->n = difference;
	*stack = aux->next;
	free(aux);
}
