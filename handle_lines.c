#include "monty.h"

/**
 * handleLine - handles commands by tokenization
 * @line: file descriptor
 * @instructions: contain defined instructions
 * @stack: point to a pointer to stack
 * @lineNumber: pointer to command line number
 * @file: file descriptor
 *
 * Return: void
*/
void handleLine(char *line, instruction_t instructions[], stack_t **stack,
unsigned int *lineNumber, FILE *file)
{
	size_t length = strlen(line);

	char *opcode = NULL;

	char *argument = NULL;

	if (line[length - 1] == '\n')
	{
		line[length - 1] = '\0';
	}
	opcode = strtok(line, " \n\t");
	argument = strtok(NULL, " \n\t");
	if (opcode == NULL || opcode[0] == '#')
		return;
	executeInstruction(instructions, opcode, stack,
	*lineNumber, argument, file);
}
