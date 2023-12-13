# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 03:25:34 by jhurpy            #+#    #+#              #
#    Updated: 2023/12/13 17:00:58 by jhurpy           ###   ########.fr        #
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
RM = rm -rf
AR = ar rc

# **************************************************************************** #
#									DIRECTORIES								   #
# **************************************************************************** #

SRCDIR = srcs
OBJDIR = objs
LIBS = ./libft/libft.a ./mlx/libmlx.a
INCDIR = # list of include directories #
EXTERN_LIBS = ./libft ./mlx

srcs = ./src/*/*.c

OBJS = $(addprefix $(OBJDIR)/, $(srcs:.c=.o))

# **************************************************************************** #
#									MAKE RULES								   #
# **************************************************************************** #

all: $(EXTERN_LIBS) $(NAME)

$(LIBS):
	@$(MAKE) -C $(EXTERN_LIBS)

$(NAME): $(OBJS) $(LIBS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(BGREEN)$(NAME) created$(RESET)"

clean:
	@$(RM) $(OBJDIR) $(OBJDIR_BONUS)
	@make clean -C $(LIBFT_DIR)
	@echo "$(BRED)$(OBJDIR) deleted$(RESET)"

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@$(RM) $(LIBS)
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
