/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdecrat <pdecrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 15:44:18 by pdecrat           #+#    #+#             */
/*   Updated: 2015/02/17 17:07:52 by pdecrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_ls_display(t_core *core)
{
	t_list		*cursor;
	char		*tmp;

	cursor = OUTPUT;
	while (cursor)
	{
		if ((tmp = ft_strrchr(cursor->content, '/')))
			ft_putendl(tmp + 1);
		else
			ft_putendl(cursor->content);
		cursor = cursor->next;
	}
}
