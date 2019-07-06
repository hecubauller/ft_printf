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

int 	ft_app_d_prs(t_rd **read, t_out **output)
{
	int		i;
	int 	b;
	int 	strlen;
	char 	*res;
	char	*tmp;

	i = -1;
	b = -1;
	if ((*read)->mod)
	{
		if ((*read)->prs > ft_strlen((*read)->mod))
		{
			strlen = ft_strlen((*read)->mod);
			if (!(res = (char *)malloc(sizeof(char)*((*read)->prs + 1))))
				return (0);
			res[strlen] = '\0';
			while (++i != ((*read)->prs - strlen))
				res[++b] = '0';
			i = -1;
			while ((*read)->mod[++i])
				res[++b] = (*read)->mod[i];
			tmp = (*read)->mod;
			(*read)->mod= res;
			free((void *)tmp);
		}
	}
	return (1);
}

int 	ft_app_empty_fl(t_rd **read, t_out **output)
{
	int		i;
	int 	b;
	int 	strlen;
	char 	*res;
	char	*tmp;

	i = -1;
	b = -1;
	if ((*read)->mod)
	{
		if (((*read)->mod) && (!(*read)->width) && !(*read)->flag)
		{
			strlen = ft_strlen((*read)->mod);
			if (!(res = (char *) malloc(sizeof(char) * (strlen + 1))))
				return (0);
			res[strlen] = '\0';
			while ((*read)->mod[++i])
				res[++b] = (*read)->mod[i];
			tmp = (*output)->buf;
			(*output)->buf = ft_strjoin((*output)->buf, res);
			free((void *)res);
			free((void *)tmp);
		}
	}
	return (SUCCESS);
}

int    ft_app_width(t_rd **read, t_out **output)
{
	int		i;
	int 	b;
	int 	strlen;
	char 	*res;
	char	*tmp;

	i = -1;
	b = -1;
	if ((*read)->mod)
	{
		if ((*read)->width)
		{
			strlen = ft_strlen((*read)->mod);
			if ((*read)->width > strlen)
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
					free((void *) res);
					free((void *) tmp);
				}
				else if ((*read)->flag == 16) /* if '0' */
				{
					while (++i != ((*read)->width - strlen))
						res[++b] = '0';
					i = -1;
					while ((*read)->mod[++i])
						res[++b] = (*read)->mod[i];
					tmp = (*output)->buf;
					(*output)->buf = ft_strjoin((*output)->buf, res);
					free((void *) res);
					free((void *) tmp);
				}
				else //это вообще что ????
				{
					while (++i != ((*read)->width - strlen))
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
			else if ((*read)->width <= strlen)
			{
				tmp = (*output)->buf;
				(*output)->buf = ft_strjoin((*output)->buf, (*read)->mod);
				free((void *)tmp);
			}
		}
	}
	return (SUCCESS);
}

int    ft_app_fl(t_rd **read, t_out **output)
{
	int		i;
	int 	b;
	int 	strlen;
	char 	*res;
	char	*tmp;

	i = -1;
	b = 0;
	if ((*read)->mod)
	{
		if ((*read)->flag == 2 && (*read)->mod[0] != '-') //+ для положит чисел
		{
			strlen = ft_strlen((*read)->mod);
			if (!(res = (char *) malloc(sizeof(char) * (strlen + 2))))
				return (0);
			res[strlen + 1] = '\0';
			res[0] = '+';
			while ((*read)->mod[++i])
				res[++b] = (*read)->mod[i];
			tmp = (*read)->mod;
			(*read)->mod = res;
			free((void *) tmp);
		}
//	if ((*read)->flag == 4) //вывести пробел перед строкой
//	вместо знака у положит чисел (если есть ширина, то не выводится)
//		;
//	if ((*read)->flag == 8) ##########
//		;
	}
	return (SUCCESS);
}

int    ft_solver(t_rd **read, t_out *output)
{
	if (((*read)->mod_smb == 'd' || (*read)->mod_smb == 'i') &&
		((*read)->prs))
	{
		if (!(ft_app_d_prs(read, &output)))
			return (0);
	}
	if (!(ft_app_fl(read, &output)))
		return (0);
	if (!(ft_app_width(read, &output)))
		return (0);
	if (!(ft_app_empty_fl(read, &output)))
		return (0);
}
//менять все в mod, а выводить уже в конце в ft_app_empty_fl