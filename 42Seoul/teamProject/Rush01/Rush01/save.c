#include "ft_header.h"

int		valid_condition(int matrix[][SIZE], char board[][SIZE])
{
	if (!(colup(board, matrix) == TRUE && coldown(board, matrix) == TRUE))
		return (FALSE);
	if (!(rowleft(board, matrix) == TRUE && rowright(board, matrix) == TRUE))
		return (FALSE);
	return (TRUE);
}

void	print(char board[][SIZE])
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
			write(1, &(board[i][j++]), 1);
		write(1, "\n", 1);
		i++;
	}
	g_print = 1;
}

void	save(int i, int j, char board[][SIZE], int matrix[][SIZE])
{
	int	num;

	if (i == SIZE)
	{
		valid_condition(matrix, board) == TRUE ? print(board) : 0;
		return;
	}
	if (j == SIZE)
	{
		j = 0;
		save(i + 1, j, board, matrix);
		return;
	}
	num = 0;
	check2(&i, &j, board);
	i == SIZE ? save(i, j, board, matrix) : 0;
	while (++num <= SIZE)
	{
		if (check1(i, j, num, board) == TRUE)
		{
			board[i][j] = (num + '0');
			save(i, j + 1, board, matrix);
			board[i][j] = '\0';
		}
	}
}