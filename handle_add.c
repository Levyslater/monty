#include "monty.h"

/**
 * handle_add - function handles opcode add
 * @opcode: pointer to the command
 * @instructions: array containing defined opcodes
 * @line_number: instruction number in the file
 * @i: iterator
 * @file: file descriptor
 * @stack: points to a pointer to stack
 * Return: void
*/

void handle_add(char *opcode, stack_t **stack, instruction_t instructions[],
unsigned int line_number, int i, FILE *file)
{
	StackNode *current = (*stack)->top;

	if (strcmp(opcode, "add") == 0)
	{
		if ((*stack)->top == NULL || current->next == NULL)
		{
			fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
			fclose(file);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
		else
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}
}
