/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:47:28 by jupark            #+#    #+#             */
/*   Updated: 2021/03/14 22:54:04 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void		rush(int argc, char *value, int skipedzero)
{
	int		cur;
	char	**nbr_sep;

	cur = -1;
	if (ft_getlen(value + skipedzero) > 39)
	{
		ft_putstr(ARG_LEN_ERROR);
		return ;
	}
	nbr_sep = ft_seperate(value + skipedzero, ft_getlen(value + skipedzero));
	if (argc == 1)
		ft_putstr(ARG_NUM_S_ERROR);
	else if (argc == 2)
	{
		while (++cur < g_nbr_sep_size - 1)
			print_nbr_by_value(nbr_sep[cur], g_nbr_sep_size - cur - 2);
	}
	else if (argc == 3)
	{
		while (++cur < g_nbr_sep_size - 1)
			print_nbr_by_value(nbr_sep[cur], g_nbr_sep_size - cur - 2);
	}
	else
		ft_putstr(ARG_NUM_L_ERROR);
	free_string_array(nbr_sep, ft_getlen(value + skipedzero));
}

int			main(int argc, char *argv[])
{
	char	*value;
	char	*file;
	int		skipedzero;
	int		errorcode;

	g_dict = createhash(HASH_SIZE);
	g_flag = 0;
	ft_check_argu(argc, argv, &file, &value);
	if ((skipedzero = ft_is_valid(value)) < 0)
	{
		ft_putstr(ARG_FORM_ERROR);
		return (0);
	}
	if ((errorcode = create_dictionary_hash(file)) < 0)
	{
		if (errorcode == -1)
			ft_putstr(DICT_CANT_OPEN_ERROR);
		else
			ft_putstr(DICT_CANT_PARSE_ERROR);
		return (0);
	}
	rush(argc, value, skipedzero);
	return (0);
}
