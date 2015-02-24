/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpyone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdecrat <pdecrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 19:04:39 by pdecrat           #+#    #+#             */
/*   Updated: 2014/12/17 15:45:25 by pdecrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstcpyone(t_list *lst)
{
	if (lst)
		return (ft_lstnew(lst->content, lst->content_size));
	return (NULL);
}
