#include "monty.h"

/**
 * executeInstruction - function execute monty file commands
 * @opcode: pointer to command
 * @argument: pointer to argument passed to the opcode
 * @line_number: line number of current indtruction
 * @file: file descriptor
 * @stack: point to a pointer to the stack
 * @instructions: array with defined opcodes
 * Return: void
*/

void executeInstruction(instruction_t instructions[], char *opcode,
stack_t **stack, unsigned int line_number, char *argument, FILE *file)
{
	int i, j;
	unsigned int data;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			if (strcmp(opcode, "push") == 0)
			{
				if (argument == NULL)
				{
					fprintf(stderr, "L%d: Usage: push integer\n", line_number);
					free_stack(*stack);
					fclose(file);
					exit(EXIT_FAILURE);
				}
				for (j = 0; argument[j] != '\0'; j++)
				{
					if (!isdigit(argument[j]))
					{
						fprintf(stderr, "L%d: Usage: push integer\n", line_number);
						free_stack(*stack);
						fclose(file);
						exit(EXIT_FAILURE);
					}
				}
				data = atoi(argument);
				/*fclose(file); */
				instructions[i].f(stack, data);
				return;
			}
			/*fclose(file);*/
			handle_rest(opcode, stack, instructions, line_number, i, file);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	fclose(file);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
