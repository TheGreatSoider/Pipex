# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cocheong <cocheong@student.42kl.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 14:46:37 by cocheong          #+#    #+#              #
#    Updated: 2022/12/05 11:41:29 by cocheong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	init.c \
	children.c \
	free.c \
	path.c \

SRCS_PREFIXED = $(addprefix srcs/, $(SRCS))
# BONUS_SRCS_PREFIXED = $(addprefix bonus/srcs/, $(BONUS_SRCS))

OBJS_DIR = objs/
OBJS_M = $(SRCS:.c=.o)
OBJS_M_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS_M))

LIBFT_DIR = 42_Libft/
LIBFT_LIB = libft.a

#text color
COLOR_OFF =\033[0m
RED =\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
CYAN=\033[0;36m


all : $(NAME)

$(LIBFT_LIB) :
	@make bonus -C $(LIBFT_DIR)

$(OBJS_DIR)%.o : %.c
	@mkdir -p $(OBJS_DIR)
	@(CC) (CFLAGS) -I. -c $< -o $@

$(NAME) : $(LIBFT_LIB) 
	@$(CC) $(CFLAGS) -Imandatory/includes $(SRCS_PREFIXED) $(LIBFT_DIR)$(LIBFT_LIB) -o $(NAME)
	@echo "$(GREEN)pipex.exe Done!$(COLOR_OFF)"

bonus: $(LIBFT_LIB)
	@$(CC) $(CFLAGS) -Ibonus/includes $(BONUS_SRCS_PREFIXED) $(LIBFT_DIR)$(LIBFT_LIB) -o $(NAME)
	@echo "$(GREEN)(bonus) pipex.exe Done!$(COLOR_OFF)"

clean :
	@rm -rf $(OBJS_DIR)
	@echo "$(RED)Removed : obj files ($(NAME))$(COLOR_OFF)"
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)Removed : $(NAME).exe$(COLOR_OFF)"
	@rm -rf libft/libft.a
	@echo "$(RED)Removed : libft.a$(COLOR_OFF)"
	@rm -rf libft/ft_printf/libftprintf.a
	@echo "$(RED)Removed : libftprinf.a$(COLOR_OFF)"

re : fclean all

.PHONY : all bonus clean fclean re test heredoc
