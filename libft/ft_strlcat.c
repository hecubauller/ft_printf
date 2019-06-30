/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 12:21:33 by shunt             #+#    #+#             */
/*   Updated: 2019/04/11 18:11:57 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	a;
	size_t	b;

	a = (size_t)ft_strlen(dst);
	b = (size_t)ft_strlen(src);
	if (a < size)
	{
		j = size - a - 1;
		dst += a;
		i = 0;
		while (i < j && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
		return (a + b);
	}
	return (b + size);
}
