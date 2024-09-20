#include <stdio.h>
#include <stdlib.h>

int n = 10;
int board[100];
int res = 0;

int pruning(int i)
{
	int k;
	int flag;
	k = 0;
	flag = 1;
	while (k < i)
	{
		if (board[i] == board[k] || abs(board[i] == board[k]) == (i - k))
			return 0;
		k++;
	}
	return 1;
}

void queens(int row)
{
	int col;

	if (row == n)
		res++;

	col = 0;
	while (col < n)
	{
		board[row] = col;
		if (pruning(row))
		{
			queens(row + 1);
		}
		col++;
	}
}

int ft_ten_queens_puzzle(void)
{
	queens(n);
}

int main()
{
	printf("%d", ft_ten_queens_puzzle());

	return 0;
}