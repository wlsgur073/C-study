#include "header.h"

char	g_emp;
char	g_obs;
char	g_ful;
int		g_width;
int		g_height;
t_bsq	g_bsq;

int		to_str(int fd, char *file[])
{
	int		i;
	char	c;
	
	if (!*file)
		return (1);
	i = 0;
	while (read(fd, &c, 1))
	{
		(*file)[i] = c;
		i++;
	}
	(*file)[i] = 0;
	return (0);
}

int		ft_file_len(char *name)
{
	int len;
	int fd;
	char c;

	fd = open(name, 0);
	while (read(fd, &c, 1))
		len++;
	close(fd);
	return (len);
}

void	read_stdin(char *name)
{
	int fd;
	char c;

	fd = open(name, 2);
	while (read(0, &c, 1))
	{
		write(fd, &c, 1);
	}
	write(fd, "\26", 1);
	close(fd);
}

void	ft_bsq(char *name)
{
	int **map;
	char *file;
	char *temp_file;
	int i;
	int fd;

	file = (char *)malloc(sizeof(char) * (ft_file_len(name) + 1));		
	temp_file = file;
	fd = open(name, 0);
	if (to_str(fd, &file) || ft_init(&file))
		write(2, "map error\n", 10);
	else
	{
		if (print_map(ft_map(&map, &file, 0, 0)))
			write(2, "map error\n", 10);
		i = 0;
		while (i < g_height)
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
	close(fd);
	free(temp_file);
}

int		main(int argc, char **argv)
{
	int i;
	char *name;

	i = 0;
	while (++i < argc || (i == 1 && argc == 1))
	{
		if (argc == 1)
		{
			name = "tempfile";
			read_stdin(name);
		}
		else
			name = argv[i];
		ft_bsq(name);
	}
	return (0);
}
