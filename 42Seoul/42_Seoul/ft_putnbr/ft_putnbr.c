#include <stdio.h>

#define INT_MIN     (-2147483647 - 1)
/*
	(-2147483647 - 1)�� ����
	32��Ʈ�� int, 64��Ʈ�� long�̴�.
	32��Ʈ�� long�� long longŸ���̴�.
	�׷��� -2147483648�� long���� int�� �ƴϴ�.
	printf("%zu %zu\n", sizeof INT_MIN, sizeof -2147483648);
	4 8 ��°�

*/

void *ft_putchar(char c)
{
	printf("%c", c);
}

void ft_putnbr(int nb)
{
	if (nb == INT_MIN)
	{
		printf("%d", nb);
		return;
	}
	else if (nb < 0)
	{
		printf("-");
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
}

int main()
{
	//ft_putnbr(-2147483648);
	return 0;
}