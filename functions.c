#include "monty.h"

/**
 * add_new_node - add the new stack node.
 * @head: stack node head.
 * @data: the data.
 * Return: no return.
*/
void add_new_node(stack_t **head, int data)
{

	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("stack over flow\n");
		exit(1);

	}
	if (*head != NULL)
		(*head)->prev = new_node;

	new_node->n = data;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

/**
 * push_node - push the new stack node.
 * @head: stack node head.
 * @line_num: line_number.
 * Return: no return.
*/
void push_node(stack_t **head, unsigned int line_num)
{
	int check, i = 0, data;

	if (data_t.value)
	{
		if (data_t.value[0] == '-')
			i++;
		for (; data_t.value[i] != '\0'; i++)
		{
			if (data_t.value[i] > 57 || data_t.value[i] < 48)
				check = 1;

		}

	if (check == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		fclose(data_t.file);
		free(data_t.inp);
		free_snodes(*head);
		exit(EXIT_FAILURE);
	}

	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		fclose(data_t.file);
		free(data_t.inp);
		free_snodes(*head);
		exit(EXIT_FAILURE);
	}

	data = atoi(data_t.value);
	add_new_node(head, data);
}






/**
 * print_nodes - prints the stack node data.
 * @stack: stack node head.
 * @line_number: no used.
 * Return: no return.
*/
void print_nodes(stack_t **stack, unsigned int line_number)
{

	stack_t *head;
	(void)line_number;

	if (stack == NULL)
	{
		return;
	}
	head = *stack;
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}

/**
 * pop_tnode - prints the top stack node.
 * @stack: stack head node.
 * @line_number: line_number
 * Return: no return
*/

void pop_tnode(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(data_t.file);
		free(data_t.inp);
		free_snodes(*stack);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = tmp->next;
	free(tmp);
}


/**
 * pint_tnode - prints the top stack node.
 * @stack: stack node head.
 * @line_number: line_number.
 * Return: no return.
*/
void pint_tnode(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(data_t.file);
		free(data_t.inp);
		free_snodes(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

