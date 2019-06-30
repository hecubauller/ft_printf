/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:05:27 by shunt             #+#    #+#             */
/*   Updated: 2019/04/15 18:26:02 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *l;

	if (f && lst)
	{
		if (!(l = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		*l = *f(lst);
		if (lst->next)
		{
			l->next = ft_lstmap(lst->next, f);
			if (l->next == NULL)
			{
				free(l);
				return (NULL);
			}
		}
		return (l);
	}
	return (NULL);
}
