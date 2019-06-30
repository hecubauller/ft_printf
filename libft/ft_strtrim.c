/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:01:22 by shunt             #+#    #+#             */
/*   Updated: 2019/04/12 15:07:57 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_w(char *s, char *d, int a)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
		i++;
	while (s[j + 1])
		j++;
	while (s[j] == '\t' || s[j] == '\n' || s[j] == ' ')
		j--;
	if (!a)
		return (j - i + 1);
	k = 0;
	while (i <= j)
	{
		d[k] = s[i];
		k++;
		i++;
	}
	d[k] = '\0';
	return (k);
}

static int	ft_c(char *s)
{
	int i;

	i = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
		i++;
	return (s[i] ? 1 : 0);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		n;
	char	*d;

	if (!s)
		return (NULL);
	d = NULL;
	i = 0;
	if (!ft_c((char *)s))
	{
		d = (char *)malloc(sizeof(char) * 1);
		if (d)
		{
			d[0] = '\0';
			return (d);
		}
		return (NULL);
	}
	n = ft_w((char *)s, d, 0);
	d = (char *)malloc(sizeof(char) * (n + 1));
	if (d)
		n = ft_w((char *)s, d, 1);
	return (d);
}
