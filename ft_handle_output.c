/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdecrat <pdecrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 15:43:46 by pdecrat           #+#    #+#             */
/*   Updated: 2015/02/25 12:43:41 by pdecrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list			*ft_del_files(t_core *core)
{
	t_list		*cursor;
	t_list		*tmp;

	cursor = OUTPUT;
	while (cursor)
	{
		tmp = cursor->next;
		if (!(ft_strchr(OPT, 'R'))
			|| !(ft_strcmp(ft_strrchr(cursor->content, '/'), "/."))
			|| !(ft_strcmp(ft_strrchr(cursor->content, '/'), "/.."))
			|| (ft_is_file_foo(cursor->content, "link"))
			|| (ft_is_dir(cursor->content)) != 1)
			ft_lstfreeone(&OUTPUT, &cursor);
		cursor = tmp;
	}
	return (OUTPUT);
}

int				ft_handle_output(t_core *core)
{
	if (OUTPUT)
	{
		OUTPUT = ft_ls_sort(core);
		(ft_strchr(OPT, 'l')) ? ft_long_display(core) : ft_ls_display(core);
		OUTPUT = ft_del_files(core);
	}
	if (OUTPUT && ft_strchr(OPT, 'R'))
	{
		if (PENDING)
			PENDING = ft_lstjoin(&PENDING, OUTPUT);
		else
			PENDING = ft_lstcpy_and_del(OUTPUT);
		OUTPUT = NULL;
	}
	return (0);
}
