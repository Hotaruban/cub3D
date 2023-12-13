# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 03:25:34 by jhurpy            #+#    #+#              #
#    Updated: 2023/12/14 01:23:06 by jhurpy           ###   ########.fr        #
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

NAME = cub3D
NAME_BONUS = # name of the bonus project #
CC = @gcc
CFLAGS = -Wall -Werror -Wextra -g3
MFLAGS = -Llibft -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit
RM = rm -rf
AR = ar rc

# **************************************************************************** #
#									DIRECTORIES								   #
# **************************************************************************** #

SRCDIR = srcs
OBJDIR = objs
LIBFT = ./libft/libft.a
MLX = ./mlx/libmlx.a
INCDIR = ./includes
EXTERN_LIBS = $(LIBFT) $(MLX)
INCS = -I$(INCDIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

srcs =	src/error_managment/check_error_file.c \
		src/free_functions/free_all.c \
		src/message/msg_error_parsing.c \
		src/parsing_map/init_data.c \
		src/parsing_map/init_textures.c \
		src/parsing_map/utils_parser.c \

OBJS = $(addprefix $(OBJDIR)/, $(srcs:.c=.o))

# **************************************************************************** #
#									MAKE RULES								   #
# **************************************************************************** #

all: $(EXTERN_LIBS) $(NAME)

$(EXTERN_LIBS):
	@$(MAKE) -C $(LIBFT)
	@echo "$(BGREEN)$(LIBFT) created$(RESET)"
	@$(MAKE) -C $(MLX)
	@echo "$(BGREEN)$(MLX) created$(RESET)"

$(NAME): $(OBJS) $(LIBS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(BGREEN)$(NAME) created$(RESET)"

clean:
	@$(RM) $(OBJDIR) $(OBJDIR_BONUS)
	@make clean -C $(LIBFT)
	@echo "$(BRED)$(LIBFT) deleted$(RESET)"
	@make clean -C $(MLX)
	@echo "$(BRED)$(MLX) deleted$(RESET)"
	@echo "$(BRED)$(OBJDIR) deleted$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBS)
	@make fclean -C $(LIBFT)
	@make fclean -C $(MLX)
	@echo "$(BRED)$(LIBS) deleted$(RESET)"
	@echo "$(BRED)$(NAME) deleted$(RESET)"

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
