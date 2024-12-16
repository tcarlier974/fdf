NAME = fdf
NAME_DEV = fdf_dev
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

dev: $(NAME_DEV)

$(NAME_DEV): $(OBJ) libft.a libmlx.a libftprintf.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft.a libmlx.a -g -fsanitize=address libftprintf.a -framework OpenGL -framework AppKit

$(NAME): $(OBJ) libft.a libmlx.a libftprintf.a
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

libft.a:
	make -C libft
	cp libft/libft.a .

libftprintf.a:
	make -C ft_printf
	cp ft_printf/libftprintf.a .

libmlx.a:
	make -C mlx_linux
	cp mlx_linux/libmlx.a .

clean:
	rm -f $(OBJ)
	make -C libft clean
	make -C mlx_linux clean
	make -C ft_printf clean

fclean: clean
	rm -f $(NAME) libft.a libmlx.a libftprintf.a
	rm -f ./src/*.o
	rm -f ./get_next_line/*.o
	rm -f ./ft_printf/*.o
	rm -f *.o

re: fclean all
