/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:32:47 by shunt             #+#    #+#             */
/*   Updated: 2019/04/12 18:39:28 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*d;

	i = 0;
	if (s == NULL)
		return (NULL);
	d = (char *)malloc(sizeof(char) * (len + 1));
	if (d)
	{
		d[len] = '\0';
		while (i < len)
		{
			d[i] = s[start];
			i++;
			start++;
		}
		return (d);
	}
	return (NULL);
}
