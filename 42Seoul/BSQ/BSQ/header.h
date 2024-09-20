/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:17:55 by djo               #+#    #+#             */
/*   Updated: 2021/03/16 18:25:27 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

//# include <unistd.h>
#include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

extern	char	g_obs;
extern	char	g_emp;
extern	char	g_ful;
extern	int		g_height;
extern	int		g_width;

void			calc(int **map);
int				str_to_map(char *file);

#endif
