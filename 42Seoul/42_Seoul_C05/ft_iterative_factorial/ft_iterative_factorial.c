#include <stdio.h>

int		ft_iterative_factorial(int nb)
{
	int	ans;

	ans = 1;
	if (nb < 0)
		return 0;
	else if (nb == 0)
		return 1;
	else
		while (nb)
			ans *= (nb--);

	return (ans);
}

int main()
{

	printf("%d", ft_iterative_factorial(5));

	return 0;
}