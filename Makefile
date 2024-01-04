# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 03:25:34 by jhurpy            #+#    #+#              #
#    Updated: 2024/01/05 03:18:29 by jhurpy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors

BRED = \033[1;31m
BYELLOW = \033[1;33m
BGREEN = \033[1;32m
BPURPLE = \033[1;35m
BBLUE = \033[1;34m
BCYAN = \033[1;36m
RESET = \033[0m

# Compiler and flags
CC = gcc
C_FLAGS = -Wall -Wextra -Werror #-fsanitize=address #-g -o3
M_FLAGS = -Llibft -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit
#S_FLAGS = -g -fsanitize=address,undefined,leak

# Commands
RM = rm -rf
AR = ar rc

# Target library name and directories
NAME = cub3D

INC_DIR = includes
LIBFT = libft/libft.a
LIBFT_DIR = libft
MLX = mlx/libmlx.a
MLX_DIR = mlx

SRC_DIR =src
SRC_FILES =	main.c \
			init_data.c \
			message_error.c \
			assign_data.c \
			assign_textures.c \
			create_map.c \
			check_data.c \
			check_map.c \
			free_data.c \
			utils_parser.c \
			utils_check_map.c \
			tester/test_parsing.c \
			rc_utils.c \
			rc_utils2.c \
			rc_minimap.c \
			rc_move.c \
			rc_draw.c \
			rc_init.c \
			rc_loop.c \
			rc_raycast.c \
			rc_raycast2.c
OBJ_DIR = obj
INCS = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

# Sources, objects and dependencies
SOURCES = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJECTS = $(SOURCES:$(SRC_DIR)%.c=$(OBJ_DIR)/%.o)

# Default target, build the library
all: $(LIBFT) $(MLX) $(NAME)
	@echo "$(BGREEN)$(NAME) created$(RESET)"

# Rule to build each personal library
$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX):
	@make -C $(MLX_DIR)

# Object file build rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/lib_cub3d.h
	@mkdir -p $(dir $@)
	$(CC) $(C_FLAGS) -c $< -o $@

# Target library build rule
$(NAME): $(OBJECTS) $(LIBFT) $(MLX)
	$(CC) $(C_FLAGS) $^ $(M_FLAGS) $(INCS) -o $(NAME)

# Clean object files
clean:
	$(RM) $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@echo "$(BGREEN)Cleaned!$(RESET)"

# Clean object files and target library
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT_DIR)/libft.a
	@$(RM) $(MLX_DIR)/libmlx.a
	@make fclean -C $(LIBFT_DIR)
	@rm ./src/tester/.test_return

# Clean and rebuild the target library
re: fclean all

# Check code style
norm:
	@norminette -R CheckForbiddenSourceHeader $(SRC_DIR)/*.c ;
	@norminette -R CheckDefine $(INC_DIR)/*.h ;
	@norminette -R CheckForbiddenSourceHeader $(LIBFT_DIR)/src/*.c ;
	@norminette -R CheckDefine $(LIBFT_DIR)/includes/*.h

# Phony targets
.PHONY: all clean fclean re norm

## **************************************************************************** #
##									COLOR									   #
## **************************************************************************** #

#BRED = \033[1;31m
#BYELLOW = \033[1;33m
#BGREEN = \033[1;32m
#BPURPLE = \033[1;35m
#BBLUE = \033[1;34m
#BCYAN = \033[1;36m
#RESET = \033[0m

## **************************************************************************** #
##									PROJECT									   #
## **************************************************************************** #

#CC = @gcc
#CFLAGS = -Wall -Werror -Wextra -g3
#MFLAGS = -Llibft -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit
##SFLAGS = -g -fsanitize=address,undefined,leak

#RM = rm -rf
#AR = ar rc

## **************************************************************************** #
##									DIRECTORIES								   #
## **************************************************************************** #

#NAME = cub3D
#LIBFT = ./libft/libft.a
#MLX = ./mlx/libmlx.a
#SRCDIR = src
#SRC_FILES =	error_managment/check_error_file.c \
#			free_functions/free_all.c \
#			message/msg_error_parsing.c \
#			parsing_map/init_data.c \
#			parsing_map/init_textures.c \
#			parsing_map/utils_parser.c \

#OBJDIR = obj
#INC = includes
#LIBFT_DIR = libft
#MLX_DIR = mlx
#INCS = -I$(INC) -I$(LIBFT_DIR) -I$(MLX_DIR)

#SOURCES = $(addprefix $(SRCDIR)/, $(SRC_FILES))
#OBJS = $(SOURCES:$(SRCDIR)%.c = $(OBJDIR)/%.o)

## **************************************************************************** #
##									MAKE RULES								   #
## **************************************************************************** #

#all: $(LIBFT_DIR) $(MLX_DIR) $(NAME)

#$(LIBFT):
#	@$(MAKE) -C $(LIBFT_DIR)

#$(MLX):
#	@$(MAKE) -C $(MLX_DIR)

#$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
#	@mkdir -p $(dir $@)
#	$(CC) $(C_FLAGS) -c $< -o $@

#$(NAME): $(OBJS) $(LIBFT) $(MLX)
#	@$(CC) $(CFLAGS) $(OBJS) $(MFLAGS) $(INCS) -o $(NAME)
#	@echo "$(BGREEN)$(NAME) created$(RESET)"

#clean:
#	@$(RM) $(OBJDIR)
#	@make clean -C $(LIBFT_DIR)
#	@make clean -C $(MLX_DIR)

#fclean: clean
#	@$(RM) $(NAME)
#	@make fclean -C $(LIBFT_DIR)
#	@echo "$(BRED)Fclean done$(RESET)"

#re: fclean all

#norm:
#	@norminette -R CheckForbiddenSourceHeader $(SRC_DIR)/*.c ;
#	@norminette -R CheckDefine $(INC_DIR)/*.h ;
#	@norminette -R CheckForbiddenSourceHeader $(LIBFT_DIR)/src/*.c ;
#	@norminette -R CheckDefine $(LIBFT_DIR)/includes/*.h

#.PHONY: all clean fclean re norm

## **************************************************************************** #
##								END OF MAKEFILE								   #
## **************************************************************************** #
