#include "monty.h"

/**
 * get_op_func - Function that selects the correct function to perform
 * the operation asked by the user
 * @stack: stack
 * @line_number: line number
 * Return: 1 for success, 0 for error
 */
int get_op_func(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", _add},
	{"nop", nop},
	{"sub", _sub},
	{"div", _div},
	{"mul", _mul},
	{"mod", _mod},
	{"pchar", _pchar},
	{"pstr", _pstr},
	{"rotl", _rotl},
	{"rotr", _rotr},
	{"stack", _stack},
	{"queue", _queue},
	{NULL, NULL}
	};
	int i;

	i = 0;
	while (ops[i].opcode != NULL)
	{
		if (info.command[0] == '#')
		{
			nop(stack, line_number);
			return (1);
		}
		else if (strcmp(info.command, ops[i].opcode) == 0)
		{
			ops[i].f(stack, line_number);
			return (1);
		}
		i++;
	}
	return (0);
}

/**
 * free_close - Free stack, free line, and close file
 * @stack: stack
 */
void free_close(stack_t *stack)
{
	stack_t *mover = stack;

	while (mover)
	{
		stack = (stack)->next;
		free(mover);
		mover = stack;
	}
	free(info.line);
	fclose(info.fp);
}

/**
 * isdigits - check if argument is a number
 * @number: number
 * Return: 1 if yes, 0 if no
 */
int isdigits(char *number)
{
	int i;

	for (i = 0; number[i] != '\0'; i++)
	{
		if (i == 0 && number[i] == '-')
			i++;
		if (!isdigit(number[i]))
			return (0);
	}
	return (1);
}
