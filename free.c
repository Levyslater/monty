#include "monty.h"

/**
 * free_stack - function frees a doubly list and stack
 * @stack: pointer to the stack
 *
 * Return: void
*/

void free_stack(stack_t *stack)
{
	StackNode *current = stack->top;

	while (current != NULL)
	{
		StackNode *temp = current;

		current = current->next;

		free(temp);
	}
	free(stack);
}
