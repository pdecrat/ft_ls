#include "ft_ls.h"

void		ft_total(struct stat **stats)
{
	unsigned int	res;
	unsigned int	i;

	i = 0;
	res = 0;
	while (stats[i])
	{
		res += stats[i]->st_blocks;
		++i;
	}
	ft_putstr("total ");
	ft_putnbr(res);
	ft_putchar('\n');
}
