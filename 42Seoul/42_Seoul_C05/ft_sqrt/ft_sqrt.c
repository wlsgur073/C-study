#include <stdio.h>

int ft_sqrt(int nb)
{
	int i;

	if (nb <= 0)
		return 0;

	i = 1;
	while (i * i < nb)
		i++;
	
	return ((i * i) == nb) ? i : 0;
}

int main()
{
	printf("%d", ft_sqrt(12));

	return 0;
}