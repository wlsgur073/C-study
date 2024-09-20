/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 14:16:35 by jupark            #+#    #+#             */
/*   Updated: 2021/03/14 22:13:03 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void		strings_distribute(char **string_array, char *input, int mod)
{
	int		digit_of_string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	digit_of_string = 1;
	while (input[j])
	{
		string_array[i][digit_of_string - 1] = input[j];
		if ((j + 1) % 3 == mod)
		{
			string_array[i][digit_of_string] = 0;
			i++;
			digit_of_string = 1;
		}
		else
			digit_of_string++;
		j++;
	}
}

char		**ft_seperate(char *input, int cnt)
{
	char	**string_array;
	int		hmt;
	int		i;

	i = 0;
	hmt = cnt / 3 + 1;
	if (cnt % 3 == 0)
		hmt = cnt / 3;
	g_nbr_sep_size = hmt + 1;
	string_array = (char**)malloc(sizeof(char*) * hmt + 1);
	while (i < hmt)
	{
		string_array[i] = (char*)malloc(sizeof(char) * (3 + 1));
		i++;
	}
	string_array[i] = 0;
	strings_distribute(string_array, input, cnt % 3);
	return (string_array);
}

void		free_string_array(char **string_array, int cnt)
{
	int		hmt;
	int		i;

	i = 0;
	hmt = cnt / 3 + 1;
	if (cnt % 3 == 0)
		hmt = cnt / 3;
	while (i < hmt)
	{
		free(string_array[i]);
		i++;
	}
	free(string_array);
}
