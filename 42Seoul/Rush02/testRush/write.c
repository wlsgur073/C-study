#include "rush02.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char* str)
{
	while (*str)
		ft_putchar(*(str++));
}

void	print_error_msg(char* str)
{
	ft_putstr("Error: ");
	ft_putstr(str);
	ft_putstr("\n");
}

void	print(char* str)
{
	if (!g_is_first)
		ft_putstr(" ");
	g_is_first = 0;
	ft_putstr(str);
}