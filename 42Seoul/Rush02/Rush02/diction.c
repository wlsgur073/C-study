/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diction.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 18:16:29 by jupark            #+#    #+#             */
/*   Updated: 2021/03/14 22:12:50 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int			insert_line_to_hash(char *str)
{
	char *ptr;
	char *key;
	char *val;

	ptr = str;
	key = str;
	while (*ptr != ':')
		++ptr;
	key = (char*)malloc(ptr - key + 1);
	ft_strcpy(key, str, ptr - 1);
	val = ++ptr;
	str = val;
	while (*ptr)
		++ptr;
	val = (char*)malloc(ptr - val + 1);
	ft_strcpy(val, str, ptr - 1);
	key = trim_side(key);
	val = trim_side(val);
	if (ft_is_valid(key) < 0)
		return (0);
	sethash(g_dict, ft_atov(key), key, val);
	return (1);
}

int			create_dictionary_hash(char *file)
{
	int		op;
	int		cur;
	char	*line;

	if ((op = open(file, O_RDONLY)) == -1)
		return (-1);
	line = (char*)malloc(MAX_VALUE_SIZE);
	cur = -1;
	while ((read(op, &line[++cur], 1)))
	{
		if (line[cur] == '\n')
		{
			line[cur] = 0;
			if (line[0] != 0)
				if (!insert_line_to_hash(line))
					return (-2);
			cur = -1;
		}
	}
	close(op);
	free(line);
	return (1);
}
