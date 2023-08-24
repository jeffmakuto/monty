#include "monty.h"

/**
 * pint - prints the value of the top element in the stack
 * @stack: pointer to the head node of the stack
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(interpreter.file);
		free(interpreter.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
