#include "ft_ls.h"

void		ft_ls_display(t_core *core)
{
	t_list		*cursor;

	cursor = OUTPUT;
	while (cursor)
	{
		ft_putendl(cursor->content);
		cursor = cursor->next;
	}
}
