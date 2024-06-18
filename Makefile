# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 22:53:17 by kyumkim           #+#    #+#              #
#    Updated: 2024/06/16 02:37:48 by jaemikim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
LIBS = -lreadline
NAME = mini_shell

# Parsing source files
PARSING_SRCS = $(wildcard parsing/*.c)

# Libft source files
LIBFT_SRCS = $(wildcard libs/libft/*.c)

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