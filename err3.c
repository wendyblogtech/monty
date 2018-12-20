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
 * @stack: stack
 * @line_number: line number
 */
void errmod(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
	free_stack(*stack);
	fclose(info.fp);
	free(info.line);
	exit(EXIT_FAILURE);
}

