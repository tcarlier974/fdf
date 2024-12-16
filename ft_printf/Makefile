# Nom de la bibliothèque finale
NAME = libftprintf.a

# Fichiers sources pour ft_printf
SRC = ft_printf.c \
	printc.c \
	printd.c \
	prints.c \
	printp.c \
	printx.c \
	printu.c

# Objets correspondant aux sources
OBJ = $(SRC:.c=.o)

# Options de compilation
FLAGS = -Wall -Wextra -Werror

# Dossier de libft (si libft.a n'est pas dans le même dossier)
LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

# Cible par défaut : crée la bibliothèque
all : $(LIBFT) $(NAME)

# Compilation des fichiers objets
%.o : %.c
	gcc $(FLAGS) -c $< -o $@

# Création de la bibliothèque ft_printf avec libft
$(NAME) : $(OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

# Nettoyage des fichiers objets
clean :
	rm -rf $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(NAME)

# Nettoyage complet
fclean : clean
	$(MAKE) -C $(LIBFT_DIR) fclean

# Reconstruction complète
re : fclean all
