//#include <io.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#pragma warning(disable:4996)

char g_obs;
char g_emp;
char g_ful;
int g_height;
int g_width;

int ft_min(int a, int b, int c)
{
	a = (a > b) ? b : a;
	return ((a > c) ? c : a);
}

void print_map(int** map, int x1, int y1, int max_size)
{
	int x;
	int y;
	char c;

	y = 0;
	while (y < g_height)
	{
		x = 0;
		while (x < g_width)
		{
			if (x1 - max_size + 1 <= x && x <= x1 && y1 - max_size + 1 <= y && y <= y1)
				c = g_ful;
			else
				c = (map[y][x] == 0) * g_obs + (map[y][x] > 0) * g_emp;
//				c = map[y][x] + '0';
			write(1, &c, 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

void calc(int** map)
{
	int i;
	int j;
	int x1;
	int y1;
	int max_size;

	max_size = 0;
	i = 0;
	while (++i < g_height)
	{
		j = 0;
		while (++j < g_width)
		{
			if (map[i][j] == 1)
				map[i][j] = ft_min(map[i - 1][j], map[i][j - 1], map[i - 1][j - 1]) + 1;
			if (map[i][j] > max_size) 
			{
				max_size = map[i][j];
				y1 = i;
				x1 = j;
			}
		}
	}
	print_map(map, x1, y1, max_size);
}

int y_to_int(char* src, int len)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (i <= len)
	{
		if (src[i] < '0' || src[i] > '9')
			return (-1);
		n = n * 10 + src[i] - '0';
		i++;
	}
	return (n);
}

char *map_set(char* line1, int *** map)
{
	int i;
	int j;

	i = 0; 
	while (line1[i] != '\n')
		i++; 
	g_height = y_to_int(line1, i - 4);
	if (i < 4 || g_height == -1)
		return (0);
	g_emp = line1[i - 3] * (line1[i - 3] >= 32 && line1[i - 3] != 127);
	g_obs = line1[i - 2] * (line1[i - 2] >= 32 && line1[i - 2] != 127);
	g_ful = line1[i - 1] * (line1[i - 1] >= 32 && line1[i - 1] != 127);
	if (!g_emp || !g_obs || !g_ful || 
		g_emp == g_obs || g_emp == g_ful || g_obs == g_ful)
		return (0); 
	*map = (int **)malloc(sizeof(int *) * g_height);
	j = 0; 
	while (j < g_height)
		(*map)[j++] = (int*)malloc(sizeof(int) * g_width);
	return (line1 + i + 1);
}

void get_width(char* file)
{
	int i;

	while (*file != '\n')
		file++;
	file++;
	i = 0;
	while (file[i] != '\n')
		i++;
	g_width = i;
}

int str_to_map(char* file)
{
	int i;
	int x;
	int y;
	int** map;

	i = -1;
	x = 0;
	y = 0;
	map = 0;
	get_width(file);
	file = map_set(file, &map);
	if (file == 0)
		return (0);
	while (file[++i])
		if ((file[i] == g_emp || file[i] == g_obs) && x < g_width)
			map[y][x++] = (file[i] == g_emp);
		else if (file[i] == '\n' && x == g_width)
		{
			y++;
			x = 0;
		}
		else
			return (0);
	calc(map);
	return (1);
}

void file_to_str(char * name, char ** file, int len)
{
	int fd;
	int i;
	char c;

	fd = open(name, O_RDONLY);
	i = 0;
	while (i < len)
	{
		read(fd, &c, 1);
		(*file)[i] = c;
		i++;
	}
	(*file)[i] = 0;
	close(fd);
}

int main(int argc, char** argv)
{
	int i;
	int len;
	int fd;
	char* file;
	char c;

//	if (argc < 2)
		//표준입력으로 읽기
	i = 1;
	while (i < argc)
	{
		len = 0;
		fd = open(argv[i], O_RDONLY);
		while (read(fd, &c, 1))
			len++;
		close(fd);
		file = (char *)malloc(sizeof(char) * (len + 1));
		file_to_str(argv[i], &file, len);
		if (!str_to_map(file))
			printf("map error\n");	//map error
		free(file);
		i++;
	}
	return (0);
}