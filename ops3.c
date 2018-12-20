#include "monty.h"

/**
 * _mod - Computes remainder of the division of second top element of stack
 * by top element of stack
 * If stack contains less than two elements, print error message
 * Result is stored in second top element of the stack & top element is removed
 * @stack: stack
 * @line_number: line number
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int result = 0;

	if (!*stack || !(*stack)->next)
		errmul(stack, line_number);
	result = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = result;
	pop(stack, line_number);
}
