/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 09:14:49 by djo               #+#    #+#             */
/*   Updated: 2021/03/16 19:02:17 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char g_obs;
char g_emp;
char g_ful;
int g_height;
int g_width;

void	file_to_str(char *name, char **file, int len)
{
	int		fd;
	int		i;
	char	c;

	if (!*file)
		exit(1);
	fd = open(name, O_RDONLY);
	if (fd < 0)
		exit(1);
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

void	read_stdin(void)
{
	char	c;
	int		len;
	char	*file;
	int		fd;

	len = 0;
	fd = open("tempfile", O_RDWR);
	if (fd < 0)
		exit(1);
	while (read(0, &c, 1))
	{
		write(fd, &c, 1);
		len++;
	}
	read(0, &c, 1);
	write(fd, "\0", 1);
	close(fd);
	file = (char *)malloc(sizeof(char) * (len + 1));
	file_to_str("tempfile", &file, len);
	if (!str_to_map(file))
		write(2, "map error\n", 11);
	free(file);
}

int		main(int argc, char **argv)
{
	int		i;
	int		len;
	int		fd;
	char	*file;
	char	c;

	if (argc == 1)
		read_stdin();
	i = 0;
	while (++i < argc || argc > 1)
	{
		len = 0;
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
			return (1);
		while (read(fd, &c, 1))
			len++;
		close(fd);
		file = (char *)malloc(sizeof(char) * (len + 1));
		file_to_str(argv[i], &file, len);
		if (!str_to_map(file))
			write(2, "map error\n", 11);
		free(file);
	}
	return (0);
}
