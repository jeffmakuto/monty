#include "monty.h"

/**
 * exec - execute a line of Monty bytecode
 * @line: the line to execute
 * @stack: pointer to the stack
 * @line_number: the line number being executed
 */
void execute(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode = strtok(line, " \t\n");
	instruction_t *instruction;

	if (!opcode || opcode[0] == '#') /* Ignore empty lines and comments */
		return;
	instruction = find_instruction(opcode);
	if (!instruction)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		free_resources();
		exit(EXIT_FAILURE);
	}
	if (instruction->opcode)
		instruction->f(stack, line_number);
	interpreter.line = NULL; /* Reset the line pointer after execution */
}

/**
 * find_instruction - find the instruction function based on opcode
 * @opcode: the opcode to search for
 * Return: pointer to the corresponding instruction function,
 * or NULL if not found
 */
instruction_t *find_instruction(char *opcode)
{
	int i = 0;

	while (interpreter.instructions[i].opcode)
	{
		if (strcmp(opcode, interpreter.instructions[i].opcode) == 0)
			return (&interpreter.instructions[i]);
		i++;
	}
	return (NULL);
}

/**
 * free_resources - free allocated resources
 */
void free_resources(void)
{
	free_stack(interpreter.stack);
	fclose(interpreter.file);
}
