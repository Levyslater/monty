#include "monty.h"

/**
 * main - main function
 * @argc: argument counter
 * @argv: array conatining command line arguments
 *
 * Return: 0 on success, 1 otherwise
*/

int main(int argc, char *argv[])
{
	FILE *file;
	instruction_t instructions[] = {{"push", push}, {"pop", pop},
	{"pall", pall}, {"swap", swap}, {"pint", pint}, {NULL, NULL}};

	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	stack = (stack_t *)malloc(sizeof(stack_t));

	if (stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(file);
		return (EXIT_FAILURE);
	}
	fclose(file);
	stack->top = NULL;
	processFile(argv[1], instructions, stack);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
