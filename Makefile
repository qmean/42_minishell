# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 22:53:17 by kyumkim           #+#    #+#              #
#    Updated: 2024/06/04 23:05:24 by kyumkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft.a
GNL = get_next_line.a
LIBFTSRCS = libs/libft/ft_atoi.c \
			libs/libft/ft_bzero.c \
			libs/libft/ft_calloc.c \
			libs/libft/ft_isalnum.c \
			libs/libft/ft_isalpha.c \
			libs/libft/ft_isascii.c \
			libs/libft/ft_isdigit.c \
			libs/libft/ft_isprint.c \
			libs/libft/ft_itoa.c \
			libs/libft/ft_memcpy.c \
			libs/libft/ft_memchr.c \
			libs/libft/ft_memcmp.c \
			libs/libft/ft_memcpy.c \
			libs/libft/ft_memmove.c \
			libs/libft/ft_memset.c \
			libs/libft/ft_putchar_fd.c \
			libs/libft/ft_putendl_fd.c \
			libs/libft/ft_putnbr_fd.c \
			libs/libft/ft_putstr_fd.c \
			libs/libft/ft_split.c \
			libs/libft/ft_strchr.c \
			libs/libft/ft_strdup.c \
			libs/libft/ft_strjoin.c \
			libs/libft/ft_strlcat.c \
			libs/libft/ft_strlcpy.c \
			libs/libft/ft_strlen.c \
			libs/libft/ft_strmapi.c \
			libs/libft/ft_strncmp.c \
			libs/libft/ft_strnstr.c \
			libs/libft/ft_strrchr.c \
			libs/libft/ft_strtrim.c \
			libs/libft/ft_substr.c \
			libs/libft/ft_tolower.c \
			libs/libft/ft_toupper.c
LIBFTOBJS = $(LIBFTSRCS:.c=.o)
GNLSRCS = libs/get_next_line/get_next_line.c \
		 libs/get_next_line/get_next_line_utils.c
GNLOBJS = $(GNLSRCS:.c=.o)

all: $(LIBFT) $(GNL)

$(GNL): $(GNLOBJS)
	ar rscv $(GNL) $(GNLOBJS)

$(LIBFT): $(LIBFTOBJS)
	ar rscv $(LIBFT) $(LIBFTOBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(LIBFTOBJS) $(GNLOBJS)

fclean: clean
	rm -f $(LIBFT) $(GNL)

re: fclean all