/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdecrat <pdecrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 15:46:12 by pdecrat           #+#    #+#             */
/*   Updated: 2014/12/17 15:46:13 by pdecrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstrev(t_list **alst)
{
	t_list		*current;
	t_list		*previous;
	t_list		*next;

	previous = NULL;
	if (!alst)
		return (NULL);
	current = *alst;
	while (current)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	return (previous);
}
