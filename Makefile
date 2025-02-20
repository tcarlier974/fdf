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

$(NAME): $(OBJ) libft.a libftprintf.a
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -Imlx_linux -Ift -Iftprintf -I./includes -L./libs -lXext -lftprintf -lX11 -lm -lft -lz -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -I./includes -Ift -lft -Imlx_linux -O3 -L./libs -c $< -o $@

libft.a:
	make bonus -C libft
	cp libft/libft.a ./libs

libftprintf.a:
	make -C ft_printf
	cp ft_printf/libftprintf.a ./libs

clean:
	rm -f $(OBJ)
	make -C libft clean
	make -C ft_printf clean

fclean: clean
	rm -f $(NAME) libft.a libftprintf.a
	rm -f ./src/*.o
	rm -f ./get_next_line/*.o
	rm -f ./ft_printf/*.o
	rm -f *.o

re: fclean all
