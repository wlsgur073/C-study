/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 10:34:09 by jupark            #+#    #+#             */
/*   Updated: 2021/03/14 22:13:44 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void		print_size_three(char *nbr, char *tmp)
{
	if (nbr[0] == '0')
		return ;
	tmp[0] = nbr[0];
	tmp[1] = 0;
	print_value(tmp);
	print_value("100");
}

int			print_size_two(char *nbr, char *tmp, int cur)
{
	int nextcheck;

	nextcheck = 1;
	tmp[0] = nbr[cur];
	tmp[2] = 0;
	if (nbr[cur] > '1')
		tmp[1] = '0';
	else if (nbr[cur] != '0')
	{
		nextcheck = 0;
		tmp[1] = nbr[cur + 1];
	}
	else if (nbr[cur] == '0' && nbr[cur + 1] != '0')
		return (1);
	else if (nbr[cur] == '0' && nbr[cur + 1] == '0')
		return (0);
	print_value(tmp);
	return (nextcheck);
}

void		print_size_one(char *nbr, char *tmp, int cur)
{
	if (cur > 0 && nbr[cur - 1] > '1')
	{
		if (nbr[cur] != '0')
		{
			tmp[0] = nbr[cur];
			tmp[1] = 0;
			print_value(tmp);
		}
	}
	else
	{
		tmp[0] = nbr[cur];
		tmp[1] = 0;
		print_value(tmp);
	}
}

void		print_by_size(char *nbr, int size)
{
	char	*tmp;

	tmp = (char*)malloc(sizeof(char) * 3);
	if (size == 3)
	{
		print_size_three(nbr, tmp);
		if (print_size_two(nbr, tmp, 1))
			print_size_one(nbr, tmp, 2);
	}
	else if (size == 2)
	{
		if (print_size_two(nbr, tmp, 0))
			print_size_one(nbr, tmp, 1);
	}
	else if (size == 1)
		print_size_one(nbr, tmp, 0);
	free(tmp);
}

void		print_nbr_by_value(char *nbr, int cur)
{
	int		size;
	int		addr;
	char	*tmpstr;

	size = ft_getlen(nbr);
	print_by_size(nbr, size);
	if (cur > 0)
	{
		if ((nbr[0] == '0' && nbr[1] == '0' && nbr[2] == '0'))
			return ;
		addr = makehash(ft_getunit_val(cur), g_dict->hashsize);
		write(1, " ", 1);
		tmpstr = ft_getunit_str(cur);
		ft_putstr(gethash(g_dict, addr, tmpstr)->value);
		free(tmpstr);
	}
}
