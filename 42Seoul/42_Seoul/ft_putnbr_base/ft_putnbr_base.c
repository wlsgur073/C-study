#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define INT_MIN     (-2147483647 - 1)

void ft_putchar(char c)
{
	printf("%c", c);
}

int ft_strlen(char* str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return i;
}

void ft_print(long long ll, long long size, char *base)
{
	if (ll == 0)
		return;
	ft_print(ll / size, size, base);
	ft_putchar(base[ll % size]);	
}

void ft_putnbr_base(int nbr, char* base)
{
	int i;
	long long size;
	long long ll;

	if (base == NULL)
		return;
	i = -1;
	while (base[i++] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return;
	}

	size = ft_strlen(base);
	ll = nbr;
	if (ll < 0)
	{
		ft_putchar('-');
		ft_print(-ll, size, base);
	}
	else
		ft_print(ll, size, base);
}

int main()
{
	char a[] = "0123456789abcdef";
	ft_putnbr_base(-2147483647, a);
	return 0;

}