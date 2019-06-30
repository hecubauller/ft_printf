/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:43:29 by shunt             #+#    #+#             */
/*   Updated: 2019/04/14 16:03:38 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_or(unsigned int a)
{
	int n;

	n = 1;
	while (a >= 2)
	{
		a /= 2;
		n++;
	}
	return (n);
}

char		*ft_bin(unsigned int a)
{
	char	*s;
	int		n;

	n = ft_or(a);
	s = (char *)malloc(sizeof(char) * (n + 1));
	if (s)
	{
		s[n] = '\0';
		while (--n >= 0)
		{
			s[n] = (a % 2) + '0';
			a /= 2;
		}
	}
	return (s);
}
