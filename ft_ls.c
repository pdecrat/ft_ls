/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdecrat <pdecrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 15:44:08 by pdecrat           #+#    #+#             */
/*   Updated: 2014/12/17 16:06:03 by pdecrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_handle_core(t_core *core)
{
	int		has_displayed;

	has_displayed = 0;
	while (OUTPUT || PENDING)
	{
		if (OUTPUT && ++has_displayed)
			ft_handle_output(core);
		if (PENDING)
		{
			if (has_displayed)
				ft_putchar('\n');
			if (has_displayed || ft_strchr(OPT, 'R')
				|| PENDING->next)
			{
				ft_putstr(PENDING->content);
				ft_putendl(":");
			}
		}
		if (PENDING)
			ft_handle_dir(PENDING->content, core);
	}
	return (0);
}

int			ft_sort_arg(char *av, t_core *core)
{
	int		ret;
	int		is_error;

	is_error = 0;
	if ((ret = ft_is_dir(av)) != -1)
	{
		if (ret == 1)
		{
			if (PENDING)
				ft_lstadd(&PENDING, ft_lstnew(av, ft_strlen(av) + 1));
			else
				PENDING = ft_lstnew(av, ft_strlen(av) + 1);
		}
		else
		{
			if (OUTPUT)
				ft_lstadd(&OUTPUT, ft_lstnew(av, ft_strlen(av) + 1));
			else
				OUTPUT = ft_lstnew(av, ft_strlen(av) + 1);
		}
	}
	if (ret == -1)
		is_error = 1;
	return (is_error);
}

int			ft_init_core(t_core **core)
{
	if ((*core = (t_core *)ft_memalloc(sizeof(t_core)))
		&& ((*core)->opt = ft_strnew(0)))
	{
		(*core)->output = NULL;
		(*core)->pending = NULL;
		return (0);
	}
	perror("ft_init_core : ");
	return (1);
}

int			main(int argc, char **argv)
{
	int		i;
	int		ret;
	t_core	*core;

	i = 1;
	ret = ft_init_core(&core);
	while (ret == 0 && --argc && argv[i] && argv[i][0] == '-')
		ret += ft_is_opt(&argv[i++][1], core);
	if (ret == 0 && argc == 0)
		PENDING = ft_lstnew(".", 2);
	else if (ret == 0 && argc == 1 && (ft_is_dir(argv[i])) == 1)
		PENDING = ft_lstnew(argv[i], ft_strlen(argv[i]) + 1);
	else
		while (argv[i])
			ret += ft_sort_arg(argv[i++], core);
	ret += ft_handle_core(core);
	ft_strdel(&core->opt);
	ft_memdel((void **)&core);
	return ((ret > 0) ? 1 : 0);
}
