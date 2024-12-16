NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \
		./src/draw.c \
		./src/hook.c \
		./src/init.c \
		./src/utils.c \
		./src/rgb.c \
		./src/draw_view.c \
		./src/init2.c \
		./src/offset.c \
		./src/utils2.c \



OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) libft.a libmlx.a libftprintf.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft.a libmlx.a -g -fsanitize=address libftprintf.a -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft.a:
	make -C libft
	cp libft/libft.a .

libftprintf.a:
	make -C ft_printf
	cp ft_printf/libftprintf.a .

libmlx.a:
	make -C mlx
	cp mlx/libmlx.a .

clean:
	rm -f $(OBJ)
	make -C libft clean
	make -C mlx clean
	make -C ft_printf clean

fclean: clean
	rm -f $(NAME) libft.a libmlx.a libftprintf.a
	rm -f ./src/*.o
	rm -f ./get_next_line/*.o
	rm -f ./ft_printf/*.o
	rm -f *.o

re: fclean all
