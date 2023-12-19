#include "monty.h"

/**
 * pint - prints the top most item of the stack
 * @stack: point to a pointer to the stack
 * @line_number: indicate line number of command in the file
 *
 * Return: void
*/
void pint(stack_t **stack, unsigned int line_number)
{
	StackNode *current = (*stack)->top;
	(void)line_number;

	printf("%d\n", current->data);
}
