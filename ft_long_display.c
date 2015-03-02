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

static int	ft_get_size(struct stat *stat)
{
	int	res;

	res = 0;
	if (S_ISBLK(stat->st_mode) || S_ISCHR(stat->st_mode))
	{
		res = ft_nbrlen(major(stat->st_rdev)) + 2;
		res += ft_nbrlen(minor(stat->st_rdev));
	}
	else
		res = ft_nbrlen(stat->st_size);
	return (res);
}

static void	ft_get_padding(struct stat *stat, t_ldisplay *padding)
{
	unsigned int	tmp;
	char		*buf;

	tmp = 0;
	tmp = ft_nbrlen(stat->st_nlink);
	LINKS = (LINKS > tmp) ? LINKS : tmp;
	if ((buf = ft_getpwuid(stat->st_uid)))
		USER = (USER > ft_strlen(buf)) ? USER : ft_strlen(buf);
	else
		USER = (USER > ft_nbrlen(stat->st_uid)) ? USER
			: ft_nbrlen(stat->st_uid);
	buf = NULL;
	if ((buf = ft_getgrid(stat->st_gid)))
		GROUP = (GROUP > ft_strlen(buf)) ? GROUP : ft_strlen(buf);
	else
		GROUP = (GROUP > ft_nbrlen(stat->st_gid)) ? GROUP
			: ft_nbrlen(stat->st_gid);
	tmp = ft_get_size(stat);
	SIZE = (tmp > SIZE) ? tmp : SIZE;
}

static void	ft_init_padding(t_ldisplay *padding)
{
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
		if (stats[i])
		{
			ft_get_padding(stats[i], padding);
			++i;
		}
		cursor = cursor->next;
	}
}

void		ft_long_display(t_core *core)
{
	int		lst_size;
	struct stat	**stats;
	void		*tmp;
	t_ldisplay	padding;

	lst_size = ft_lstlen(OUTPUT);
	if (!(stats = (struct stat **)ft_memalloc(sizeof(struct stat *)
		* (lst_size + 1))))
		return;
	stats[lst_size] = NULL;
	ft_init_padding(&padding);
	ft_get_stats(OUTPUT, stats, &padding);
	ft_total(stats, lst_size);
	ft_print_long_display(OUTPUT, stats, &padding);
	tmp = (void *)stats;
	while (*stats)
	{
		ft_memdel((void **)&(*stats));
		++stats;
	}
	ft_memdel(&tmp);
}
