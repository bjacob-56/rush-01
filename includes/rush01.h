/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:15:27 by smorel            #+#    #+#             */
/*   Updated: 2021/04/12 11:08:21 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_rush;
{
	int	size;
	char	c;
	char **map_origin;
	char **map_modif;
	int	max;
	int	i_max;	// line
	int	j_max;	// column
} t_rush;


int		get_next_line(int fd, char **line);
int		glen(char *str, char c);
void	gnl_free(char **str);

#endif
