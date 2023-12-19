#include "monty.h"

/**
 * swap - swap top most stack elements
 * @stack: points to a pointer to the stack
 * @line_number: show line number of the command in the command file
 *
 * Return: void
*/
void swap(stack_t **stack, unsigned int line_number)
{
	StackNode *current = (*stack)->top;
	int tmp = current->data;

	current->data = current->next->data;

	current->next->data = tmp;

	(void)line_number;
}
