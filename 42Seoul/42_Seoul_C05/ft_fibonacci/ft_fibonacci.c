#include <stdio.h>

/*
	0 1 1 2 3 5 8 13 21 34 55 89 144

	ex) fibonacci (5) = 3 + 2 = fibonacci(4) + fibonacci(3)
*/

//int ft_fibonacci(int index)
//{
//	if (index <= 0)
//		return 0;
//	else if (index > 2)
//		return ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
//	else
//		return 1;
//}

int	fib(int n, int a, int b)
{
	if (n == 0)
		return (a);
	if (n == 1)
		return (b);
	return (fib(n - 1, b, a + b));
}

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	return (fib(index, 0, 1));
}

int main()
{
	//for(int i = 0; i < 1000; ++i)
		printf("%d ", ft_fibonacci(1000));

	return 0;
}