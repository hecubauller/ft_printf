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
	(*read)->mod = NULL;
	(*read)->mod2 = NULL;
	if (format[(*read)->smb_cnt] == 'o')
	{
		(*read)->mod_smb = 'o';
		if ((*read)->size == 0)
			(*read)->mod = ft_ox(va_arg(**ap, unsigned int), 8, 1);
		else if ((*read)->size == 1)
			(*read)->mod = ft_ox(va_arg(**ap, unsigned long), 8, 1);
		else if ((*read)->size == 2)
			(*read)->mod = ft_ox(va_arg(**ap, unsigned long long), 8, 1);
		else if ((*read)->size == 4)
			(*read)->mod = ft_ox((unsigned short)va_arg(**ap, unsigned int), 8, 1);
		else if ((*read)->size == 8)
			(*read)->mod = ft_ox((unsigned char)va_arg(**ap, unsigned int), 8, 1);
		else if ((*read)->size == 16)
			(*read)->mod = ft_ox(va_arg(**ap, uintmax_t), 8, 1);
		else if ((*read)->size == 32 || (*read)->size == 64)
			(*read)->mod = ft_ox(va_arg(**ap, size_t), 8, 1);
		else if ((*read)->size == 128)
			(*read)->mod = ft_ox(va_arg(**ap, u_int64_t), 8, 1);
	}
	else if (format[(*read)->smb_cnt] == 'b')
	{
		(*read)->mod_smb = 'b';
		if ((*read)->size == 0)
			(*read)->mod = ft_ox(va_arg(**ap, unsigned int), 2, 1);
		else if ((*read)->size == 1)
			(*read)->mod = ft_ox(va_arg(**ap, unsigned long), 2, 1);
		else if ((*read)->size == 2)
			(*read)->mod = ft_ox(va_arg(**ap, unsigned long long), 2, 1);
		else if ((*read)->size == 4)
			(*read)->mod = ft_ox((unsigned short)va_arg(**ap, unsigned int), 2, 1);
		else if ((*read)->size == 8)
			(*read)->mod = ft_ox((unsigned char)va_arg(**ap, unsigned int), 2, 1);
		else if ((*read)->size == 16)
			(*read)->mod = ft_ox(va_arg(**ap, uintmax_t), 2, 1);
		else if ((*read)->size == 32 || (*read)->size == 64)
			(*read)->mod = ft_ox(va_arg(**ap, size_t), 2, 1);
		else if ((*read)->size == 128)
			(*read)->mod = ft_ox(va_arg(**ap, u_int64_t), 2, 1);
	}
	else if (format[(*read)->smb_cnt] == 'x')
	{
		(*read)->mod_smb = 'x';
		if ((*read)->size == 0)
			(*read)->mod = ft_ox(va_arg(**ap, unsigned int), 16, 1);
		else if ((*read)->size == 1)
			(*read)->mod = ft_ox(va_arg(**ap, unsigned long), 16, 1);
		else if ((*read)->size == 2)
			(*read)->mod = ft_ox(va_arg(**ap, unsigned long long), 16, 1);
		else if ((*read)->size == 4)
			(*read)->mod = ft_ox((unsigned short)va_arg(**ap, unsigned int), 16, 1);
		else if ((*read)->size == 8)
			(*read)->mod = ft_ox((unsigned char)va_arg(**ap, unsigned int), 16, 1);
		else if ((*read)->size == 16)
			(*read)->mod = ft_ox(va_arg(**ap, uintmax_t), 16, 1);
		else if ((*read)->size == 32 || (*read)->size == 64)
			(*read)->mod = ft_ox(va_arg(**ap, size_t), 16, 1);
		else if ((*read)->size == 128)
			(*read)->mod = ft_ox(va_arg(**ap, u_int64_t), 16, 1);
	}
	else if (format[(*read)->smb_cnt] == 'X')
	{
		(*read)->mod_smb = 'X';
		if ((*read)->size == 0)
			(*read)->mod = ft_ox(va_arg(**ap, unsigned int), 16, 0);
		else if ((*read)->size == 1)
			(*read)->mod = ft_ox(va_arg(**ap, unsigned long), 16, 0);
		else if ((*read)->size == 2)
			(*read)->mod = ft_ox(va_arg(**ap, unsigned long long), 16, 0);
		else if ((*read)->size == 4)
			(*read)->mod = ft_ox((unsigned short)va_arg(**ap, unsigned int), 16, 0);
		else if ((*read)->size == 8)
			(*read)->mod = ft_ox((unsigned char)va_arg(**ap, unsigned int), 16, 0);
		else if ((*read)->size == 16)
			(*read)->mod = ft_ox(va_arg(**ap, uintmax_t), 16, 0);
		else if ((*read)->size == 32 || (*read)->size == 64)
			(*read)->mod = ft_ox(va_arg(**ap, size_t), 16, 0);
		else if ((*read)->size == 128)
			(*read)->mod = ft_ox(va_arg(**ap, u_int64_t), 16, 0);
	}
	else if (format[(*read)->smb_cnt] == 'c')
	{
		(*read)->mod_smb = 'c';
		if ((*read)->size == 1)
			(*read)->mod = ft_c(va_arg(**ap, wchar_t));
		else
			(*read)->mod = ft_c(va_arg(**ap, int));
	}
	else if (format[(*read)->smb_cnt] == 's' || format[(*read)->smb_cnt] == 'r')
	{
		(*read)->mod_smb = format[(*read)->smb_cnt] == 's' ? 's' : 'r';
		if ((*read)->size == 1 || format[(*read)->smb_cnt] == 'r')
			(*read)->mod2 = (va_arg(**ap, wchar_t *));
		else
			(*read)->mod = (va_arg(**ap, char *));
	}
	else if (format[(*read)->smb_cnt] == 'd' || format[(*read)->smb_cnt] == 'i')
	{
		(*read)->mod_smb = format[(*read)->smb_cnt] == 'd' ? 'd' : 'i';
		if ((*read)->size == 0)
			(*read)->mod = ft_d(va_arg(**ap, int));
		else if ((*read)->size == 1)
			(*read)->mod = ft_d(va_arg(**ap, long));
		else if ((*read)->size == 2)
			(*read)->mod = ft_d(va_arg(**ap, long long));
		else if ((*read)->size == 4)
			(*read)->mod = ft_d((short)va_arg(**ap, int));
		else if ((*read)->size == 8)
			(*read)->mod = ft_d((char)va_arg(**ap, int));
		else if ((*read)->size == 16)
			(*read)->mod = ft_d(va_arg(**ap, uintmax_t));
		else if ((*read)->size == 32 || (*read)->size == 64)
			(*read)->mod = ft_d(va_arg(**ap, ssize_t));
		else if ((*read)->size == 128)
			(*read)->mod = ft_d(va_arg(**ap, u_int64_t));
	}
	else if (format[(*read)->smb_cnt] == 'f')
	{
		(*read)->mod_smb = 'f';
		if ((*read)->size == 128)
			(*read)->mod = ft_round(ft_fld(va_arg(**ap, long double), 1), (*read)->prs);
		else
			(*read)->mod = ft_round(ft_fld(va_arg(**ap, double), 1), (*read)->prs);
	}
	else if (format[(*read)->smb_cnt] == 'F')
	{
		(*read)->mod_smb = 'F';
		if ((*read)->size == 128)
			(*read)->mod = ft_round(ft_fld(va_arg(**ap, long double), 0), (*read)->prs);
		else
			(*read)->mod = ft_round(ft_fld(va_arg(**ap, double), 0), (*read)->prs);
	}
	else if (format[(*read)->smb_cnt] == 'e')
	{
		(*read)->mod_smb = 'e';
		if ((*read)->size == 128)
			(*read)->mod = ft_round(ft_e(va_arg(**ap, long double), 1), (*read)->prs);
		else
			(*read)->mod = ft_round(ft_e(va_arg(**ap, double), 1), (*read)->prs);
	}
	else if (format[(*read)->smb_cnt] == 'E')
	{
		(*read)->mod_smb = 'E';
		if ((*read)->size == 128)
			(*read)->mod = ft_round(ft_e(va_arg(**ap, long double), 0), (*read)->prs);
		else
			(*read)->mod = ft_round(ft_e(va_arg(**ap, double), 0), (*read)->prs);
	}
	else if (format[(*read)->smb_cnt] == 'g')
	{
		(*read)->mod_smb = 'g';
		if ((*read)->size == 128)
			(*read)->mod = ft_g(va_arg(**ap, long double), 1, (*read)->prs);
		else
			(*read)->mod = ft_g(va_arg(**ap, double), 1, (*read)->prs);
	}
	else if (format[(*read)->smb_cnt] == 'G')
	{
		(*read)->mod_smb = 'G';
		if ((*read)->size == 128)
			(*read)->mod = ft_g(va_arg(**ap, long double), 0, (*read)->prs);
		else
			(*read)->mod = ft_g(va_arg(**ap, double), 0, (*read)->prs);
	}
	else if (format[(*read)->smb_cnt] == 'p')
	{
		(*read)->mod_smb = 'p';
		(*read)->mod = ft_p(va_arg(**ap, unsigned long long));
	}
}

void    ft_chck_size(t_rd **read, const char *format, va_list **ap)
{
    int     r;

    (*read)->size = 0;
	if (format[(*read)->smb_cnt + 1])
	{
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
}

void    ft_chck_precision(t_rd **read, const char *format)
{
    int     r;

    (*read)->prs = 6;
	(*read)->kostil = 0;
	if (format[(*read)->smb_cnt + 1])
	{
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
			if (r == 6)
				(*read)->kostil = 1;
			(*read)->prs = r;
		}
	}
}

void    ft_chck_wdth(t_rd **read, const char *format, va_list **ap)
{
    int     r;

    (*read)->width = 0;
	if (format[(*read)->smb_cnt + 1])
	{
		if (format[(*read)->smb_cnt] == '*')
			(*read)->width = va_arg(**ap, int);
		r = 0;
		if (format[(*read)->smb_cnt - 1] == '#')
			(*read)->smb_cnt++;
		while (format[(*read)->smb_cnt] != '.' &&
		       (format[(*read)->smb_cnt] >= '0'
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
}

int    ft_chck_flags(t_rd **read, const char *format)
{
    (*read)->flag = 0;
    if (format[(*read)->smb_cnt + 1] != '\0')
    {
	    if ((*read)->smb_cnt < (*read)->strlen)
	    {
		    while ((format[++(*read)->smb_cnt] == '-' ||
		            format[(*read)->smb_cnt] == '+' ||
		            format[(*read)->smb_cnt] == ' ' ||
		            format[(*read)->smb_cnt] == '0'));
		    if (format[(*read)->smb_cnt - 1] == '+')
			    (*read)->flag |= F_PLUS;
		    else if (format[(*read)->smb_cnt - 1] == '-')
			    (*read)->flag |= F_MINUS;
		    else if (format[(*read)->smb_cnt - 1] == ' ')
			    (*read)->flag |= F_SPACE;
		    else if (format[(*read)->smb_cnt - 1] == '0')
			    (*read)->flag |= F_ZERO;
		    else if (format[(*read)->smb_cnt] == '#')
			    (*read)->flag |= F_OCT;
	    }
    }
}
