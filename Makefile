
SRCS	= ft_check_map.c ft_lbft_split.c get_next_line_utils.c get_next_line.c flood_fill.c \
	so_long.c so_long_utils.c ft_printf.c

OBJ = $(SRCS:.c=.o)

CFLAGS =#-Wall -Wextra -Werror
NAME = so_long
AR = ar rcs
RM = rm -f
CC = cc

all:$(NAME)

$(NAME):$(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all