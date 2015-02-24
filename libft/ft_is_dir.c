/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdecrat <pdecrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 15:44:37 by pdecrat           #+#    #+#             */
/*   Updated: 2014/12/17 15:47:44 by pdecrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int		ft_is_dir(char *name)
{
	struct stat		*buf;
	int				ret;

	ret = 0;
	if (!(buf = (struct stat *)ft_memalloc(sizeof(*buf))))
	{
		perror("ft_is_dir: ");
		return (-1);
	}
	if ((ret = stat(name, buf)) == -1)
	{
		ft_putstr_fd("ft_is_dir: cannot access ", 2);
		ft_putstr_fd(name, 2);
		perror(" ");
		ft_memdel((void **)&buf);
		return (-1);
	}
	if (S_ISDIR(buf->st_mode))
	{
		ft_memdel((void **)&buf);
		return (1);
	}
	ft_memdel((void **)&buf);
	return (0);
}
