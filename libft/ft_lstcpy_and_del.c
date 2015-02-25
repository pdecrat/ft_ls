/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy_and_del.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdecrat <pdecrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 15:45:09 by pdecrat           #+#    #+#             */
/*   Updated: 2014/12/17 15:48:35 by pdecrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstcpy_and_del(t_list *lst)
{
	t_list			*result;

	if (lst)
	{
		result = ft_lstcpyone(lst);
		result->next = (lst->next != NULL)
			? ft_lstcpy_and_del(lst->next) : NULL;
		ft_lstfreeone(&lst, &lst);
		return (result);
	}
	return (NULL);
}
