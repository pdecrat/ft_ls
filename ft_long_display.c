/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdecrat <pdecrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 15:42:46 by pdecrat           #+#    #+#             */
/*   Updated: 2015/02/25 12:43:20 by pdecrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_get_padding(struct stat *stat, t_ldisplay *padding)
{
	int	tmp;

	tmp = 0;
	padding->total += stat->st_blocks;
}

static void	ft_init_padding(t_ldisplay *padding)
{
	padding->total = 0;
	padding->rights = 0;
	padding->links = 0;
	padding->user = 0;
	padding->group = 0;
	padding->size = 0;
}

static void	ft_get_stats(t_list *lst, struct stat **stats,
			t_ldisplay *padding)
{
	t_list		*cursor;
	int		i;

	i = 0;
	cursor = lst;
	while (cursor)
	{
		stats[i] = ft_get_stat(cursor->content);
		ft_get_padding(stats[i], padding);
		cursor = cursor->next;
		++i;
	}
	ft_putnbr(padding->total);
	ft_putchar('\n');
}

void		ft_long_display(t_core *core)
{
	int		lst_size;
	struct stat	**stats;
	t_ldisplay	padding;

	lst_size = ft_lstlen(OUTPUT);
	if (!(stats = (struct stat **)ft_memalloc(sizeof(struct stat *)
		* (lst_size + 1))))
		return;
	stats[lst_size] = NULL;
	ft_init_padding(&padding);
	ft_get_stats(OUTPUT, stats, &padding);
}
