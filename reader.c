/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:24:05 by huller            #+#    #+#             */
/*   Updated: 2019/06/18 17:24:07 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_chck_mod(t_rd **read, const char *restrict format, va_list **ap)
{
    if (format[++(*read)->smb_cnt] == 'o')
    {
        (*read)->mod_smb = 'o';
        if ((*read)->size == 0)
            (*read)->mod = ft_ox(va_arg(**ap, unsigned int), 1, 1);
        if ((*read)->size == 8)
            (*read)->mod = ft_ox(va_arg(**ap, unsigned char), 1, 1);
        if ((*read)->size == 4)
            (*read)->mod = ft_ox(va_arg(**ap, unsigned short int), 1, 1);
        if ((*read)->size == 1)
            (*read)->mod = ft_ox(va_arg(**ap, unsigned int), 1, 1);
        if ((*read)->size == 2)
            (*read)->mod = ft_ox(va_arg(**ap, unsigned int), 1, 1);
    }
    if (format[(*read)->smb_cnt] == 'x')
        (*read)->mod = ft_ox(va_arg(**ap, unsigned int), 0, 1);
    if (format[(*read)->smb_cnt] == 'X')
        (*read)->mod = ft_ox(va_arg(**ap, unsigned int), 0, 0);
    else if (format[(*read)->smb_cnt] == 'c')
        (*read)->mod = ft_c(va_arg(**ap, int));
    else if (format[(*read)->smb_cnt] == 's')
        (*read)->mod = (va_arg(**ap, char *));
    else if (format[(*read)->smb_cnt] == 'd' || format[(*read)->smb_cnt] == 'i')
        (*read)->mod = ft_d(va_arg(**ap, int));
    else if (format[(*read)->smb_cnt] == 'f' || format[(*read)->smb_cnt] == 'F')
        (*read)->mod = ft_fld(va_arg(**ap, long double));
    else if (format[(*read)->smb_cnt] == 'e')
        (*read)->mod = ft_e(va_arg(**ap, long double), 1);
    else if (format[(*read)->smb_cnt] == 'E')
        (*read)->mod = ft_e(va_arg(**ap, long double), 0);
    else if (format[(*read)->smb_cnt] == 'g')
        (*read)->mod = ft_g(va_arg(**ap, long double), 1, (*read)->width);
    else if (format[(*read)->smb_cnt] == 'G')
        (*read)->mod = ft_g(va_arg(**ap, long double), 0, (*read)->width);
    else if (format[(*read)->smb_cnt] == 'p')
        (*read)->mod = ft_p(va_arg(**ap, unsigned long long));
    //создать отмену всех флагов и вывод only строки
}

void    ft_chck_size(t_rd **read, const char *restrict format, va_list **ap)
{
    int     r;

    (*read)->size = 0;
    r = 0;
    if (format[(*read)->smb_cnt] == '*')
        (*read)->size = va_arg(**ap, int);
    else if (format[(*read)->smb_cnt] == 'l')
        (*read)->size |= LONG_INT;
    else if (format[(*read)->smb_cnt] == 'l' &&
        format[(*read)->smb_cnt + 1] == 'l')
        (*read)->size |= LONG_LONG_INT;
    else if (format[(*read)->smb_cnt] == 'h')
        (*read)->size |= SHORT_INT;
    else if (format[(*read)->smb_cnt] == 'h' &&
        format[(*read)->smb_cnt + 1] == 'h')
        (*read)->size |= SIGNED_CHAR;
    else if (format[(*read)->smb_cnt] == 'j')
        (*read)->size |= INT_MAX;
    else if (format[(*read)->smb_cnt] == 'z')
        (*read)->size |= SIZE_T;
    else if (format[(*read)->smb_cnt] == 't')
        (*read)->size |= PTRDIFF_T;
    else if (format[(*read)->smb_cnt] == 'L')
        (*read)->size |= INT_64;
}

void    ft_chck_precision(t_rd **read, const char *restrict format)
{
    int     r;

    (*read)->prs = 0;
    r = 0;
    if (format[(*read)->smb_cnt] == '.')
    {
        while (format[++(*read)->smb_cnt] >= '0' &&
            format[(*read)->smb_cnt] <= '9')
        {
            r += format[(*read)->smb_cnt] - '0';
            if (format[(*read)->smb_cnt + 1] >= '0'
                && format[(*read)->smb_cnt + 1] <= '9')
                r *= 10;
        }
        (*read)->prs = r;
    }
}

void    ft_chck_wdth(t_rd **read, const char *restrict format, va_list **ap)
{
    int     r;

    (*read)->width = 0;
    if (format[(*read)->smb_cnt] == '*')
        (*read)->width = va_arg(**ap, int);
    r = 0;
    if (format[(*read)->smb_cnt - 1] == '#')
        (*read)->smb_cnt++;
    while (format[(*read)->smb_cnt] != '.' && (format[(*read)->smb_cnt] >= '0'
        && format[(*read)->smb_cnt] <= '9'))
    {
        r += format[(*read)->smb_cnt] - '0';
        if (format[(*read)->smb_cnt + 1] >= '0'
            && format[(*read)->smb_cnt + 1] <= '9')
            r *= 10;
        (*read)->smb_cnt++;
        }
        (*read)->width = r;
}

void    ft_chck_flags(t_rd **read, const char *restrict format)
{
    (*read)->flag = 0;
    (*read)->smb_cnt = 0;
    while ((format[++(*read)->smb_cnt] == '-' ||
        format[(*read)->smb_cnt] == '+' ||
        format[(*read)->smb_cnt] == ' ' ||
        format[(*read)->smb_cnt] == '0'))
        ;
    if (format[(*read)->smb_cnt - 1] == '+')
        (*read)->flag |= F_PLUS;
    if (format[(*read)->smb_cnt - 1] == '-')
        (*read)->flag |= F_MINUS;
    if (format[(*read)->smb_cnt - 1] == ' ')
        (*read)->flag |= F_SPACE;
    if (format[(*read)->smb_cnt - 1] == '0')
        (*read)->flag |= F_ZERO;
    if (format[(*read)->smb_cnt] == '#')
        (*read)->flag |= F_OCT;
}
