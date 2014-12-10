#include "libft.h"

t_list		*ft_lstjoin(t_list **dst, t_list *src)
{
	t_list		*cursor;
	t_list		*tmp;

	tmp = ft_lstcpy_and_del(src);
	cursor = tmp;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = *dst;
	return (tmp);
}
