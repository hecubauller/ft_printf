/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_df.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:03:32 by shunt             #+#    #+#             */
/*   Updated: 2019/04/14 16:23:57 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_df(char *name)
{
	int		fd;
	char	buf;

	fd = open(name, O_RDONLY);
	if (fd == -1)
		write(1, "Invalid file name.\n", 19);
	else
		while (read(fd, &buf, 1))
			write(1, &buf, 1);
	close(fd);
}
