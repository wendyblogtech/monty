#include "monty.h"

/**
 * _add - Add top two elements of stack
 * If stack contains less than two elements, print error message
 * Result is stored in second top element and top element is removed
 * @stack: stack
 * @line_number: line number
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int result = 0;

	if (!*stack || !(*stack)->next)
		erradd(stack, line_number);
	result = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = result;
	pop(stack, line_number);
}

/**
 * nop - Doesn't do anything
 * @stack: stack
 * @line_number: line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * _sub - Subtract the top element of the stack from second top element
 * If stack contains less than two elements, print error message
 * Result is stored in second top element of the stack & top element is removed
 * @stack: stack
 * @line_number: line number
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int result = 0;

	if (!*stack || !(*stack)->next)
		errsub(stack, line_number);
	result = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = result;
	pop(stack, line_number);
}

/**
 * _div - Divide the second top element of the stack by top element of stack
 * If stack contains less than 2 elements or if top element is 0, print error
 * Result is stored in second top element of the stack & top element is removed
 * @stack: stack
 * @line_number: line number
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int result = 0, divcode = 0;

	if (!*stack || !(*stack)->next)
	{
		divcode = 1;
		errdiv(stack, line_number, divcode);
	}
	if ((*stack)->n == 0)
	{
		divcode = 2;
		errdiv(stack, line_number, divcode);
	}
	result = (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = result;
	pop(stack, line_number);
}

/**
 * _mul - Multiplies the second top element of stack with the top element
 * If stack contains less than two elements, print error message
 * Result is stored in second top element of the stack & top element is removed
 * @stack: stack
 * @line_number: line number
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int result = 0;

	if (!*stack || !(*stack)->next)
		errmul(stack, line_number);
	result = (*stack)->next->n * (*stack)->n;
	(*stack)->next->n = result;
	pop(stack, line_number);
}
