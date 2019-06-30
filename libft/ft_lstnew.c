/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:37:35 by shunt             #+#    #+#             */
/*   Updated: 2019/04/17 11:46:03 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*l;

	l = (t_list *)malloc(sizeof(t_list));
	if (l)
	{
		if (content == NULL || content_size == 0)
		{
			l->content = NULL;
			l->content_size = 0;
			l->next = NULL;
			return (l);
		}
		else
		{
			l->content = (content_size != 0) ? malloc(content_size) : NULL;
			if (l->content)
			{
				ft_memcpy(l->content, content, content_size);
				l->content_size = content_size;
				l->next = NULL;
				return (l);
			}
		}
	}
	return (NULL);
}
