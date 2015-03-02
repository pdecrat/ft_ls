#include "ft_ls.h"

char		*ft_getgrid(gid_t grid)
{
	struct group	*grgid;

	if (!(grgid = getgrgid(grid)))
		return (NULL);
	return (grgid->gr_name);
}

char		*ft_getpwuid(uid_t uid)
{
	struct passwd	*pwuid;

	if (!(pwuid = getpwuid(uid)))
		return (NULL);
	return (pwuid->pw_name);
}

struct stat	*ft_get_stat(char *p_name)
{
	struct stat	*ret;

	if (!(ret = (struct stat *)ft_memalloc(sizeof(struct stat))))
		return(NULL);
	if ((lstat(p_name, ret) == -1))
		return (NULL);
	return (ret);
}
