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
		errmod(stack, line_number, modcode);
	}
	if ((*stack)->n == 0)
	{
		modcode = 2;
		errmod(stack, line_number, modcode);
	}
	result = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = result;
	pop(stack, line_number);
}

/**
 * _pchar - Print char at the top of the stack
 * The integer stored at the top of the stack is treated as the ascii value of
 * the character to be printed
 * If the value is not in the ascii table or if stack is empty, print error
 * @stack: stack
 * @line_number: line number
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int pcharcode = 0;

	if (!*stack)
	{
		pcharcode = 1;
		errpchar(stack, line_number, pcharcode);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		pcharcode = 2;
		errpchar(stack, line_number, pcharcode);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * _pstr - Prints the string starting at top of the stack, followed by new line
 * Integer stored in each element of the stack is treated as the ascii value of
 * the character to be printed
 * The string stops when the stack is over, value of element is 0, or value is
 * not in the ascii table
 * If stack is empty, print only a new line
 * @stack: stack
 * @line_number: line number
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *mover;
	(void)line_number;

	mover = *stack;
	while (mover)
	{
		if ((mover)->n < 1 || (mover)->n > 127)
			break;
		printf("%c", (mover)->n);
		mover = (mover)->next;
	}
	printf("\n");
}

/**
 * _rotl - Rotates the stack to the top
 * The top element of the stack becomes the last one
 * and the second top element of the stack becomes the first one
 * rotl never fails
 * @stack: stack
 * @line_number: line number
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *mover;
	(void)line_number;

	if (*stack)
	{
		mover = *stack;
		temp = mover->n;
		while (mover->next)
		{
			mover->n = mover->next->n;
			mover = mover->next;
		}
		mover->n = temp;
	}
}
