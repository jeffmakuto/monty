#include "monty.h"

/**
 * push - pushes a value onto the stack
 * @stack: a pointer to the pointer to the stack's top node
 * @line_number: the line number where the push operation is performed
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *operand = strtok(NULL, " \t\n");
	int value;

	if (!operand || !is_numeric(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_resources();
		exit(EXIT_FAILURE);
	}
	value = atoi(operand);
	push_stack(stack, value);
}

/**
 * is_numeric - checks if a given string represents a numeric value
 * @str: the string to be checked
 * Return: 1 if the string is numeric, 0 otherwise.
 */
int is_numeric(const char *str)
{
	char *endptr;

	if (!str || *str == '\0' || isspace(*str))
		return (0);
	strtol(str, &endptr, 10);
	return (*endptr == '\0');
}

/**
 * push_stack - pushes a value onto the stack
 * @stack: a pointer to the pointer to the stack's top node
 * @value: the value to be pushed onto the stack
 */
void push_stack(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_resources();
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - prints all values in the stack
 * @stack: a pointer to the pointer to the stack's top node
 * @line_number: the line number where the pall operation is performed
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

/**
 * free_resources - frees allocated resources
 * and exits the program
 */
void free_resources(void)
{
	if (interpreter.file)
		fclose(interpreter.file);
	if (interpreter.line)
		free(interpreter.line);
	if (interpreter.operand)
		free(interpreter.operand);
}

