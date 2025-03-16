SRCS = checkers.c control_ops.c graphic_ops.c graphic_ops2.c map_checkers.c map_checkers2.c map_ops.c so_long.c get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
NAME = so_long
FT_PRINTF = ft_printf/libftprintf.a
LIBFT = libft/libft.a
MINILIBX_DIR = minilibx-linux
MINILIBX = minilibx-linux/libmlx.a
LFLAGS = -Lminilibx-linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(FT_PRINTF):
	@make -C ft_printf

$(LIBFT):
	@make -C libft

$(MINILIBX):
	@make -C $(MINILIBX_DIR)
$(NAME): $(OBJS) $(FT_PRINTF) $(LIBFT) $(MINILIBX)
	cc $(CFLAGS) $(LFLAGS)  $(OBJS) $(FT_PRINTF) $(LIBFT) $(MINILIBX) -o so_long
clean:
	rm -rf *.o
	@make -C ft_printf clean
	@make -C libft clean

fclean: clean
	rm -rf so_long
	@make -C ft_printf fclean
	@make -C libft fclean
	@make -C $(MINILIBX_DIR) clean

re: fclean all

.PHONY: all clean fclean re