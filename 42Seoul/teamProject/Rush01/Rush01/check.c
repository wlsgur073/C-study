#include "ft_header.h"

void	error(void)
{
	char* err;

	err = "Error";
	while (*err)
		write(1, err++, 1);
	write(1, "\n", 1);
}

int		is_num_n_space(char c, int index)
{
	if (index % 2 == 0)
	{
		if (c > '0' && c <= '0' + SIZE)
			return (TRUE);
	}
	else
	{
		if (c == ' ')
			return (2);
	}
	return (FALSE);
}

int		only_num_init(char* buff, char* argv)
{
	int	i;
	int	n;
	int	max;
	
	max = (SIZE * SIZE);
	i = 0;
	n = 0;
	while (argv[i] && n < max)
	{
		if (is_num_n_space(argv[i], i) == TRUE)
			buff[n++] = argv[i];
		else if (is_num_n_space(argv[i], i) == FALSE)
		{
			error();
			return (FALSE);
		}
		i++;
	}
	buff[n] = '\0';
	if (argv[i] == 0 && n == max)
		return (TRUE);
	error();
	return (FALSE);
}

int		check1(int i, int j, int num, char board[][SIZE])
{
	int	n;

	n = 0;
	while (n < SIZE)
	{
		if (board[i][n] == (num + '0') || board[n][j] == (num + '0'))
			return (FALSE);
		n++;
	}
	return (TRUE);
}

void	check2(int* i, int* j, char board[][SIZE])
{
	while (board[*i][*j] != '\0' && *i != SIZE)
	{
		if (*j == SIZE - 1)
		{
			*j = 0;
			(*i)++;
		}
		else
			(*j)++;
	}
}