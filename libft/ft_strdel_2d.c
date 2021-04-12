/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 20:01:57 by smorel            #+#    #+#             */
/*   Updated: 2021/04/12 11:46:50 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	**ft_strdel_2d(char **t, int size, int print)
{
	int	i;
	char	c;

	i = -1;
	c = '\n';
	while (++i < size)
	{
		if (print)
		{
			write(1, t[i], size);
			write(1, &c, 1);
		}
		free(t[i]);
		t[i] = NULL;
	}
	free(t);
	return (NULL);
}
