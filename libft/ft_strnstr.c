/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:13:14 by shunt             #+#    #+#             */
/*   Updated: 2019/04/11 18:21:21 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int l;
	int j;

	i = 0;
	l = 0;
	while (needle[l])
		l++;
	if (l == 0)
		return ((char *)haystack);
	while (haystack[i] && i < (int)len)
	{
		j = 0;
		while (i + j < (int)len && needle[j] == haystack[i + j])
		{
			if (j == l - 1 && !needle[j + 1])
				return ((char *)haystack + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
