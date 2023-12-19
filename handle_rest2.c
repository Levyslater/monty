#include "monty.h"

/**
 * handle_rest2 - function handles other opcodes
 * @opcode: pointer to the command
 * @instructions: array containing defined opcodes
 * @line_number: instruction number in the file
 * @i: iterator
 * @stack: points to a pointer to stack
 * @file: file descriptor
 * Return: void
*/

void handle_rest2(char *opcode, stack_t **stack, instruction_t instructions[],
unsigned int line_number, int i, FILE *file)
{
	StackNode *current = (*stack)->top;

	if (strcmp(opcode, "swap") == 0)
	{
		if ((*stack)->top == NULL || current->next == NULL)
		{
			fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
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
	else if (strcmp(opcode, "pint") == 0)
	{
		if ((*stack)->top == NULL)
		{
			fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
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
	handle_add(opcode, stack, instructions, line_number, i, file);
}
