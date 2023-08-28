#include "monty.h"

/**
 * execute_op - find the opcode function.
 * @stack: stack node head.
 * @opcode: the opcode.
 * @line_num: line_number.
 * Return: no return.
*/
void execute_op(stack_t **stack, char *opcode, int line_num)
{
	int i = 0;
	instruction_t oparray[] = {
		{"push", push_node},
		{"pall", print_nodes},
		{"pint", pint_tnode},
		{"pop", pop_tnode},
		{NULL, NULL}
	};

	while (oparray[i].opcode && opcode)
	{
		if (strcmp(opcode, oparray[i].opcode) == 0)
		{
			oparray[i].f(stack, line_num);
			return;
		}
		i++;
	}

	if (opcode && oparray[i].opcode == NULL)
	{
		printf("L%d: unknown instruction %s\n", line_num, opcode);
		fclose(data_t.file);
		free(data_t.inp);
		free_snodes(*stack);
		exit(EXIT_FAILURE);
	}
}
