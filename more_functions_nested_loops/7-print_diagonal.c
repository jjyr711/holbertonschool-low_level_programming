#include "main.h"

/**
 * print_diagonal - draws a diagonal line on the terminal using '\'
 * @n: number of times '\' should be printed
 */
void print_diagonal(int n)
{
	int row, space;

	if (n > 0)
	{
		for (row = 0; row < n; row++)
		{
			for (space = 0; space < row; space++)
				_putchar(' ');
			_putchar('\\');
			_putchar('\n');
		}
	}
	else
	{
		_putchar('\n');
	}
}
