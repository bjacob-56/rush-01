/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:15:27 by smorel            #+#    #+#             */
/*   Updated: 2021/04/13 15:45:16 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_max
{
	int		i;
	int		j;
	int		max;
}	t_max;

int				get_next_line(char **line, int len);
char			**ft_strdel_2d_char(char **t, int size);
int				**ft_strdel_2d_int(int **t, int size);
void			algo(char **map_o, int **map_m, char c, int size);

#endif
