/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:15:27 by smorel            #+#    #+#             */
/*   Updated: 2021/04/12 11:47:28 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_rush
{
	int		size;
	char	c;
	char	**map_origin;
	char	**map_modif;
	int		max;
	int		i_max;	// line
	int		j_max;	// column
}	t_rush;

int				get_next_line(int fd, char **line);
int				glen(char *str, char c);
void			gnl_free(char **str);
long long int	ft_atoi(const char *nptr);
void			*ft_memalloc(size_t size);
char			*ft_strdup(const char *s1);
char			*ft_strncpy(char *dst, const char *src, size_t len);
size_t			ft_strlen(const char *s);
int				pars(t_rush *r);

char			**ft_strdel_2d(char **t, int size, int print);

void			algo(t_rush *rush);

#endif
