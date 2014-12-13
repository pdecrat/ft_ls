#include "libft.h"

void		ft_lstfree(t_list **alst)
{
	t_list		*next;

	while (*alst)
	{
		next = (*alst)->next;
		ft_lstfreeone(alst, alst);
		*alst = next;
	}
	alst = NULL;
}
