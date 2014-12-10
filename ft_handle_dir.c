#include "ft_ls.h"
#include <dirent.h>
#include <sys/types.h>

char		*ft_pathname(char *current, char *sub)
{
	char		*pathname;
	char		*tmp;

	if (current[ft_strlen(current) - 1] == '/')
		pathname = ft_strjoin(current, sub);
	else
	{
		pathname = ft_strjoin(current, "/");
		tmp = ft_strdup(pathname);
		ft_memdel((void **)&pathname);
		pathname = ft_strjoin(tmp, sub);
		ft_memdel((void **)&tmp);
	}
	return (pathname);
}

int		ft_handle_dir(char *p_name, t_core *core)
{
	t_list		*tmp;
	DIR		*dir_stream;
	struct dirent	*buf;
	char		*pathname;

	if (!(dir_stream = opendir(p_name)))
	{
		perror(p_name);
		return (1);
	}
	while ((buf = readdir(dir_stream)))
	{
		pathname = ft_pathname(p_name, buf->d_name);
		ft_lstadd(&OUTPUT, ft_lstnew(pathname, ft_strlen(pathname) + 1));
		ft_memdel((void **)&pathname);
	}
	closedir(dir_stream);
	tmp = PENDING->next;
	ft_lstfreeone(&PENDING, &PENDING);
	PENDING = tmp;
	return (0);
}
