#include "monty.h"

/**
 * main - Entry point for Monty interpreter
 * @argc: argument count
 * @argv: argument variable
 * Return: Always EXIT_SUCCESS
 */
int main(int argc, char **argv)
{
	size_t len = 0;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	int ret_ops = 0;

	info.line = NULL;
	info.number = NULL;
	if (argc != 2)
		errac();
	info.fp = fopen(argv[1], "r");
	if (info.fp == NULL)
		erropen(argv[1]);
	while (getline(&info.line, &len, info.fp) != -1)
	{
		line_number++;
		info.command = strtok(info.line, MY_DELIM);
		info.number = strtok(NULL, MY_DELIM);
		if (info.command)
			ret_ops = get_op_func(&stack, line_number);
		if (ret_ops == 0)
			errnomatch(&stack, line_number);
	}
	free(info.line);
	free_stack(stack);
	fclose(info.fp);
	return (EXIT_SUCCESS);
}
