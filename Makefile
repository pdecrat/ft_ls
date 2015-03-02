NAME = ft_ls
FLAGS = -Werror -Wextra -Wall

SRC = ft_get_time.c \
	  ft_handle_dir.c \
	  ft_handle_output.c \
	  ft_is_opt.c \
	  ft_long_display.c \
	  ft_ls.c \
	  ft_ls_display.c \
	  ft_ls_lstsort.c \
	  ft_ls_lstsort_t.c \
	  ft_ls_sort.c \
	ft_get_stat.c \
	ft_print_long_display.c

Includes = ft_ls.h

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	make -C ./libft
	gcc $(FLAGS) -c $(SRC) -L ./libft/
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(INCLUDES) -L ./libft -lft -I libft/

clean :
	make -C ./libft clean
	rm -rf $(OBJ)

fclean : clean
	make -C ./libft fclean
	rm -rf $(NAME)

re : fclean all
