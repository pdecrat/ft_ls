
#include "libft.h"

t_list		*ft_lstcpy_and_del(t_list *lst)
{
	t_list			*result;

	if (lst)
	{
		result = ft_lstcpyone(lst);
		result->next = (lst->next != NULL) ? ft_lstcpy_and_del(lst->next) : NULL;
		ft_lstfreeone(&lst, &lst);
		return (result);
	}
	return (NULL);
}
