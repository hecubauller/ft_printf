/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:09:04 by shunt             #+#    #+#             */
/*   Updated: 2019/04/09 17:52:58 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	i = 0;
	if (src < dst)
	{
		while (i < (int)len)
			i++;
		while (--i >= 0)
			((char *)dst)[i] = ((char *)src)[i];
	}
	else
	{
		i = -1;
		while (++i < (int)len)
			((char *)dst)[i] = ((char *)src)[i];
	}
	return (dst);
}
