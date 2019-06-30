/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:24:07 by shunt             #+#    #+#             */
/*   Updated: 2019/04/12 17:47:28 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *m;

	if (!size)
		return (NULL);
	m = (void *)malloc(sizeof(void) * size);
	if (m)
	{
		ft_bzero(m, size);
		return (m);
	}
	return (NULL);
}
