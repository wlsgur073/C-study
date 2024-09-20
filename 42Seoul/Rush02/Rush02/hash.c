/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:00:59 by jupark            #+#    #+#             */
/*   Updated: 2021/03/14 22:22:50 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int				makehash(int val, int hashsize)
{
	return (val % hashsize);
}

t_hashtable		*createhash(int hashsize)
{
	t_hashtable	*htable;

	htable = (t_hashtable*)malloc(sizeof(t_hashtable));
	htable->node = (t_node*)malloc(sizeof(t_node) * hashsize);
	htable->hashsize = hashsize;
	return (htable);
}

void			sethash(t_hashtable *htable, int val, char *key, char *value)
{
	int		addr;
	int		initaddr;

	addr = makehash(val, htable->hashsize);
	initaddr = -1;
	while (initaddr != addr)
	{
		if (initaddr == -1)
			initaddr = addr; // initaddr = 101;
		if (htable->node[addr].address == 0
				&& htable->node[addr].address != addr)
			break ;
		addr = makehash(++val, htable->hashsize);
	}
	htable->node[addr].address = addr;
	htable->node[addr].key = key;
	htable->node[addr].value = value;
}

t_node			*gethash(t_hashtable *htable, int val, char *key)
{
	int		addr;
	int		initaddr;

	addr = makehash(val, htable->hashsize); // 이미 val가 hash된 값인데 또 하는 이유는?
	initaddr = -1;
	while (initaddr != addr)
	{
		if (initaddr == -1)
			initaddr = addr;
		if (htable->node[addr].address == addr
				&& ft_cmp(htable->node[addr].key, key))
			break ;
		addr = makehash(++val, htable->hashsize);
	}
	return (&htable->node[addr]);
}
