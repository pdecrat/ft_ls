#include "libft.h"

t_list		*ft_lstrev(t_list **alst)
{
	t_list		*current;
	t_list		*previous;
	t_list		*next;

	previous = NULL;
	if (!alst)
		return (NULL);
	current = *alst;
	while (current)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	return (previous);
}
