/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:44:09 by shunt             #+#    #+#             */
/*   Updated: 2019/04/09 12:29:10 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		l;
	int		i;
	int		j;

	l = 0;
	while (needle[l])
		l++;
	if (l == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (j == l - 1)
				return ((char *)haystack + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
