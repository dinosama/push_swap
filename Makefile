NAME    =    push_swap

LIBFT_D    =    libft
LIBFT_N    =    libft.a

SRCS    =    sources/push_swap.c             \
            sources/utils.c                  \
            sources/ft_checksort.c           \
			sources/ft_checkerror.c          \
			sources/operations.c             \
			sources/solver.c                 \
			sources/ft_solve_chunk.c         \
			sources/comparison.c             \
			sources/search_functions.c       \
			sources/search_function_chunk.c \
			sources/ft_solve_conditions.c    \
			sources/parsing.c                \
			sources/manage_chunk.c           \

INCS    =    /includes/push_swap.h

OBJS    =    $(SRCS:.c=.o)

CC        =    gcc
CFLAGS    =    -Wall -Wextra -Werror

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS)

$(NAME):    $(OBJS)
			@make -C $(LIBFT_D)
			@cp $(LIBFT_D)/$(LIBFT_N) $(NAME)
			@echo "\033[1;93mpush_swap compilation\033[0;m"
			@ar -rcs $(NAME) $(OBJS)
			@$(CC) $(OBJS) $(LIBFT_D)/$(LIBFT_N) -o $(NAME)
			@echo "\033[1;92mpush_swap compiled\033[0;m"

all:        $(NAME)

clean:
			@rm -rf $(OBJS)
			@make clean -C $(LIBFT_D)
			@echo "\033[1;91mobject files removed\033[0;m"

fclean:		clean
			@make fclean -C    $(LIBFT_D)
			@rm -rf $(NAME)
			@echo "\033[1;91mexecutables removed\033[0;m"

re:			fclean all

.PHONY:		all clean fclean re