#include "monty.h"

void parse_line(stack_t **stack, char *inp, int line_num)
{
	char *opcode, *op_value;
	const char *delim = "\n ";

	if (inp == NULL)
		fprintf(stderr, "Error: malloc failed\n");

	opcode = strtok(inp, delim);
	op_value = strtok(NULL, delim);
	data_t.value = op_value;

	execute_op(stack, opcode, line_num);
}

/**
* free_stack - frees a doubly linked list
* @head: head of the stack
*/
void free_snodes(stack_t *head)
{
	stack_t *temp;

	if (head == NULL)
		return;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
