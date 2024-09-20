#include "ft_header.h"

void	fill_matrix(char* buff, int matrix[][SIZE])
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
			matrix[i][j++] = buff[n++] - '0';
		i++;
	}
}

void	fill_null(char board[][SIZE])
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
			board[i][j++] = '\0';
		i++;
	}
}

void	fill_board(int matrix[][SIZE], char board[][SIZE])
{
	int	i;
	int	j;

	i = -1;
	while (++i < SIZE)
	{
		j = -1;
		if (matrix[0][i] == SIZE)
			while (++j < SIZE)
				board[j][i] = (j + 1) + '0';
		else if (matrix[1][i] == SIZE)
			while (++j < SIZE)
				board[j][i] = (SIZE - j) + '0';
		j = -1;
		if (matrix[2][i] == SIZE)
			while (++j < SIZE)
				board[i][j] = (j + 1) + '0';
		else if (matrix[3][i] == SIZE)
			while (++j < SIZE)
				board[i][j] = (SIZE - j) + '0';
	}
}