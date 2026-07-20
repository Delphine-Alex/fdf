CC = cc

NAME = fdf

CFLAGS = -Wall -Wextra -Werror -Ilibft -Iprintf -Iminilibx
MLXFLAGS = -L ./minilibx -lmlx -lXext -lX11 -lm

SRCS = fdf.c hooks.c maps.c errors.c bresenham.c maths.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a
PRINTF = printf/libftprintf.a
MLX = minilibx/libmlx.a

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C printf

$(MLX):
	make -C minilibx

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C libft
	make clean -C printf
	make clean -C minilibx
	$(RM) $(OBJS)

fclean: clean
	make fclean -C libft
	make fclean -C printf
	make clean -C minilibx
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re