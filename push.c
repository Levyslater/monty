#include "monty.h"

/**
 * push - handles the push command with arguments
 * @stack: double pointer to stack
 * @data: new node data
 *
 * Return: void
*/

void push(stack_t **stack, unsigned int data)
{
	StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));

	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = (*stack)->top;

	if ((*stack)->top != NULL)
		(*stack)->top->prev = newNode;
	(*stack)->top = newNode;
}
