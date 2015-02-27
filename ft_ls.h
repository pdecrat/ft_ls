/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdecrat <pdecrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 15:43:28 by pdecrat           #+#    #+#             */
/*   Updated: 2015/02/25 12:43:00 by pdecrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define OUTPUT		core->output
# define PENDING	core->pending
# define OPT		core->opt

# include <string.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <grp.h>
# include <pwd.h>

typedef struct		s_ldisplay
{
	int		total;
	unsigned int		links;
	unsigned int		user;
	unsigned int		group;
	unsigned int		size;
}			t_ldisplay;
# define LINKS padding->links
# define USER padding->user
# define GROUP padding->group
# define SIZE padding->size

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_core
{
	char			*opt;
	t_list			*pending;
	t_list			*output;
}					t_core;

int					ft_is_opt(char *av, t_core *core);
int					ft_is_dir(char *name);
int					ft_handle_output(t_core *core);
int					ft_handle_dir(char *p_name, t_core *core);
void				ft_ls_display(t_core *core);
void				ft_long_display(t_core *core);
t_list				*ft_ls_sort(t_core *core);
t_list				*ft_ls_lstsort(t_list *lst);
t_list				*ft_ls_lstsort_t(t_list *lst);
struct stat			*ft_get_stat(char *p_name);
char				*ft_strdup(char const *s);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
char				*ft_getpwuid(uid_t uid);
char				*ft_getgrid(gid_t grid);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstcpyone(t_list *to_copy);
t_list				*ft_lstjoin(t_list **dst, t_list *src);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_memdel(void **ap);
size_t				ft_strlen(char *s);
void				ft_putendl(char const *s);
char				*ft_strchr(char const *s, int c);
t_list				*ft_lstrev(t_list **output);
void				ft_lstfreeone(t_list **alst, t_list **to_free);
t_list				*ft_lstcpy_and_del(t_list *to_copy);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_strdel(char **as);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strcmp(char const *s1, char const *s2);
char				*ft_strstr(char const *s1, char const *s2);
char				*ft_strrchr(char const *s, int c);
int					ft_is_file_foo(char *p_name, char *type);
int					ft_get_time(char *p_name);
int				ft_lstlen(t_list *lst);
unsigned int			ft_nbrlen(int nbr);
void				ft_putlst(t_list *lst);
void				ft_putchar(char c);
void				ft_putstr(char *s);
void				ft_putnbr(int n);

#endif
