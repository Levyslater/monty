#include "monty.h"

/**
 * processFile - function process the monty byte code
 * @filename: contain name of the monty file
 * @instructions: contain instructions
 * @stack: points to a pointer to the stack
 *
 * Return: void
*/

void processFile(const char *filename, instruction_t instructions[],
stack_t *stack)
{
	FILE *file = fopen(filename, "r");
	char line[1024];
	unsigned int lineNumber = 0;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		lineNumber++;
		handleLine(line, instructions, &stack, &lineNumber, file);
	}
	fclose(file);
}
