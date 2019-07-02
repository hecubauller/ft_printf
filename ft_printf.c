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
	char *res;
	char *tmp2;
	int tmp;
	int i;
	int b;

	i = 0;
	b = -1;
	tmp = (*rd)->smb_cnt;
	while (++i && format[(*rd)->smb_cnt] && format[(*rd)->smb_cnt] != '%')
		(*rd)->smb_cnt++;
	if (!(res = (char *) malloc(sizeof(char) * i)))
		return (0);
	res[i] = '\0';
	tmp--;
	while (res[++b])
		res[b] = format[++tmp];
	tmp2 = (*output).buf;
	(*output).buf = ft_strjoin((*output).buf, res);
	free((void *)res);
	free((void *)tmp2);
	return (SUCCESS);
}

void ft_reader(t_rd **read, va_list *ap, const char *format)
{
	ft_chck_flags(read, format);
	ft_chck_wdth(read, format, &ap);
	ft_chck_precision(read, format);
	ft_chck_size(read, format, &ap);
	//ft_chck_mod(read, format, &ap);
}

void ft_free_lists(t_rd **read)
{
	t_rd *tmp;

	while ((*read)->prev)
	{
		tmp = (*read);
		*read = (*read)->prev;
		free((void *) tmp);
	}
	free((void *) read);
}

int ft_printf(const char *format, ...)
{
	t_printf	p;
	t_rd	*tmp;
	int		tmp2;

	if (!(*format))
		return (0);
	p.output.output_cnt = 0;
	va_start (p.ap, format);
	tmp2 = 0;
	while (format[tmp2])
	{
		if (!(p.read = (t_rd *) malloc(sizeof(t_rd))) ||
			!(ft_pt_frst(format, &p.output, &p.read)))
			return (0);
		ft_reader(&p.read, &p.ap, format);
		tmp = p.read;
		p.read = p.read->next;
		p.read->prev = tmp;
		tmp2 = p.read->smb_cnt;
	}
	va_end(p.ap);
	if (!(ft_solver(&p.read, &p.output)))
		return (0);
	ft_free_lists(&p.read);
	return (p.output.output_cnt);
}