#include <stdio.h>

int ft_iterative_power(int nb, int power)
{
	int res;

	res = nb;
	if (power < 0)
		return 0;
	else if (power == 0)
		return 1;
	while (--power)
	{
		res *= nb;
	}

	return res;
}

int main()
{

	printf("%d", ft_iterative_power(2, 3));

	return 0;
}