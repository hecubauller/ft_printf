/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:15:45 by shunt             #+#    #+#             */
/*   Updated: 2019/04/12 18:37:02 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			c[i] = f(i, s[i]);
		return (c);
	}
	return (NULL);
}
