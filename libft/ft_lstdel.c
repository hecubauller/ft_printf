/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:48:54 by shunt             #+#    #+#             */
/*   Updated: 2019/04/10 15:58:46 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *l;
	t_list *t;

	l = *alst;
	while (l)
	{
		t = l->next;
		del(l->content, l->content_size);
		free(l);
		l = t;
	}
	*alst = NULL;
}
