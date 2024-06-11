# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 22:53:17 by kyumkim           #+#    #+#              #
#    Updated: 2024/06/12 03:38:46 by jaemikim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
LIBS = -lreadline
NAME = mini_shell

# Parsing source files
PARSING_SRCS = parsing/error_print.c \
               parsing/init.c \
               parsing/linked_list_handler.c \
               parsing/make_nodes.c \
               parsing/parsing_main.c \
               parsing/parsing_utils.c \
               parsing/signal_hanlder.c \
               parsing/test.c \
               parsing/tokeniz.c \
               $(wildcard parsing/c*)

# Libft source files
LIBFT_SRCS = libs/libft/ft_putstr_fd.c \
             libs/libft/ft_strlen.c \
             libs/libft/ft_putchar_fd.c \
             libs/libft/ft_strlcpy.c

# Object files
PARSING_OBJS = $(PARSING_SRCS:.c=.o)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)
OBJS = $(PARSING_OBJS) $(LIBFT_OBJS)

# Compilation rule
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
