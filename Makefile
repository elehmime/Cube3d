# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ellehmim <ellehmim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 13:40:52 by ellehmim          #+#    #+#              #
#    Updated: 2024/09/29 15:35:43 by ellehmim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
# Options de compilation
CFLAGS = -Wall -Wextra -Werror -g3
# Dossier contenant la libft et son chemin d'inclusion
LIBFT_DIR = ./libft
LIBFT_INC = -I$(LIBFT_DIR)
LIBFT_LIB = -L$(LIBFT_DIR) -lft

MIMILIBX_DIR = ./mlx
MIMILIBX_INC = -I$(MIMILIBX_DIR)
MIMILIBX_LIB = -L$(MIMILIBX_DIR) -lmlx -lX11 -lXext -L/usr/lib/X11

# Sources et objets pour le serveur et le client
SRC = parsing.c error_handling.c map_creat.c map_split.c map_check.c map_check_utils.c map_playable.c map_playable_utils.c
OBJ = $(SRC:.c=.o)

# Noms des exécutables
CUBE3D_BIN = cube3d

# Règle par défaut pour compiler le serveur et le client
all: $(CUBE3D_BIN)

# Compilation de la libft
$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

$(MIMILIBX_DIR)/libmlx_Linux.a:
	$(MAKE) -C $(MIMILIBX_DIR)

# Règle générique pour convertir les .c en .o
%.o: %.c
	$(CC) $(CFLAGS) $(LIBFT_INC) $(MIMILIBX_INC) -c $< -o $@

# Compilation du serveur
$(CUBE3D_BIN): $(OBJ) $(LIBFT_DIR)/libft.a $(MIMILIBX_DIR)/libmlx_Linux.a
	$(CC) $(OBJ) $(LIBFT_LIB) $(MIMILIBX_LIB) -o $@

# Nettoyage des fichiers compilés
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

# Suppression de tout ce qui a été compilé
fclean: clean
	rm -f $(CUBE3D_BIN)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Recompilation de tout
re: fclean all
# Empêcher make de confondre un fichier et une règle
.PHONY: all clean fclean re