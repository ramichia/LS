# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/13 11:20:42 by ramichia          #+#    #+#              #
#    Updated: 2017/05/11 12:46:03 by ramichia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = gcc
FLAGS = -Wall -Wextra -Werror

LIB = ./libft/libft.a
LIB_PATH = ./libft

SRC = srcs/handle_arg.c srcs/handle_error.c srcs/sort.c srcs/main.c \
	srcs/various.c srcs/built_table.c srcs/display.c srcs/stock_data.c \
	srcs/free.c srcs/sort2.c srcs/padding.c srcs/colors.c srcs/count.c \
	srcs/handle_arg2.c srcs/option_files_arg.c

HEADER = includes/ft_ls.h

OBJS = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	@ $(CC) $(FLAGS) $(SRC) $(LIB) -o $(NAME)

$(LIB):
	@make -C $(LIB_PATH)
	@echo "make ok"

%.o: %.c
	@$(CC) $(FLAGS)  -o $@ -c $<
clean:
	@rm -f $(OBJS)
	@make clean -C ./libft
	@echo "clean OK"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft
	@echo "LIBRARY DELETED"

re: fclean all
