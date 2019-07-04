/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 11:19:18 by shunt             #+#    #+#             */
/*   Updated: 2019/06/02 11:19:44 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_pt_frst(const char *format, t_out *output, t_rd **rd)
{
	char	*res;
	char	*tmp2;
	int		tmp;
	int		i;
	int		b;

	i = 0;
	b = -1;
	tmp = (*rd)->smb_cnt;
	while (format[(*rd)->smb_cnt] && format[(*rd)->smb_cnt] != '%')
	{
		(*rd)->smb_cnt++;
		i++;
	}
	if (!(res = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	res[i] = '\0';
	tmp--;
	while (++b < i)
		res[b] = format[++tmp];
	tmp2 = (*output).buf;
	if (!(*output).buf)
		(*output).buf = ft_strnew(0);
	else
		(*output).buf = ft_strjoin((*output).buf, res);
	free((void *)res);
	tmp2 ? free((void *)tmp2) : 0;
	return (SUCCESS);
}

void ft_reader(t_rd **read, va_list *ap, const char *format)
{
	if (ft_chck_flags(read, format) == 1)
		return ;
	ft_chck_wdth(read, format, &ap);
	ft_chck_precision(read, format);
	ft_chck_size(read, format, &ap);
	ft_chck_mod(read, format, &ap);
}

void ft_free_lists(t_rd **read)
{
	t_rd *tmp;

	while ((*read)->prev)
	{
		tmp = (*read);
		*read = (*read)->prev;
		free(tmp);
	}
	//free(read);
}

int ft_printf(const char *format, ...)
{
	t_printf	p;
	t_rd		*tmp;

	if (!(*format))
		return (0);
	p.output.output_cnt = 0;
	va_start (p.ap, format);
	p.output.buf = NULL;
	if (!(p.read = (t_rd *)malloc(sizeof(t_rd))))
		return (0);
	p.read->strlen = ft_strlen(format);
	p.read->smb_cnt = -1;
	p.read->prev = NULL;
	while (format[++p.read->smb_cnt])
	{
		if (!(p.read->next = (t_rd *)malloc(sizeof(t_rd))))
			return (0);
		if (!(ft_pt_frst(format, &p.output, &p.read)))
			return (0);
		ft_reader(&p.read, &p.ap, format);
		if (!(ft_solver(&p.read, &p.output)))
			return (0);
		tmp = p.read;
		p.read = p.read->next;
		p.read->prev = tmp;
		p.read->smb_cnt = p.read->prev->smb_cnt;
		p.read->strlen = p.read->prev->strlen;
	}
	va_end(p.ap);
	ft_putstr(p.output.buf);
	ft_free_lists(&p.read);
	return (p.output.output_cnt);
}