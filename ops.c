#include "monty.h"

/**
 * push - Push an element to the stack
 * If argument is not given or if it is not a number, print error message
 * @stack: stack
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *mover = *stack;
	char *push_arg = strtok(NULL, MY_DELIM);

	if (push_arg == NULL || !(isdigits(push_arg)))
		errpush(stack, line_number);
	if (isdigits(push_arg))
	{
		new = malloc(sizeof(stack_t));
		if (new == NULL)
		{
			free_stack(*stack);
			free(info.line);
			fclose(info.fp);
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		new->n = atoi(push_arg);
		if (info.flag)
		{
			new->prev = NULL;
			new->next = NULL;
			if (!*stack)
				*stack = new;
			else
			{
				while (mover->next)
					mover = mover->next;
				new->prev = mover;
				mover->next = new;
			}
		}
		else
		{
			new->prev = NULL;
			new->next = *stack;
			if (*stack)
				(*stack)->prev = new;
			*stack = new;
		}
	}
}

/**
 * pall - print all nodes
 * @stack: stack
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *mover = *stack;
	(void)line_number;

	while (mover)
	{
		printf("%d\n", mover->n);
		mover = mover->next;
	}
}

/**
 * pint - print number of head node
 * @stack: stack
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
		errpint(stack, line_number);
	printf("%d\n", (*stack)->n);
}

/**
 * pop - remove top element of stack
 * @stack: stack
 * @line_number: line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *pointer;

	if (!*stack)
		errpop(stack, line_number);
	if ((*stack)->next != NULL)
	{
		pointer = (*stack)->next;
		pointer->prev = NULL;
		free(*stack);
		*stack = pointer;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}
/**
 * swap - swap top two elements of stack
 * @stack: stack
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp = 0;

	if (!*stack || !(*stack)->next)
		errswap(stack, line_number);
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
