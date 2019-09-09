# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asuissa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 17:36:49 by asuissa           #+#    #+#              #
#    Updated: 2019/03/10 18:44:25 by asuissa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re
.SUFFIXES:

# couleurs
RED = \x1B[31m
GREEN = \x1B[32m
YELLOW = \x1B[33m
BLUE = \x1B[34m
PURPLE = \x1B[35m
RESET = \033[0m
HEAD = \033[H\033[2J

MLX = -L minilibx_macos -lmlx -framework OpenGL -framework Appkit

CC = gcc
NAME = fractol
D_NAME = fractol_debug
CFLAGS = -Wall -Wextra -Werror
D_FLAG = -fsanitize=address -g
HEADER = fractol.h
HFLAGS = -I $(INC_PATH)
OBJ = $(FILES:.c=.o)
CLIBFT = -L libft -lft
SRC_PATH = src/
INC_PATH = inc/
INCLUDE = $(addprefix $(INC_PATH), $(HEADER))
SRC = $(addprefix $(SRC_PATH), $(FILES))
FILES = \
			ft_algos.c \
			ft_events.c\
			ft_cleaners.c\
			fractol_main.c\

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft
	@make -C minilibx_macos
	@printf "\r\e[K[$(YELLOW)Make .o done$(RESET)]\n"
	@$(CC) $(CLIBFT) $(MLX) $^ -o $@
	@echo "[$(PURPLE)Make $(NAME) done$(RESET)]"

$(OBJ) : $(INCLUDE)

%.o: $(SRC_PATH)%.c
	@$(CC) -c $(HFLAGS) $(CFLAGS) $< -o $@
	@printf "\r\e[K[$(YELLOW)Make $@ done$(RESET)]"

clean :
	@make -C libft clean
	@make -C minilibx_macos clean
	@/bin/rm -f $(OBJ)
	@echo "[$(RED)Clean .o done$(RESET)]"

fclean : clean
	@make -C libft fclean
	@/bin/rm -f $(NAME)
	@echo "[$(RED)Clean $(NAME) done$(RESET)]"

re : fclean all

norme :
	@make -C libft norme
	@norminette $(SRC) $(INCLUDE)

debug :
	@echo "[$(RED)/!\ DEBUG MODE ON $(NAME)$(RESET)]"
	@make -C libft debug
	@make -C minilibx_macos
	@printf "\r\e[K[$(YELLOW)Make .o done$(RESET)]\n"
	@$(CC) $(CFLAGS) $(CLIBFT) $(D_FLAG) $(MLX) $(SRC) $(HFLAGS) -o $(D_NAME)
	@echo "[$(PURPLE)Make $(D_NAME) done$(RESET)]"

debug_clean : clean
	@make -C libft fclean
	@/bin/rm -f $(D_NAME)
	@/bin/rm -rf $(D_NAME).dSYM
	@echo "[$(RED)Clean $(D_NAME) done$(RESET)]"

debug_re : debug_clean debug
