/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 01:46:25 by shunt             #+#    #+#             */
/*   Updated: 2019/06/07 01:46:27 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_fld(long double f)
{
    t_flts  l;
    int     sign;
    char    *res;
    char    *in;
    char    *fr;
    int     e;

    l.u = f;
    if (!(res = mantis(l)))
        return (NULL);
    sign = (l.y[4] & 0x8000) ? 1 : 0;
    e = mexp(l);
    if (e == 16384)
        return (fld_edge(&res, sign));
    if (!(in = int_p(e + 1, res)))
        return (NULL);
    if (!(fr = fr_p(e, res)))
        return (NULL);
    free(res);
    res = (e < 63) ? res_w_fr(e, in, fr, sign) : res_o_fr(in, fr, sign);
    free(in);
    free(fr);
    return (res ? res : NULL);
}