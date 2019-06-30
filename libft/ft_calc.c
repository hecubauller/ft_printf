/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 14:08:10 by shunt             #+#    #+#             */
/*   Updated: 2019/04/14 15:54:36 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_h(int i, int j, char b)
{
	if (b == '/')
	{
		if (j != 0)
			ft_putnbr(i / j);
		else if (j == 0)
			write(1, "division by zero\n", 17);
	}
	else if (b == '%')
	{
		if (j != 0)
			ft_putnbr(i % j);
		else if (j == 0)
			write(1, "modulo by zero\n", 15);
	}
}

void		ft_calc(char *a, char b, char *c)
{
	int		i[2];

	if (ft_isnum(a) && ft_isnum(c))
	{
		i[0] = ft_atoi(a);
		i[1] = ft_atoi(c);
		if (b == '-')
		{
			ft_putnbr(i[0] - i[1]);
			return ;
		}
		else if (b == '+')
		{
			ft_putnbr(i[0] + i[1]);
			return ;
		}
		else if (b == '*')
		{
			ft_putnbr(i[0] * i[1]);
			return ;
		}
		(b == '/' || b == '%') ? ft_h(i[0], i[1], b) :
			write(1, "invalid operator\n", 17);
	}
}
