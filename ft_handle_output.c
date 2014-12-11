#include "ft_ls.h"

t_list	*ft_del_files(t_core *core)
{
	t_list		*cursor;
	t_list		*tmp;

	cursor = OUTPUT;
	while (cursor)
	{
		tmp = cursor->next;
		if (!(ft_strchr(OPT, 'R')) || (ft_is_dir(cursor->content)) != 1
			|| !(ft_strcmp(ft_strrchr(cursor->content, '/'), "/."))
			|| !(ft_strcmp(ft_strrchr(cursor->content, '/'), "/..")))
			ft_lstfreeone(&OUTPUT, &cursor);
		cursor = tmp;
	}
	return (OUTPUT);
}

int	ft_handle_output(t_core *core)
{
	if (OUTPUT)
	{
		OUTPUT = ft_ls_sort(core);
		ft_ls_display(core);
		OUTPUT = ft_del_files(core);
	}
	if (OUTPUT && ft_strchr(OPT, 'R'))
	{
		if (PENDING)
			PENDING = ft_lstjoin(&PENDING, OUTPUT);
		else
			PENDING = ft_lstcpy_and_del(OUTPUT);
		OUTPUT = NULL;
	}
	return (0);
}
