#include "ft_ls.h"

int		ft_sort_arg(char *av, t_core *core)
{
	int		ret;
	int		is_error;

	is_error = 0;
	if ((ret = ft_is_dir(av)) != -1)
	{	
		(ret == 1) ? 
			ft_lstadd(&PENDING, ft_lstnew(av, ft_strlen(av) + 1))
			: ft_lstadd(&OUTPUT, ft_lstnew(av, ft_strlen(av) + 1));
	}
	if (ret == -1)
		is_error = 1;
	return (is_error);
}

void		ft_free_core(t_core **core)
{
	ft_strdel(&(*core)->opt);
	ft_memdel((void **)&(*core)->output);
	ft_memdel((void **)&(*core)->pending);
	ft_memdel((void **)core);
}

int		ft_init_core(t_core **core)
{
	if ((*core = (t_core *)ft_memalloc(sizeof(t_core)))
		&& ((*core)->opt = ft_strnew(0))
		&& ((*core)->output = (t_list *)ft_memalloc(sizeof(t_list)))
		&& ((*core)->pending = (t_list *)ft_memalloc(sizeof(t_list))))
			return (0);
	perror("ft_init_core : ");
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;
	int		ret;
	t_core		*core;

	i = 1;
	ret = ft_init_core(&core);
	while (ret == 0 && --argc && argv[i] && argv[i][0] == '-')
		ret += ft_is_opt(&argv[i++][1], core);
	if (ret == 0 && argc == 0)
		ret += ft_handle_dir(".", core);
	else if (ret == 0 && argc == 1 && (ft_is_dir(argv[i])) == 1)
		ret += ft_handle_dir(argv[i], core);
	else
		while (argv[i])
			ret += ft_sort_arg(argv[i++], core);
	while(OUTPUT)
	{
		ft_handle_output(core);
		if (PENDING)
			ft_handle_dir(PENDING->content, core);
	}
	ft_free_core(&core);
	return ((ret > 0) ? 1 : 0);
}
