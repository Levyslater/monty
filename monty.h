#ifndef MONTY_H
#define MONTY_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackNode {
  int data;
  struct StackNode *prev;
  struct StackNode *next;
} StackNode;

typedef struct {
  StackNode *top;
} stack_t;

typedef struct instruction_s {
  char *opcode;
  void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void processFile(const char *filename, instruction_t instructions[],
                 stack_t *stack);
void handleLine(char *line, instruction_t instructions[], stack_t **stack,
                unsigned int *lineNumber, FILE *file);
void push(stack_t **stack, unsigned int data);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void executeInstruction(instruction_t instructions[], char *opcode,
                        stack_t **stack, unsigned int line_number,
                        char *argument, FILE *file);
void handle_rest(char *opcode, stack_t **stack, instruction_t instructions[],
                 unsigned int line_number, int i, FILE *file);
void handle_rest2(char *opcode, stack_t **stack, instruction_t instructions[],
                 unsigned int line_number, int i, FILE *file);
void pint(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);

#endif
