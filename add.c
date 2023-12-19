#include "monty.h"

/**
 * add - adds the two top stack elements
 * @stack: points to a pointer to the stack
 * @line_number: show line number of the command in the command file
 *
 * Return: void
*/

void add(stack_t **stack, unsigned int line_number)
{
	StackNode *current = (*stack)->top;

	current->next->data += current->data;

	pop(stack, line_number);
}
