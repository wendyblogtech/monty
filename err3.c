#include "monty.h"

/**
 * errmul - Print error when stack contains less than two elements for mul
 * @stack: stack
 * @line_number: line number
 */
void errmul(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
	free_stack(*stack);
	fclose(info.fp);
	free(info.line);
	exit(EXIT_FAILURE);
}

/**
 * errmod - Print error when stack contains less than two elements for mod
 * or if top element is 0
 * @stack: stack
 * @line_number: line number
 * @modcode: error code
 */
void errmod(stack_t **stack, unsigned int line_number, int modcode)
{
	if (modcode == 1)
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
	else if (modcode == 2)
		fprintf(stderr, "L%u: division by zero\n", line_number);
	free_stack(*stack);
	fclose(info.fp);
	free(info.line);
	exit(EXIT_FAILURE);
}

