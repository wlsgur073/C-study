#include "ft_header.h"

int	main(int argc, char** argv)
{
	char*	buff;
	char	board[SIZE][SIZE];
	int		matrix[SIZE][SIZE];

	g_print = 0;
	argc = 2;
	argv[1] = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
	if (argc != 2)
	{
		error();
		return (1);
	}

	buff = (char*)malloc((sizeof(char) * SIZE * SIZE) + 1);
	if (only_num_init(buff, argv[1]) == FALSE)
	{
		free(buff);
		return (1);
	}
	fill_matrix(buff, matrix);
	fill_null(board);
	fill_board(matrix, board);
	save(0, 0, board, matrix);
	if (g_print == 0)
		error();
	free(buff);
	return (0);
}