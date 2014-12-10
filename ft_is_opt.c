#include "ft_ls.h"

int             ft_is_opt(char *arg, t_core *core)
{
        int             i;
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
	tmp = ft_strdup(core->opt);
	ft_strdel(&core->opt);
        core->opt = ft_strjoin(tmp, arg);
	ft_strdel(&tmp);
        return (0);
}
