/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfreeone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdecrat <pdecrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 15:01:31 by pdecrat           #+#    #+#             */
/*   Updated: 2014/11/12 15:27:57 by pdecrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstfreeone(t_list **alst, t_list **to_free)
{
	t_list		*cursor;
	t_list		*tmp;

	cursor = *alst;
	if (cursor == *to_free)
	{
		*alst = cursor->next;
		ft_memdel((void **)&cursor->content);
		ft_memdel((void **)&cursor);
	}
	else
	{
		while (cursor && cursor->next && cursor->next != *to_free)
			cursor = cursor->next;
		if (cursor->next == *to_free)
		{
			tmp = cursor->next;
			cursor->next = cursor->next->next;
			ft_memdel((void **)&tmp->content);
			ft_memdel((void **)&tmp);
		}
	}
}
