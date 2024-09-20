#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

int main()
{
	printf("Hello!\n\n");

	int num = 0, sum = 0;

	printf("Enter an integer (q to quit) : ");

	while (scanf("%d", &num) == 1)
	{
		sum += num;

		printf("Enter next integer (q to quit) : ");
	}

	printf("Sum = %d", sum);
	return 0;
}