#include <stdio.h>

int ft_recursive_power(int nb, int power)
{
	int res;

	res = nb;
	if (power < 0)
		return 0;
	else if (power > 0)
		return res * ft_recursive_power(nb, power - 1);
	else
		return 1;
}

int main()
{

	printf("%d", ft_recursive_power(2, 0));

	return 0;
}