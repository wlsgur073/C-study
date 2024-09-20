#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#pragma warning(disable:4996)

char g_obs;
char g_emp;
char g_ful;

int calc_and_print(int** map)
{
	if (!map)
		return (1);
	//print해주기
}

char* map_set(char* line1, int*** map, int* width)
{
	int i;
	
	i = 0;
	while (line1[i] != '\n')
		i++;
	//y값을 숫자로 바꿔주기 =
	g_emp = line1[i - 3];
	g_obs = line1[i - 2];
	g_ful = line1[i - 1];
	//printable 체크하기! 
	if (g_emp == g_obs || g_emp == g_ful || g_obs == g_ful)
		return (0);
	//malloc
	//맵의 첫줄을 초기화하는것까지 같이 해주자. 
	
	return (line1 + i + 1);
}

int** str_to_map(char* file)
{
	int i;
	int x;
	int y;
	int width;
	int** map;
	
	i = -1;
	x = 0;
	y = 1;
	map = 0;
	file = map_set(file, &map, &width);
	if (file == 0)
		return (0);
	while (file[++i])
		if (file[i] == g_emp || file[i] == g_obs)
			map[y][x++] = (file[i] == g_emp);
		else if (file[i] == '\n' && x == width)
		{
			y++;
			x = 0;
		}
		else
			return (0);
	return (map);
}

void file_to_str(char* name, char** file, int len)
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
		file = (char*)malloc(sizeof(char) * (len + 1));
		file_to_str(argv[i], &file, len);
		if (calc_and_print(str_to_map(file)))
			//map error
		//free file
			i++;
	}
	return (0);
}
