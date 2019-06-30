/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ox.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 01:37:04 by shunt             #+#    #+#             */
/*   Updated: 2019/06/04 01:37:20 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_ox(unsigned int o, int a, int b)
{
    char    *s;

    if (a)
        if (!(s = ft_itoa_base(o, 8, 1)))
            return (NULL);
    else
        if (!(s = b ? ft_itoa_base(o, 16, 1) : ft_itoa_base(o, 16, 0)))
            return (NULL);
    return (s);
}