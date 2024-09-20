#include <stdio.h>

char is_space(char c)
{
	if (c == '\n' || c == '\t' || c == ' ' ||
		c == '\f' || c == '\v' || c == '\r')
		return (c);
	return NULL;
}

int ft_in_base(char c, char* base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return i;
		i++;
	}
	return -1;
}

int ft_atoi(char* str, int base)
{
	int i;
	int r;

	i = 1;
	r = 0;

	if (*str == NULL)
		return (0);
	while (is_space(*str))
	{
		str++;
	}
	while (*str == '-')
	{
		i *= -1;
		str++;
	}
	while (*str)
	{
		r = r * base + *str - '0';
		str++;
	}
	return (r * i);
}


int ft_atoi_base(char* str, char* base)
{
	int i;
	int n_base;
	int r;

	if (*base == NULL)
		return;
	i = -1;
	while (base[i++] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return 0;
	}

	i = 1;
	n_base = 0;
	r = 0;
	while (base[n_base])
		n_base++;
	while (is_space(*str))
		str++;
	while (*str == '-')
	{
		i *= -1;
		str++;
	}
	while (*str && ft_in_base(*str, base) >= 0)
	{
		r = r * n_base + ft_in_base(*str, base);
		str++;
	}
	return r * i;
}

int main()
{
	char a[] = "1100";
	char b[] = "ca";

	printf("%d\n", ft_atoi_base(a, b));

	return 0;
}