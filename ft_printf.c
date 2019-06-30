/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 16:26:50 by huller            #+#    #+#             */
/*   Updated: 2019/06/30 16:26:51 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    ft_pt_frst(const char * restrict format, t_out **output, t_rd **rd)
{
    char    *res;
    int     tmp;
    int     i;
    int     b;

    i = 0;
    b = -1;
    tmp = (*rd)->smb_cnt;
    while (++i && format[(*rd)->smb_cnt] && format[(*rd)->smb_cnt] != '%')
        (*rd)->smb_cnt++;
    if (!(res = (char *)malloc(sizeof(char) * i)))
        return (0);
    res[i] = '\0';
    tmp--;
    while (res[++b])
        res[b] = format[++tmp];
    (*output)->buf = ft_strjoin((*output)->buf, res);
    free((void *)res);
}

void     ft_reader(t_rd **read, va_list *ap, const char *restrict format)
{
    ft_chck_flags(read, format);
    ft_chck_wdth(read, format, &ap);
    ft_chck_precision(read, format);
    ft_chck_size(read, format, &ap);
    ft_chck_mod(read, format, &ap);
}

void    ft_free_lists(t_rd **read)
{
    t_rd    *tmp;

    while ((*read)->prev)
    {
        tmp = (*read);
        *read = (*read)->prev;
        free((void *)tmp);
    }
    free((void *)read);
}

int     ft_printf(const char * restrict format, ...)
{
    int     symbols;
    va_list ap;
    t_rd    *tmp;
    t_rd    *read;
    t_out   *output;

    if (!(*format))
        return (0);
    if (!(output = (t_out *)malloc(sizeof(t_out))))
        return (0);
    output->output_cnt = 0;
    va_start (ap, format);
    while (*format) //изменить условия передвижения по строке
    {
        if (!(read = (t_rd *) malloc(sizeof(t_rd))))
            return (0);
        if (!(ft_pt_frst(format, &output, &read)))
            return (0);
        ft_reader(&read, &ap, format);
        tmp = read;
//        printf("flags: %d\n", read->flag);
//        printf("size: %i\n", read->size);
//        printf("width: %d\n", read->width);
//        printf("precision: %d\n", read->prs);
        read = read->next;
        read->prev = tmp;
    }
    va_end(ap);
    if (!(ft_solver(&read, &output)))
        return (0);
    ft_free_lists(&read);
    symbols = output->output_cnt;
    free((void *)output);
    return (symbols);
}
