#include <stdio.h>

#define N 4

char g_col_up[N];
char g_col_down[N];
char g_row_left[N];
char g_row_right[N];

char g_buf[16];

int isnum(char c)
{
	if (c > '0' && c < '5')
		return 1;
	return 0;
}

char onlyNum(char* str)
{
	int i;
	int k;

	i = 0;
	while (*str)
	{
		if (isnum(*str))
			g_buf[i++] = *str;
		str++;
	}

	if (i > 16)
		return NULL;

	i = 0;
	k = 0;
	while (g_buf[i])
	{
		if (k == 4)
			k = 0;

		if (i / 4 == 0)
			g_col_up[k] = g_buf[i];
		else if (i / 4 == 1)
			g_col_down[k] = g_buf[i];
		else if (i / 4 == 2)
			g_row_left[k] = g_buf[i];
		else if (i / 4 == 3)
			g_row_right[k] = g_buf[i];
		i++;
		k++;
	}
	for (k = 0; k < 4; ++k)
	{
		//printf("%c ", g_col_up[k]);
		//printf("%c ", g_col_down[k]);
		//printf("%c ", g_row_left[k]);
		printf("%c ", g_row_right[k]);
	}
	return NULL;
}

char* ft_split(char* str);

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		// error
		return 1;
	}
	char* arr = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";

	checkstr(arr);

	return 0;
}


/*
	가장 높은 건물순으로 배열을 선언해주는 것이 좋다.
	arr[ROW][COL] = {0} {1} {2} {3}
	arr[0] = arr[0][0~3]

	[0][0] ~ [0][5] // col up
	[1][0] ~ [1][5] // row
	[2][0] ~ [2][5] // row
	[3][0] ~ [3][5] // row
	[4][0] ~ [4][5] // row
	[5][0] ~ [5][5] // col down

	0000
	0000
	0000
	0000
	0000
*/

char* ft_split(char* str)
{
	static char* sp = NULL;
	char* tp;
	char* rp;

	if (sp == NULL)
		sp = str;

	if (*sp == '\0')
		return NULL;

	tp = sp;
	while ((*tp != '\0') && (*tp != ' '))
	{
		tp++;
	}
	if (*tp != '\0')
	{
		*tp = '\0';
		tp++;
	}

	rp = sp;
	sp = tp;
	return rp;
}