#include "libft.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/** Takes a pathname as argument, returns 1 if it is a directory,
*					  0 if it isn't
*					 -1 if the pathname is incorrect
**/

int		ft_is_dir(char *name)
{
	struct stat	*buf;
	int		ret;

	ret = 0;
	if (!(buf = (struct stat *)ft_memalloc(sizeof(*buf))))
	{
		perror("ft_is_dir: ");
		return (-1);
	}
	if ((ret = stat(name, buf)) == -1)
	{
		ft_putstr_fd("ft_is_dir: cannot access ", 2);
		ft_putstr_fd(name, 2);
		perror(" ");
		ft_memdel((void **)&buf);
		return (-1);
	}
	if (S_ISDIR(buf->st_mode))
	{
		ft_memdel((void **)&buf);
		return (1);
	}
	ft_memdel((void **)&buf);
	return (0);
}
