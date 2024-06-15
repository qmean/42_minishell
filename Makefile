# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jammin <jammin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 22:53:17 by kyumkim           #+#    #+#              #
#    Updated: 2024/06/14 01:47:55 by jammin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = -lreadline
NAME = mini_shell

# Parsing source files
PARSING_SRCS = $(wildcard parsing/*.c)

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
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L/opt/homebrew/opt/readline/lib $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c -I/opt/homebrew/opt/readline/include $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re