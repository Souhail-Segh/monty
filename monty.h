#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0
#define MAX_LINE 2048
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct datas - struct have variables: value, inp, file.
 * @value: the opcode value.
 * @inp: the input.
 * @file: pointer to monty file.
 * Description: make this variable golpal.
 */
typedef struct datas
{
	char *value;
	char *inp;
	FILE *file;
} datas;
extern datas data_t;

void add_new_node(stack_t **head, int data);
void execute_op(stack_t **stack, char *opcode, int line_num);
void free_snodes(stack_t *head);
void parse_line(stack_t **stack, char *inp, int line_number);
void push_node(stack_t **head, unsigned int line_num);
void print_nodes(stack_t **stack, unsigned int line_number);
void pop_tnode(stack_t **stack, unsigned int line_number);
void pint_tnode(stack_t **head, unsigned int line_number);

#endif
