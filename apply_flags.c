/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:25:32 by huller            #+#    #+#             */
/*   Updated: 2019/06/24 17:25:34 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	ft_app_empty_fl(t_rd **read, t_out **output)
{
	int		i;
	int 	b;
	char 	*res;
	char	*tmp;

	i = -1;
	b = -1;
	if (((*read)->mod) && (!(*read)->width) && !(*read)->flag)
	{
		if (!(res = (char *)malloc(sizeof(char)*((ft_strlen((*read)->mod)) + 1))))
			return (0);
		res[ft_strlen((*read)->mod)] = '\0';
		while ((*read)->mod[++i])
			res[++b] = (*read)->mod[i];
		tmp = (*output)->buf;
		(*output)->buf = ft_strjoin((*output)->buf, res);
		free((void *)res);
		free((void *)tmp);
	}
	return (SUCCESS);
}

int    ft_app_width(t_rd **read, t_out **output)
{
	int		i;
	int 	b;
	char 	*res;
	char	*tmp;

	i = -1;
	b = -1;
	if ((*read)->width)
	{
		if ((*read)->width > ft_strlen((*read)->mod))
		{
			if (!(res = (char *)malloc(sizeof(char)*((*read)->width) + 1)))
				return (0);
			res[(*read)->width] = '\0';
			if ((*read)->flag == 1) /* if '-' */
			{
				while ((*read)->mod[++i])
					res[++b] = (*read)->mod[i];
				while (res[++b])
					res[b] = ' ';
				tmp = (*output)->buf;
				(*output)->buf = ft_strjoin((*output)->buf, res);
				free((void *)res);
				free((void *)tmp);
			}
			else if ((*read)->flag == 16) /* if '0' */
			{
				while (++i != ((*read)->width - ft_strlen((*read)->mod)))
					res[++b] = '0';
				i = -1;
				while ((*read)->mod[++i])
					res[++b] = (*read)->mod[i];
				tmp = (*output)->buf;
				(*output)->buf = ft_strjoin((*output)->buf, res);
				free((void *)res);
				free((void *)tmp);
			}
			else
			{
				while (++i != ((*read)->width - ft_strlen((*read)->mod)))
					res[++b] = ' ';
				i = -1;
				while ((*read)->mod[++i])
					res[++b] = (*read)->mod[i];
				tmp = (*output)->buf;
				(*output)->buf = ft_strjoin((*output)->buf, res);
				free((void *) res);
				free((void *) tmp);
			}

		}
	}
	return (SUCCESS);
}

int    ft_app_fl(t_rd **read, t_out **output)
{
//	if ((*read)->flag == 2) //вывести знак числа
//		;
//	if ((*read)->flag == 4) //вывести пробел перед строкой вм есто знака у положит чисел (если есть ширина, то не выводится)
//		;
//	if ((*read)->flag == 8)
//		;
	return (SUCCESS);
}

int    ft_solver(t_rd **read, t_out *output)
{
//	while ((*read)->prev)
//		(*read) = (*read)->prev;
	if (!(ft_app_fl(read, &output)))
		return (0);
	if (!(ft_app_width(read, &output)))
		return (0);
	if (!(ft_app_empty_fl(read, &output)))
		return (0);
}