#include <io.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comma(void)
{
	ft_putchar(',');
	ft_putchar(' ');
}

void	ft_init_digit(int n, int *digit)
{
	int i;

	i = n - 1;
	while (i > 0)
	{
		if (digit[i] >= 10 - (n - 1 - i))
		{
			digit[i - 1]++;
		}
		i--;
	}
	if (n > 1)
	{
		i = 1;
		while (i < n)
		{
			if (digit[i] >= 10 - (n - 1 - i))
				digit[i] = digit[i - 1] + 1;
			i++;
		}
	}
}

void	ft_print_combn(int n)
{
	int i;
	int digit[9];

	i = 0;
	while (i < n)
	{
		digit[i] = i;
		i++;
	}
	while (1)
	{
		i = 0;

		while (i < n)
			ft_putchar(digit[i++] + '0');

		digit[n - 1]++;

		if (digit[n - 1] == 10)
		{
			ft_init_digit(n, digit);
			if (digit[n - 1] > 9)
				break;
		}
		ft_print_comma();
	}
}

int main()
{
	ft_print_combn(4);
	return 0;
}