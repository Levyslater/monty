#include "monty.h"

/**
 * pall - handles pall command
 * @stack: points to a pointer to the stack
 * @line_number: command line number in the monty code
 *
 * Return: void
*/

void pall(stack_t **stack, unsigned int line_number)
{
	StackNode *current = (*stack)->top;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
}
