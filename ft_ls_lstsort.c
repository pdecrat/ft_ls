/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_lstsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdecrat <pdecrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 14:49:23 by pdecrat           #+#    #+#             */
/*   Updated: 2014/12/17 15:43:09 by pdecrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list		*ft_mergesort(t_list *front, t_list *back)
{
	t_list		*result;

	if (!front)
		return (back);
	if (!back)
		return (front);
	if ((ft_strcmp(front->content, back->content)) < 0)
	{
		result = front;
		result->next = ft_mergesort(front->next, back);
	}
	else
	{
		result = back;
		result->next = ft_mergesort(front, back->next);
	}
	return (result);
}

t_list		*ft_ls_lstsort(t_list *lst)
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
	return (ft_mergesort(ft_ls_lstsort(front), ft_ls_lstsort(back)));
}
