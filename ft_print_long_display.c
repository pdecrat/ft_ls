#include "ft_ls.h"

static void	ft_print_time(struct stat *stat)
{
	time_t	ftime;
	time_t	current;
	char	*date;
	char	*tmp;

	ftime = stat->st_mtime;
	current = time(&current);
	tmp = ctime(&ftime);
	if ((ftime > (current + 1)) || (ftime < (current - 15552000)))
	{
		date = ft_strdel_and_join(ft_strsub(tmp, 4, 7),
			ft_strsub(tmp, 19, 5));
	}
	else
		date = ft_strsub(tmp, 4, 12);
	ft_putstr(date);
	ft_putchar(' ');
	ft_strdel(&date);
}

static void	ft_print_file_type(struct stat *stat)
{
	if (S_ISDIR(stat->st_mode))
		ft_putchar('d');
	else if (S_ISBLK(stat->st_mode))
		ft_putchar('b');
	else if (S_ISCHR(stat->st_mode))
		ft_putchar('c');
	else if (S_ISFIFO(stat->st_mode))
		ft_putchar('p');
	else if (S_ISLNK(stat->st_mode))
		ft_putchar('l');
	else if (S_ISSOCK(stat->st_mode))
		ft_putchar('s');
	else if (S_ISREG(stat->st_mode))
		ft_putchar('-');
	else
		ft_putchar('?');
}

static void	ft_print_rights(struct stat *stat)
{
	(stat->st_mode &S_IRUSR) ? ft_putchar('r') : ft_putchar('-');
	(stat->st_mode &S_IWUSR) ? ft_putchar('w') : ft_putchar('-');
	if (stat->st_mode & S_IXUSR)
		(stat->st_mode & S_ISUID) ? ft_putchar('t') : ft_putchar('x');
	else
		(stat->st_mode & S_ISUID) ? ft_putchar('T') : ft_putchar('-');
	(stat->st_mode &S_IRGRP) ? ft_putchar('r') : ft_putchar('-');
	(stat->st_mode &S_IWGRP) ? ft_putchar('w') : ft_putchar('-');
	if (stat->st_mode & S_IXGRP)
		(stat->st_mode & S_ISGID) ? ft_putchar('t') : ft_putchar('x');
	else
		(stat->st_mode & S_ISGID) ? ft_putchar('T') : ft_putchar('-');
	(stat->st_mode &S_IROTH) ? ft_putchar('r') : ft_putchar('-');
	(stat->st_mode &S_IWOTH) ? ft_putchar('w') : ft_putchar('-');
	if (stat->st_mode & S_IXOTH)
		(stat->st_mode & S_ISVTX) ? ft_putchar('t') : ft_putchar('x');
	else
		(stat->st_mode & S_ISVTX) ? ft_putchar('T') : ft_putchar('-');
	ft_putchar(' ');
}

static void	ft_print_name(char *p_name, struct stat *stat)
{
	char	*tmp;
	int	ret;
	char	buf[1024];

	tmp = (ft_strrchr(p_name, '/')) ? ft_strrchr(p_name, '/') : p_name;
	if (S_ISLNK(stat->st_mode))
	{
		if ((ret = readlink(p_name, buf, 1025)) != -1)
		{
			buf[ret] = '\0';
			ft_putstr(tmp + 1);
			ft_putstr(" -> ");
			ft_putendl(buf);
		}
	}
	else
		(tmp[0] == '/') ? ft_putendl(tmp + 1) : ft_putendl(tmp);
}

void		ft_print_long_display(t_list *files, struct stat **stats,
			t_ldisplay *padding)
{
	int	i;
	t_list	*cursor;

	i = 0;
	cursor = files;
	while (cursor)
	{
		ft_print_file_type(stats[i]);
		ft_print_rights(stats[i]);
		ft_print_all_padded(stats[i], padding);
		ft_print_time(stats[i]);
		ft_print_name(cursor->content, stats[i]);
		++i;
		cursor = cursor->next;
	}
}
