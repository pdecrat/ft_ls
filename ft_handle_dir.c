/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdecrat <pdecrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 15:43:40 by pdecrat           #+#    #+#             */
/*   Updated: 2014/12/17 15:53:45 by pdecrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				*ft_pathname(char *current, char *sub)
{
	char			*pathname;
	char			*tmp;

	if (current[ft_strlen(current) - 1] == '/')
		pathname = ft_strjoin(current, sub);
	else
	{
		pathname = ft_strjoin(current, "/");
		tmp = ft_strdup(pathname);
		ft_memdel((void **)&pathname);
		pathname = ft_strjoin(tmp, sub);
		ft_memdel((void **)&tmp);
	}
	return (pathname);
}

int					ft_handle_dir(char *p_name, t_core *core)
{
	DIR				*dir_stream;
	struct dirent	*buf;
	char			*pathname;

	if (!(dir_stream = opendir(p_name)))
		perror(p_name);
	if (dir_stream)
		while ((buf = readdir(dir_stream)))
		{
			pathname = ft_pathname(p_name, buf->d_name);
			if (OUTPUT)
				ft_lstadd(&OUTPUT, ft_lstnew(pathname,
							ft_strlen(pathname) + 1));
			else
				OUTPUT = ft_lstnew(pathname, ft_strlen(pathname) + 1);
			ft_memdel((void **)&pathname);
		}
	if (dir_stream)
		closedir(dir_stream);
	ft_lstfreeone(&PENDING, &PENDING);
	return (0);
}
