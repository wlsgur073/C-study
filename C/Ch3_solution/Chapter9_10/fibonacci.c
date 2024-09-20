#include <stdio.h>

#define COUNT 10

int fibonacci(int number);

int main()
{
	for (int count = 1; count < 13; ++count)
	{
		printf("%d ", fibonacci(count));
	}
	return 0;
}

int fibonacci(int number)
{
	if (number == 0)
		return 0;
	else if(number == 1)
		return 1;
	else
	{
		number = (number - 1) + (number - 2);
	}
	return number;
}