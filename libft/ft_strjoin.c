/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:42:19 by shunt             #+#    #+#             */
/*   Updated: 2019/04/12 18:48:06 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*d;

	if (s1 && s2)
	{
		i = ft_strlen(s1);
		j = ft_strlen(s2);
		d = (char *)malloc(sizeof(char) * (i + j + 1));
		if (d)
		{
			d[i + j] = '\0';
			i = -1;
			while (s1[++i])
				d[i] = s1[i];
			j = -1;
			while (s2[++j])
				d[i++] = s2[j];
			return (d);
		}
	}
	return (NULL);
}
