#include <stdio.h>

#define SIZE 4
// necessary global variable
char g_buf[16];
int	col[2][SIZE];
int	row[2][SIZE];

int isnum(char c)
{
	if (c > '0' && c < '5')
		return 1;
	return 0;
}

void onlyNumInit(char* str)
{
	int i;
	int n;

	i = 0;
	while (*str)
		if (isnum(*str))
			g_buf[i++] = *str;
	str++;

	i = 0;
	n = 0;
	while (g_buf[i])//insert col, row array
	{
		if (n == 4)
			n = 0;

		if (i / 4 == 0) // 0 ~3
			col[0][n] = g_buf[i] - '0';
		else if (i / 4 == 1) // 4~7
			col[1][n] = g_buf[i] - '0';
		else if (i / 4 == 2) // 8~ 11 
			row[0][n] = g_buf[i] - '0';
		else if (i / 4 == 3) // 12 ~15
			row[1][n] = g_buf[i] - '0';
		n++;
		i++;
	}
}



int main(int argc, char** argv)
{
	int i;
	int n;

	argc = 2;
	if (argc != 2)
		return (1);
	argv[1] = "4 2 3 1 1 2 2 2 4 3 2 1 1 2 2 2";

	i = 0;
	n = 0;
	onlyNumInit(argv[1]);
	// g_buf 4 2 3 1 1 2 ..

	for (int j = 0; j < SIZE; j++)
	{
		printf("%d ", col[1][j]);
	}
}