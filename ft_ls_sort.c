/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdecrat <pdecrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 14:48:20 by pdecrat           #+#    #+#             */
/*   Updated: 2014/12/17 16:06:31 by pdecrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list		*ft_rem_hidden(t_list **lst)
{
	t_list		*cursor;
	t_list		*next;

	cursor = *lst;
	while (cursor)
	{
		next = cursor->next;
		if ((ft_strstr(cursor->content, "/.")))
			ft_lstfreeone(lst, &cursor);
		cursor = next;
	}
	return (*lst);
}

t_list		*ft_ls_sort(t_core *core)
{
	if (!(ft_strchr(OPT, 'a')))
		OUTPUT = ft_rem_hidden(&OUTPUT);
	OUTPUT = (ft_strchr(OPT, 't')) ? ft_ls_lstsort_t(OUTPUT)
		: ft_ls_lstsort(OUTPUT);
	if (ft_strchr(OPT, 'r'))
		OUTPUT = ft_lstrev(&OUTPUT);
	return (OUTPUT);
}
