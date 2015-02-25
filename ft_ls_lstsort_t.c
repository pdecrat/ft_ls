/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_lstsort_t.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdecrat <pdecrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 14:49:35 by pdecrat           #+#    #+#             */
/*   Updated: 2015/01/31 15:15:41 by pdecrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list		*ft_mergesort_t(t_list *front, t_list *back)
{
	t_list		*result;

	if (!front)
		return (back);
	if (!back)
		return (front);
	if ((ft_get_time(front->content)) > (ft_get_time(back->content))
			|| ((ft_get_time(front->content)) == (ft_get_time(back->content))
				&& (ft_strcmp(front->content, back->content)) < 0))
	{
		result = front;
		result->next = ft_mergesort_t(front->next, back);
	}
	else
	{
		result = back;
		result->next = ft_mergesort_t(front, back->next);
	}
	return (result);
}

t_list		*ft_ls_lstsort_t(t_list *lst)
{
	t_list		*front;
	t_list		*back;

	if (!lst || !lst->next)
		return (lst);
	front = lst;
	back = lst->next;
	while (back && back->next)
	{
		lst = lst->next;
		back = lst->next->next;
	}
	back = lst->next;
	lst->next = NULL;
	return (ft_mergesort_t(ft_ls_lstsort_t(front), ft_ls_lstsort_t(back)));
}
