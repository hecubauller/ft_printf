/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:25:55 by shunt             #+#    #+#             */
/*   Updated: 2019/04/12 18:36:25 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*c;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
		i++;
	c = (char *)malloc(sizeof(char) * (i + 1));
	if (c)
	{
		c[i] = '\0';
		i = -1;
		while (s[++i])
			c[i] = f(s[i]);
		return (c);
	}
	return (NULL);
}
