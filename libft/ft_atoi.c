/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:45:41 by shunt             #+#    #+#             */
/*   Updated: 2019/04/16 16:04:48 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_r(char *str, int i, int f)
{
	long int	r;

	r = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (r <= 922337203685477580)
			r *= 10;
		else if (f)
			return (0);
		else if (!f)
			return (-1);
		if (r < 9223372036854775800 || (f && r == 9223372036854775800
					&& str[i] - '0' < 8) || (!f && r == 9223372036854775800
						&& str[i] - '0' < 7))
			r += str[i] - '0';
		else if (f && str[i] - '0' >= 8)
			return (0);
		else if (!f && str[i] - '0' >= 7)
			return (-1);
		i++;
	}
	return (r);
}

int				ft_atoi(const char *str)
{
	int			i;
	int			f;
	long int	r;

	i = 0;
	f = 0;
	r = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\r' ||
			str[i] == '\t' || str[i] == '\v' || str[i] == '\f')
		i++;
	(str[i] == '-') ? f++ : f;
	(str[i] == '-' || str[i] == '+') ? i++ : i;
	if (str[i] >= '0' && str[i] <= '9')
		r = ft_r((char *)str, i, f);
	if (r < 0)
		return (r);
	return (f ? -r : r);
}
