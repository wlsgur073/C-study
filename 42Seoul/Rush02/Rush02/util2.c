/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 09:22:44 by jupark            #+#    #+#             */
/*   Updated: 2021/03/14 22:12:19 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void		print_value(char *str)
{
	int		addr;

	if (g_flag)
		write(1, " ", 1);
	if (!g_flag)
		g_flag++;
	addr = makehash(ft_atov(str), g_dict->hashsize);
	ft_putstr(gethash(g_dict, addr, str)->value);
}

int			ft_atov(char *key)
{
	int cal;
	int cur;

	cal = 0;
	cur = -1;
	while (key[++cur])
		cal += (int)key[cur];
	return (cal);
}

int			ft_atoi(char *nbr)
{
	int cal;
	int cur;

	cal = 0;
	cur = -1;
	while (nbr[++cur])
	{
		cal *= 10;
		cal += nbr[cur] - '0';
	}
	return (cal);
}

int			ft_getunit_val(int cur)
{
	int cal;

	cal = 49;
	cur *= 3;
	while (cur--)
		cal += 48;
	return (cal);
}

char		*ft_getunit_str(int cur)
{
	char	*str;
	int		i;

	cur *= 3;
	str = (char*)malloc(sizeof(char) * (cur + 2));
	str[0] = '1';
	i = 0;
	while (++i < cur + 1)
		str[i] = '0';
	str[i] = 0;
	return (str);
}
