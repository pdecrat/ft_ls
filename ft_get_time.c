/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdecrat <pdecrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 15:26:39 by pdecrat           #+#    #+#             */
/*   Updated: 2014/12/17 15:43:18 by pdecrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <time.h>
#include <sys/stat.h>

int		ft_get_time(char *p_name)
{
	struct stat		*buf;
	int				ret;

	ret = 0;
	if (!(buf = (struct stat *)ft_memalloc(sizeof(*buf))))
		return (-1);
	if ((ret = stat(p_name, buf)) == -1)
		return (-1);
	return (buf->st_mtime);
}
