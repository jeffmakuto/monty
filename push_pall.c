#include "monty.h"

/**
 * push - add node to the stack
 * @stack: stack node
 * @line_number: line_number
 * Return: void
*/
void push(stack_t **stack, unsigned int line_number)
{
	int n, j = 0, flag = 0;

	if (interpreter.operand)
	{
		if (interpreter.operand[0] == '-')
			j++;
		for (; interpreter.operand[j] != '\0'; j++)
		{
			if (interpreter.operand[j] > 57 || interpreter.operand[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(interpreter.file);
			free(interpreter.line);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(interpreter.file);
		free(interpreter.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	n = atoi(interpreter.operand);

	if (interpreter.count == 0)
		add_node(stack, n);
	else
		add_queue(stack, n);
}

/**
 * pall - prints the stack
 * @stack: stack node
 * @line_number: unused parameter
 * Return: void
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = *stack;
	if (!h)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
