# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asuissa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 17:36:49 by asuissa           #+#    #+#              #
#    Updated: 2019/03/10 18:45:33 by asuissa          ###   ########.fr        #
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


CC = gcc
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
D_FLAG = -fsanitize=address -g
HEADER = libft.h
CPPFLAGS = -I $(HEADER)
OBJ = $(FILES:.c=.o)
FILES = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isascii.c ft_isalpha.c \
		ft_isdigit.c ft_memcmp.c ft_memccpy.c ft_memcpy.c ft_memset.c \
		ft_memmove.c ft_strcat.c ft_strcmp.c ft_memchr.c ft_strcpy.c \
		ft_strdup.c ft_strlen.c ft_strlcat.c ft_strncat.c ft_isprint.c \
		ft_strncmp.c ft_strchr.c ft_strncpy.c ft_strnstr.c ft_toupper.c \
		ft_tolower.c ft_strrchr.c ft_strstr.c ft_memalloc.c ft_memdel.c \
		ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
		ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
		ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
		ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c \
		ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strlowcase.c \
		ft_strcapitalize.c ft_swap.c ft_strrev.c ft_print_words_tables.c \
		ft_foreach.c ft_any.c ft_count_if.c ft_sort_wordtab.c \
		ft_strfjoin.c get_next_line.c ft_strnchr.c ft_putnbr_base.c \
		ft_strclen.c ft_atoi_base.c ft_strmultijoinfree.c \
		ft_strf2join.c ft_memfjoin.c ft_itoa_base.c ft_printf.c specifier.c \
		specifier2.c specifier3.c ft_transform_wchar.c

all : $(NAME)

$(NAME) : $(OBJ)
	@printf "\r\e[K[$(YELLOW)Make .o done$(RESET)]\n"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "[$(PURPLE)Make $(NAME) done$(RESET)]\n"

$(OBJ) : $(HEADER)

%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@ $(CPPFLAGS)
	@printf "\r\e[K[$(YELLOW)Make $@ done$(RESET)]"

clean :
	@/bin/rm -f *.o
	@echo "[$(RED)Clean .o done$(RESET)]"

fclean : clean
	@/bin/rm -f $(NAME)
	@echo "[$(RED)Clean $(NAME) done$(RESET)]"

re : fclean all

norme :
	@norminette $(FILES) $(HEADER)

debug : $(HEADER)
	@echo "[$(RED)/!\ DEBUG MODE ON $(NAME)$(RESET)]"
	@printf "\r\e[K[$(YELLOW)Make .o done$(RESET)]\n"
	@$(CC) -c $(CFLAGS) $(D_FLAG) $(CPPFLAGS) $(FILES)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "[$(PURPLE)Make $(NAME) done$(RESET)]"
