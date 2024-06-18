# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyuminkim <kyuminkim@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 22:53:17 by kyumkim           #+#    #+#              #
#    Updated: 2024/06/19 03:17:02 by kyuminkim        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

AR = ar
ARFLAGS = rcs
NAME = libft.a

# Libft source files
LIBFT_SRCS = $(wildcard libs/libft/*.c)

# Object files
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

# Compilation rule
all: $(NAME)

$(NAME): $(LIBFT_OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(LIBFT_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c -I/opt/homebrew/opt/readline/include $< -o $@

clean:
	rm -f $(LIBFT_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re