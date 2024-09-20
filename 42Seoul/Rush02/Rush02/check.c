/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 09:26:55 by jupark            #+#    #+#             */
/*   Updated: 2021/03/14 22:58:08 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		ft_is_valid(char *value)
{
	int i;
	int	zerocnt;

	if (!*value)
		return (-1);
	i = 0;
	zerocnt = 0;
	if (value[0] == '0' && value[1] != 0)
		while (value[i] && value[i] == '0')
		{
			i++;
			zerocnt++;
		}
	i = -1;
	while (value[++i])
		if (value[i] < '0' || value[i] > '9')
			return (-1);
	return (zerocnt);
}

void	ft_check_argu(int argc, char **argv, char **file, char **value)
{
	if (argc < 2 || argc > 3)
	{
		*file = NULL;
		*value = NULL;
	}
	if (argc == 2)
	{
		*file = "numbers.dict";
		*value = argv[1];
	}
	else
	{
		*file = argv[1];
		*value = argv[2];
	}
}
