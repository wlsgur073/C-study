#include "ft_header.h"

int		rowleft(char board[][SIZE], int matrix[][SIZE])
{
	int		i;
	int		j;
	int		count;
	char	max;

	i = 0;
	while (i < SIZE)
	{
		count = 1;
		max = board[i][0];
		j = 1;
		while (j < SIZE)
		{
			if (max < board[i][j])
			{
				count++;
				max = board[i][j];
			}
			j++;
		}
		if (count != matrix[2][i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int		rowright(char board[][SIZE], int matrix[][SIZE])
{
	int		i;
	int		j;
	int		count;
	char	max;

	i = 0;
	while (i < SIZE)
	{
		count = 1;
		j = SIZE - 2;
		max = board[i][SIZE - 1];
		while (j >= 0)
		{
			if (max < board[i][j])
			{
				count++;
				max = board[i][j];
			}
			j--;
		}
		if (count != matrix[3][i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int		colup(char board[][SIZE], int matrix[][SIZE])
{
	int		i;
	int		j;
	int		count;
	char	max;

	i = 0;
	while (i < SIZE)
	{
		count = 1;
		max = board[0][i];
		j = 1;
		while (j < SIZE)
		{
			if (max < board[j][i])
			{
				count++;
				max = board[j][i];
			}
			j++;
		}
		if (count != matrix[0][i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int		coldown(char board[][SIZE], int matrix[][SIZE])
{
	int		i;
	int		j;
	int		count;
	char	max;

	i = 0;
	while (i < SIZE)
	{
		count = 1;
		j = SIZE - 2;
		max = board[SIZE - 1][i];
		while (j >= 0)
		{
			if (max < board[j][i])
			{
				count++;
				max = board[j][i];
			}
			j--;
		}
		if (count != matrix[1][i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}