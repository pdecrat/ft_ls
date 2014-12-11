#include "ft_ls.h"

void	ft_del_files(t_core *core)
{
	t_list		*cursor;
	t_list		*tmp;

	cursor = OUTPUT;
	while (cursor && cursor->content)
	{
		tmp = cursor->next;
		if (!(ft_strchr(OPT, 'R')))
			ft_lstfreeone(&OUTPUT, &cursor);
		else if ((ft_is_dir(cursor->content)) != 1)
		{
			ft_lstfreeone(&OUTPUT, &cursor);
		}
		cursor = tmp;
	}
}

int	ft_handle_output(t_core *core)
{
	if (OUTPUT && OUTPUT->content)
	{
		ft_ls_sort(core);
		ft_ls_display(core);
		ft_del_files(core);
	}
	if (OUTPUT && OUTPUT->content && ft_strchr(OPT, 'R'))
	{
		if (PENDING->content)
			PENDING = ft_lstjoin(&PENDING, OUTPUT);
		else
			PENDING = ft_lstcpy_and_del(OUTPUT);
	}
	if (!OUTPUT && !(OUTPUT = (t_list *)ft_memalloc(sizeof(t_list))))
		return (1);
	return (0);
}
