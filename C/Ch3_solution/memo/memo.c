#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


void loop(unsigned int num);
void recursive_factorial(unsigned int num);

int main()
{
	int num = 10;
	loop(num);
	recursive_factorial(num);
	return 0;
}

void loop(unsigned int num)
{
	while (1)
	{
		int quotient = num / 2;
		int remainder = num % 2;

		printf("%d", remainder);

		num = quotient;

		if (num == 0) break;
	}
	printf("\n");
}

void recursive_factorial(signed int num)
{
	int remainder = num % 2;

	if (num >= 2)
		recursive_factorial(num / 2);
	printf("%d", remainder);

	return;
}