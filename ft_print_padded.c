#include "ft_ls.h"

static void	ft_print_size(struct stat *stat, t_ldisplay *padding)
{
	int	maxlen;
	int	len;

	maxlen = SIZE;
	if (S_ISBLK(stat->st_mode) || S_ISCHR(stat->st_mode))
	{
		len = ft_nbrlen(major(stat->st_rdev)) +
			ft_nbrlen(minor(stat->st_rdev)) + 2;
		while (maxlen-- > len)
			ft_putchar(' ');
		ft_putnbr(major(stat->st_rdev));
		ft_putstr(", ");
		ft_putnbr(minor(stat->st_rdev));
	}
	else
	{
		len = ft_nbrlen(stat->st_size);
		while (maxlen-- > len)
			ft_putchar(' ');
		ft_putnbr(stat->st_size);
	}
	ft_putchar(' ');
}

static void	ft_print_grid(struct stat *stat, t_ldisplay *padding)
{
	struct group	*grp;
	int		maxlen;
	int		len;

	grp = getgrgid(stat->st_gid);
	maxlen = GROUP;
	if (grp)
	{
		ft_putstr(grp->gr_name);
		len = ft_strlen(grp->gr_name);
	}
	else
	{
		ft_putnbr(stat->st_gid);
		len = ft_nbrlen(stat->st_gid);
	}
	while (maxlen-- >= len)
		ft_putchar(' ');
}

static void	ft_print_uid(struct stat *stat, t_ldisplay *padding)
{
	struct passwd	*name;
	int		maxlen;
	int		len;

	name = getpwuid(stat->st_uid);
	maxlen = USER;
	if (name)
	{
		ft_putstr(name->pw_name);
		len = ft_strlen(name->pw_name);
	}
	else
	{
		ft_putnbr(stat->st_uid);
		len = ft_nbrlen(stat->st_uid);
	}
	while (maxlen-- >= len)
		ft_putchar(' ');
}

static void	ft_print_nlink(struct stat *stat, t_ldisplay *padding)
{
	int	maxlen;
	int	len;

	maxlen = LINKS;
	len = ft_nbrlen(stat->st_nlink);
	while (maxlen-- > len)
		ft_putchar(' ');
	ft_putnbr(stat->st_nlink);
	ft_putchar(' ');
}

void		ft_print_all_padded(struct stat *stat, t_ldisplay *padding)
{
	ft_print_nlink(stat, padding);
	ft_print_uid(stat, padding);
	ft_print_grid(stat, padding);
	ft_print_size(stat, padding);
}
