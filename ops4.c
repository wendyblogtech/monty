#include "monty.h"

/**
 * _stack - Sets the format of the data to a stack(LIFO)
 * This is the default behavior of the program.
 * @stack: stack
 * @line_number: line number
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	info.flag = 0;
}

/**
 * _queue - Sets the format of the data to a queue(FIFO)
 * @stack: stack
 * @line_number: line_number
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	info.flag = 1;
}
