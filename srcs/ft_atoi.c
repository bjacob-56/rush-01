/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 20:01:57 by smorel            #+#    #+#             */
/*   Updated: 2021/04/12 19:15:32 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

long long int	ft_atoi(const char *nptr)
{
	long long int	val;
	int				signe;

	signe = 1;
	val = 0;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\f' || *nptr == '\n' \
		 || *nptr == '\r' || *nptr == '\v')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			signe = -signe;
		nptr++;
	}
	while ('0' <= *nptr && *nptr <= '9')
		val = 10 * val + (*nptr++ - '0');
	return (signe * val);
}


int	ft_atoi_read(void)
{
	int	val;
	char buf[2];

	val = 0;
	buf[0] = '0';
	while (buf[0] != '\n')
	{
		val = 10 * val + (buf[0] - '0');
		read(0, buf, 1);
	}
	return (val);
}
