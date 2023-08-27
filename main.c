#include "monty.h"
#include <stdbool.h>
#include <string.h>

/**
 * main - the entry level
 * @argc: number of args
 * @argv: array of args
 *
 * Return: 0 if all good, 1 otherwise
 */

int main(int argc, char *argv[])
{
	datas data_t = {NULL, NULL, NULL, 0};
	char inp[2048];
	int line_num = 0;
	stack_t *stack = NULL;
	FILE *fptr;
	bool keep_reading;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	fptr = fopen(argv[1], "r");
	data_t.file = fptr;
	if (fptr == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	keep_reading = true;
	if (feof(fptr))
	{
		keep_reading = false;
	}
	while (keep_reading == true)
	{
		fgets(inp, MAX_LINE, fptr);
		if (feof(fptr))
		{
			break;
		}
		data_t.inp = inp;
		if (*inp != '\n')
		{
			line_num++;
			parse_line(&stack, inp, line_num);
		}
	}
	free_snodes(stack);
	return (1);
}
