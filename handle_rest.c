#include "monty.h"

/**
 * handle_rest - function handles opcodes other than push
 * @opcode: pointer to the command
 * @instructions: array containing defined opcodes
 * @line_number: instruction number in the file
 * @i: iterator
 * @file: file descriptor
 * @stack: points to a pointer to stack
 * Return: void
*/

void handle_rest(char *opcode, stack_t **stack, instruction_t instructions[],
unsigned int line_number, int i, FILE *file)
{
	if (strcmp(opcode, "pall") == 0)
	{
		instructions[i].f(stack, line_number);

		return;
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		if ((*stack)->top == NULL)
		{
			fprintf(stderr, "Error: can't pop an empty stack\n");
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
	handle_rest2(opcode, stack, instructions, line_number, i, file);
}
