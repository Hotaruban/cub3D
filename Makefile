# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 03:25:34 by jhurpy            #+#    #+#              #
#    Updated: 2023/12/14 03:15:10 by jhurpy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#									COLOR									   #
# **************************************************************************** #

BRED = \033[1;31m
BYELLOW = \033[1;33m
BGREEN = \033[1;32m
BPURPLE = \033[1;35m
BBLUE = \033[1;34m
BCYAN = \033[1;36m
RESET = \033[0m

# **************************************************************************** #
#									PROJECT									   #
# **************************************************************************** #

CC = @gcc
CFLAGS = -Wall -Werror -Wextra -g3
MFLAGS = -Llibft -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit
#SFLAGS = -g -fsanitize=address,undefined,leak

RM = rm -rf
AR = ar rc

# **************************************************************************** #
#									DIRECTORIES								   #
# **************************************************************************** #

NAME = cub3D
LIBFT = ./libft/libft.a
MLX = ./mlx/libmlx.a
SRCDIR = src
SRC_FILES =	error_managment/check_error_file.c \
			free_functions/free_all.c \
			message/msg_error_parsing.c \
			parsing_map/init_data.c \
			parsing_map/init_textures.c \
			parsing_map/utils_parser.c \

OBJDIR = obj
INC = includes
LIBFT_DIR = ./libft
MLX_DIR = ./mlx
INCS = -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(INC)

SOURCES = $(addprefix $(SRCDIR)/, $(SRC_FILES))
OBJS = $(SOURCES:$(SRCDIR)%.c = $(OBJDIR)/%.o)

# **************************************************************************** #
#									MAKE RULES								   #
# **************************************************************************** #

all: $(LIBFT_DIR) $(MLX_DIR) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(MFLAGS) $(INCS) -o $(NAME)
	@echo "$(BGREEN)$(NAME) created$(RESET)"

clean:
	@$(RM) $(OBJDIR)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(BRED)Fclean done$(RESET)"

re: fclean all

norm:
	@norminette -R CheckForbiddenSourceHeader $(SRC_DIR)/*.c ;
	@norminette -R CheckDefine $(INC_DIR)/*.h ;
	@norminette -R CheckForbiddenSourceHeader $(LIBFT_DIR)/src/*.c ;
	@norminette -R CheckDefine $(LIBFT_DIR)/includes/*.h

.PHONY: all clean fclean re norm

# **************************************************************************** #
#								END OF MAKEFILE								   #
# **************************************************************************** #
