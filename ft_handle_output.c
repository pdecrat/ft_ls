#include "ft_ls.h"

int	ft_handle_output(t_core *core)
{
	t_list		*tmp;

	while (OUTPUT)
	{
		tmp = OUTPUT->next;
		ft_putendl(OUTPUT->content);
		if (ft_strchr(OPT, 'R') && (ft_is_dir(OUTPUT->content)) == 1
			&& ft_strcmp(OUTPUT->content, ".")
			&& ft_strcmp(OUTPUT->content, ".."))
				ft_lstadd(&PENDING, ft_lstcpyone(OUTPUT->content));
		ft_lstfreeone(&OUTPUT, &OUTPUT);
		OUTPUT = tmp;
	}
	if (!OUTPUT && !(OUTPUT = (t_list *)ft_memalloc(sizeof(t_list))))
		return (1);
	return (0);
}
