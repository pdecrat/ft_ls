/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdecrat <pdecrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 15:45:39 by pdecrat           #+#    #+#             */
/*   Updated: 2014/12/17 15:45:40 by pdecrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstfree(t_list **alst)
{
	t_list		*next;

	while (*alst)
	{
		next = (*alst)->next;
		ft_lstfreeone(alst, alst);
		*alst = next;
	}
	alst = NULL;
}
