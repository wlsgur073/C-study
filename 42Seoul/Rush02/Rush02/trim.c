/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 09:42:18 by jupark            #+#    #+#             */
/*   Updated: 2021/03/14 22:11:31 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char		*ft_go_before_end(char *begin, char *end)
{
	while (begin <= end)
		begin++;
	*begin = 0;
	return (begin);
}

char		*trim_left(char *str)
{
	char	*begin;

	if (!*str)
		return (0);
	begin = str;
	while (ft_isspace(*begin))
		++begin;
	return (begin);
}

char		*trim_right(char *str)
{
	char	*end;

	if (!*str)
		return (0);
	end = str;
	while (*end)
		end++;
	--end;
	while (ft_isspace(*end))
		--end;
	ft_go_before_end(str, end);
	return (str);
}

char		*trim_side(char *str)
{
	char	*begin;
	char	*end;

	if (!*str)
		return (0);
	begin = str;
	while (ft_isspace(*begin))
		++begin;
	end = begin;
	while (*end)
		++end;
	--end;
	while (ft_isspace(*end))
		--end;
	ft_go_before_end(begin, end);
	return (begin);
}
