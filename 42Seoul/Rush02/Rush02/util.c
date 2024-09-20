/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:48:02 by jupark            #+#    #+#             */
/*   Updated: 2021/03/14 22:14:29 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int			ft_getlen(char *str)
{
	int		cur;

	cur = 0;
	while (str[cur])
		cur++;
	return (cur);
}

void		ft_putstr(char *str)
{
	write(1, str, ft_getlen(str));
}

int			ft_cmp(char *a, char *b)
{
	if (a == NULL || b == NULL)
		return (0);
	while (*a && *b)
	{
		if (*a != *b)
			return (0);
		a++;
		b++;
	}
	return (1);
}

void		ft_strcpy(char *dest, char *b, char *e)
{
	while (b <= e)
		*(dest++) = *(b++);
	*dest = 0;
}

int			ft_isspace(char c)
{
	return (c == ' ' || ('\t' <= c && c <= '\r'));
}
