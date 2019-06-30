/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 12:33:32 by shunt             #+#    #+#             */
/*   Updated: 2019/04/12 19:35:36 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_order(int n)
{
	int a;

	a = 1;
	if (n > 0)
		while (n >= 10)
		{
			n /= 10;
			a++;
		}
	if (n < 0)
		while (n <= -10)
		{
			n /= 10;
			a++;
		}
	return (a);
}

static void	ft_d(char *r, int *n, int a)
{
	int b;

	b = *n;
	r[a] = (b % 10) + 48;
	*n = b / 10;
}

char		*ft_itoa(int n)
{
	char	*r;
	int		a;

	a = ft_order(n);
	(n < 0 ? a++ : a);
	r = (char *)malloc(sizeof(char) * (a + 1));
	if (r)
	{
		(n == -2147483648 ? a-- : a);
		r[a] = (n == -2147483648) ? '8' : '\0';
		n = (n == -2147483648) ? n / 10 : n;
		if (n < 0)
		{
			n = -n;
			r[0] = '-';
			while (--a >= 1)
				ft_d(r, &n, a);
		}
		else
			while (--a >= 0)
				ft_d(r, &n, a);
		return (r);
	}
	return (NULL);
}
