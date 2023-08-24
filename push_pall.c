#include "monty.h"

/**
 * push - adds a node with a value to the stack
 * @stack: pointer to the head node of the stack
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n, j = 0;
	int flag = 0;

	if (!interpreter.operand)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_resources_and_exit();
	}

	if (interpreter.operand[0] == '-')
		j++;

	for (; interpreter.operand[j] != '\0'; j++)
	{
		if (interpreter.operand[j] < '0' || interpreter.operand[j] > '9')
		{
			flag = 1;
			break;
		}
	}

	if (flag == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_resources_and_exit();
	}

	n = atoi(interpreter.operand);

	if (interpreter.count == 0)
		add_node(stack, n);
	else
		add_queue(stack, n);
}

/**
 * pall - prints all elements of the stack
 * @stack: pointer to the head node of the stack
 * @line_number: line number (unused)
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
