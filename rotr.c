#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: head node
 * @line_number: line_number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *copy;
	(void)line_number;

	copy = *stack;
	if (!*stack || (*stack)->next == NULL)
		return;
	while (copy->next)
		copy = copy->next;
	copy->next = *stack;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*stack)->prev = copy;
	(*stack) = copy;
}
