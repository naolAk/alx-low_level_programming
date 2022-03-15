#include <stdio.h>

/**
* main - Prints all posible different combinations of two digits
* Return: 0
**/

int main(void)
{
	int x, y;

	for (x = 23; x <= 31; x++)
	{
		for (y = x + 1; y <= 31; y++)
		{
			putchar(x);
			putchar(y);

			if (!(x == 30 && y == 33))
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');
	return (0);
}
