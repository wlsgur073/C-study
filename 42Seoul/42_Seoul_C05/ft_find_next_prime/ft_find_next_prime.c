#include <stdio.h>
#include <stdlib.h>

//int ft_find_next_prime(int nb)
//{
//	int i;
//	int j;
//	int *prime;
//
//	prime = (int*)malloc(nb);
//	i = 2;
//	while (i <= nb)
//	{
//		prime[i] = i;
//		i++;
//	}
//
//	i = 1;
//	while (i++ <= nb)
//	{
//		if (prime[i] == 0) continue;
//		j = i + i;
//		while (j <= nb)
//		{
//			prime[j] = 0;
//			j += i;
//		}
//	}
//	i = 2;
//	while (i <= nb)
//	{
//		if (prime[i] != 0)
//			printf("%d ", prime[i]);
//		i++;
//	}
//
//	return 1;
//}

int is_prime(int nb)
{
	int i;

	i = 2;
	if (nb <= 1)
		return 0;
	while (i < nb)
	{
		if (nb % i == 0)
			return 0;
		i++;
	}
	return nb;
}

int ft_find_next_prime(int nb)
{
	int cmp;

	while (1)
	{
		cmp = nb + 1;

		if (is_prime(nb) < is_prime(cmp))
			return cmp;
		else
			nb++;
	}
}

int main()
{
	printf("%d", ft_find_next_prime(-1));
	return 0;
}