/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:15:27 by smorel            #+#    #+#             */
/*   Updated: 2021/04/13 10:50:11 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_rush
{
	int		size;
	char	c;
	char	**map_origin;
	int		**map_modif;
	int		max;
	int		i_max;
	int		j_max;
}	t_rush;

int				get_next_line(char **line, int len);
char			**ft_strdel_2d_char(char **t, int size);
int				**ft_strdel_2d_int(int **t, int size);
void			algo(t_rush *rush);

#endif
