#include "monty.h"

/**
 * errpop - Print error message if stack is empty when using pop
 * @stack: stack
 * @line_number: line number
 */
void errpop(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	free_stack(*stack);
	fclose(info.fp);
	free(info.line);
	exit(EXIT_FAILURE);
}

/**
 * errswap - Print error when stack contains less than two elements for swap
 * @stack: stack
 * @line_number: line number
 */
void errswap(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
	free_stack(*stack);
	fclose(info.fp);
	free(info.line);
	exit(EXIT_FAILURE);
}

/**
 * erradd - Print error when stack contains less than two elements for add
 * @stack: stack
 * @line_number: line number
 */
void erradd(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
	free_stack(*stack);
	fclose(info.fp);
	free(info.line);
	exit(EXIT_FAILURE);
}

/**
 * errsub - Print error when stack contains less than two elements for sub
 * @stack: stack
 * @line_number: line number
 */
void errsub(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
	free_stack(*stack);
	fclose(info.fp);
	free(info.line);
	exit(EXIT_FAILURE);
}

/**
 * errdiv - Print error when stack contains less than two elements for div
 * or if top element is 0
 * @stack: stack
 * @line_number: line number
 * @divcode: error code
 */
void errdiv(stack_t **stack, unsigned int line_number, int divcode)
{
	if (divcode == 1)
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
	else if (divcode == 2)
		fprintf(stderr, "L%u: division by zero\n", line_number);
	free_stack(*stack);
	fclose(info.fp);
	free(info.line);
	exit(EXIT_FAILURE);
}
