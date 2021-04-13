/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:15:27 by smorel            #+#    #+#             */
/*   Updated: 2021/04/13 07:54:20 by bjacob           ###   ########lyon.fr   */
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

int				get_next_line(char **line);
int				glen(char *str, char c);
void			gnl_free(char **str);

long long int	ft_atoi(const char *nptr);
int				ft_atoi_read(void);

void			*ft_memalloc(size_t size);
char			*ft_strdup(const char *s1);
char			*ft_strncpy(char *dst, const char *src, size_t len);
size_t			ft_strlen(const char *s);

char			**ft_strdel_2d_char(char **t, int size, int print);

void			algo(t_rush *rush);

#endif
