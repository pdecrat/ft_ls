/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdecrat <pdecrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 15:44:01 by pdecrat           #+#    #+#             */
/*   Updated: 2014/12/17 16:03:00 by pdecrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_is_opt(char *arg, t_core *core)
{
	int			i;
	char		*tmp;

	i = 0;
	if (*arg == '-')
		arg++;
	while (arg[i])
	{
		if (arg[i] == 'R' || arg[i] == 'r' || arg[i] == 'l'
			|| arg[i] == 'a' || arg[i] == 't')
			i++;
		else
		{
			ft_putstr_fd("Bad option : ", 2);
			ft_putendl_fd(&arg[i], 2);
			return (1);
		}
	}
	tmp = ft_strdup(OPT);
	ft_strdel(&OPT);
	OPT = ft_strjoin(tmp, arg);
	ft_strdel(&tmp);
	return (0);
}
