/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_o_fr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:11:15 by shunt             #+#    #+#             */
/*   Updated: 2019/06/14 14:11:17 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *res_o_fr(char *in, char *fr, int sign)
{
    char    *res;
    int     i;
    int     j;

    i = 0;
    while (in[i] == '0')
        ++i;
    res = (sign) ? (char *)malloc(sizeof(char) * (5003 - i)) : (char *)malloc(sizeof(char) * (5002 - i));
    res[5001 - i] = '\0';
    j = -1;
    if (sign)
        res[++j] = '-';
    while (in[i])
        res[++j] = in[i++];
    res[++j] = '.';
    return (res);
}