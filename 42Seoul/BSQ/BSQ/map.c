/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:16:43 by djo               #+#    #+#             */
/*   Updated: 2021/03/16 19:02:50 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		y_to_int(char *src, int len)
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

char	*map_set(char *line1, int ***map, int i, int j)
{
	while (line1[i] != '\n' && line1[i])
		i++;
	if (line1[i] == '\0')
		return (0);
	g_height = y_to_int(line1, i - 4);
	if (i < 4 || g_height < 1)
		return (0);
	g_emp = line1[i - 3] * (line1[i - 3] >= 32 && line1[i - 3] != 127);
	g_obs = line1[i - 2] * (line1[i - 2] >= 32 && line1[i - 2] != 127);
	g_ful = line1[i - 1] * (line1[i - 1] >= 32 && line1[i - 1] != 127);
	if (!g_emp || !g_obs || !g_ful ||
		g_emp == g_obs || g_emp == g_ful || g_obs == g_ful)
		return (0);
	*map = (int **)malloc(sizeof(int *) * g_height);
	if (!*map)
		exit(1);
	while (j < g_height)
	{
		(*map)[j] = (int*)malloc(sizeof(int) * g_width);
		if (!(*map)[j++])
			exit(1);
	}
	return (line1 + i + 1);
}

int		get_width(char *file)
{
	int i;

	while (*file != '\n' && *file)
		file++;
	file++;
	if (!*file)
		return (0);
	i = 0;
	while (file[i] != '\n')
		i++;
	if (!file[i])
		return (0);
	g_width = i;
	return (1);
}

void	next(int ***map)
{
	int i;

	calc(*map);
	i = 0;
	while (i < g_height)
		free((*map)[i++]);
	free(*map);
}

int		str_to_map(char *file)
{
	int i;
	int x;
	int y;
	int **map;

	i = -1;
	x = 0;
	y = 0;
	map = 0;
	file = map_set(file, &map, 0, 0);
	if (file == 0 || !get_width(file))
		return (0);
	while (file[++i] && y < g_height)
		if ((file[i] == g_emp || file[i] == g_obs) && x < g_width)
			map[y][x++] = (file[i] == g_emp);
		else if (file[i] == '\n' && x == g_width)
		{
			y++;
			x = 0;
		}
		else
			return (0);
	if (x == 0 && y == g_height && !file[i])
		next(&map);
	return (x == 0 && y == g_height && !file[i]);
}
