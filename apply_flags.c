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

//int    ft_app_prcsn(t_rd **read, t_out **output)
//{
//	int     i;
//	int     b;
//	char    *res;
//	char 	*tmp;
//
//	b = -1;
//	i = -1;
//	if ((*read)->prs)
//	{
//		if (ft_strlen((*read)->mod) < (*read)->prs)
//		{
//			if ((*read)->mod_smb == 'd' || (*read)->mod_smb == 'i')
//			{
//				if (!(res = (char *)malloc(sizeof(char) * (*read)->prs + 1)))
//					return (0);
//				while (++i != ((*read)->prs) - ft_strlen((*read)->mod))
//					res[i] = '0';
//				while ((*read)->mod[++b])
//				{
//					res[i] = (*read)->mod[b];
//					i++;
//				}
//				tmp = (*output)->buf;
//				(*output)->buf = ft_strjoin((*output)->buf, res);
//				free((void *)res);
//				free((void *)tmp);
//			}
//		}
//	}
//	return (SUCCESS);
//
//}

int    ft_app_width(t_rd **read, t_out **output)
{
	int i;

	i = -1;
	if ((*read)->width)
	{
		if ((*read)->width > ft_strlen((*read)->mod))
		{
			if ((*read)->flag == 1) /* if '-' */
			{
				while ((*read)->mod[++i])
					(*output)->buf[++(*output)->cnt] = (*read)->mod[i];
				while ((*output)->buf[++(*output)->cnt])
					((*output)->buf[(*output)->cnt] = ' ');

			}
			else if ((*read)->flag == 16) /* if '0' */
			{
				while (++i != ((*read)->width - ft_strlen((*read)->mod)))
					(*output)->buf[(*output)->cnt] = '0';
				i = -1;
				while ((*read)->mod[++i])
					(*output)->buf[(*output)->cnt] = (*read)->mod[i];
			}
		}
	}
}

int    ft_app_fl(t_rd **read, t_out **output)
{
//	if ((*read)->flag == 2) //вывести знак числа
//		;
//	if ((*read)->flag == 4)
//		;
//	if ((*read)->flag == 8)
//		;
	return (SUCCESS);
}

int    ft_solver(t_rd **read, t_out *output)
{
	while ((*read)->prev)
		(*read) = (*read)->prev;
	if (!(ft_app_fl(read, &output)))
		return (0);
//	if (!(ft_app_prcsn(read, &output)))
//		return (0);
	if (!(ft_app_width(read, &output)))
		return (0);
	output->buf = (*read)->mod;

}