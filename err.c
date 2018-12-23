#include "monty.h"

/**
 * errac - Print error message if user does not give any file or more than one
 * argument to your program
 */
void errac(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * erropen - Print error message if it's not possible to open the file
 * @arg: file
 */
void erropen(char *arg)
{
	fprintf(stderr, "Error: Can't open file %s\n", arg);
	exit(EXIT_FAILURE);
}

/**
 * errnomatch - Print error message if file contains an invalid instruction
 * @stack: stack
 * @line_number: line number
 */
void errnomatch(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, info.command);
	free_close(*stack);
	exit(EXIT_FAILURE);
}

/**
 * errpush - Print error message if no argument to push or if argument not num
 * @stack: stack
 * @line_number: line number
 */
void errpush(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	free_close(*stack);
	exit(EXIT_FAILURE);
}

/**
 * errpint - Print error message if stack is empty when using pint
 * @stack: stack
 * @line_number: line number
 */
void errpint(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	free_close(*stack);
	exit(EXIT_FAILURE);
}
