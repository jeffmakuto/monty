#include "monty.h"

/**
 * rotl- rotates the stack
 * @stack: head of the stack
 * @line_number: line_number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack, *aux;
	(void)line_number;

	if (!*stack || (*stack)->next == NULL)
		return;
	aux = (*stack)->next;
	aux->prev = NULL;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = tmp;
	(*stack) = aux;
}
