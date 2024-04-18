
SRCS	= ft_check_map.c ft_lbft_split.c get_next_line_utils.c get_next_line.c flood_fill.c \
	so_long.c 

OBJ = $(SRCS:.c=.o)

CFLAGS =  #-fsanitize=address -g3#-Wall -Wextra -Werror
NAME = so_long
AR = ar rcs
RM = rm -f
CC = cc

all:$(NAME)

$(NAME):$(OBJ)

%.o :%.c
	$(CC) -c $(CFLAGS) $^ -o $@
	$(AR) $(NAME) $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all