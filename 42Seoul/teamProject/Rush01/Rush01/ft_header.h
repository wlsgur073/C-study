#ifndef FT_HEADER_H
# define FT_HEADER_H
//# include <unistd.h>
#include <stdio.h>
# include <stdlib.h>
# define SIZE 4
# define TRUE 1
# define FALSE 0

int		g_print;
void	error(void);
int		is_num_n_space(char c, int index);
int		only_num_init(char* buff, char* argv);
void	fill_matrix(char* buff, int matrix[][SIZE]);
void	fill_null(char board[][SIZE]);
void	fill_board(int matrix[][SIZE], char board[][SIZE]);
int		check1(int i, int j, int num, char board[][SIZE]);
void	check2(int* i, int* j, char board[][SIZE]);
int		rowleft(char board[][SIZE], int matrix[][SIZE]);
int		rowright(char board[][SIZE], int matrix[][SIZE]);
int		colup(char board[][SIZE], int matrix[][SIZE]);
int		coldown(char board[][SIZE], int matrix[][SIZE]);
int		valid_condition(int matrix[][SIZE], char board[][SIZE]);
void	print(char board[][SIZE]);
void	save(int i, int j, char board[][SIZE], int matrix[][SIZE]);
#endif