#include <stdio.h>

#define INT_MIN     (-2147483647 - 1)
/*
	(-2147483647 - 1)인 이유
	32비트는 int, 64비트는 long이다.
	32비트의 long은 long long타입이다.
	그래서 -2147483648은 long이지 int가 아니다.
	printf("%zu %zu\n", sizeof INT_MIN, sizeof -2147483648);
	4 8 출력값

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