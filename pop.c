#include "monty.h"

/**
 * pop - function handles pop command
 * @stack: points to a pointer to the stack
 * @line_number: command line number
 *
 * Retuen: void
*/

void pop(stack_t **stack, unsigned int line_number)
{
	StackNode *temp;
	(void)line_number;

	temp = (*stack)->top;

	(*stack)->top = temp->next;

	if ((*stack)->top != NULL)
	{
		(*stack)->top->prev = NULL;
	}
	free(temp);
	temp = NULL;
}
