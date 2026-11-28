#include "3-calc.h"

/**
 * main - performs simple operations from command line arguments
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, or 98, 99, 100 on error
 */
int main(int argc, char *argv[])
{
	int a, b;
	int (*func)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		return (98);
	}

	func = get_op_func(argv[2]);
	if (func == NULL || argv[2][1] != '\0')
	{
		printf("Error\n");
		return (99);
	}

	a = atoi(argv[1]);
	b = atoi(argv[3]);

	if ((*argv[2] == '/' || *argv[2] == '%') && b == 0)
	{
		printf("Error\n");
		return (100);
	}

	printf("%d\n", func(a, b));
	return (0);
}
