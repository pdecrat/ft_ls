#include "ft_ls.h"

void		ft_ls_display(t_core *core)
{
	t_list		*cursor;
	char		*tmp;

	cursor = OUTPUT;
	while (cursor)
	{
		if ((tmp = ft_strrchr(cursor->content, '/')))
			ft_putendl(tmp + 1);
		else
			ft_putendl(cursor->content);
		cursor = cursor->next;
	}
}
