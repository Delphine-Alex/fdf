CC = cc

NAME = libftprintf.a

SRCS =	ft_printf.c ft_putchar.c ft_putstr.c ft_strlen.c \
	ft_putnbr.c ft_putunbr.c ft_putnbr_hexlower.c ft_putnbr_hexupper.c \
	ft_putadress.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

INCLUDES = .

.c.o:
	$(CC) $(CFLAGS) -c -I $(INCLUDES) $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean 
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
