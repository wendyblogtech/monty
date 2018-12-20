#include "monty.h"

/**
 * _mod - Computes remainder of the division of second top element of stack
 * by top element of stack
 * If stack contains less than 2 elements or if top element is 0, print error
 * Result is stored in second top element of the stack & top element is removed
 * @stack: stack
 * @line_number: line number
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int result = 0, modcode = 0;

	if (!*stack || !(*stack)->next)
	{
		modcode = 1;
		errmul(stack, line_number, modcode);
	}
	if ((*stack)->n == 0)
	{
		modcode = 2;
		errmul(stack, line_number, modcode);
	}
	result = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = result;
	pop(stack, line_number);
}
