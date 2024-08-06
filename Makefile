# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LREADLINE = -lreadline
NAME = minishell
LIBFT = libft.a
# Source files
# delete test.c later
SRCS = main.c \
		execute/executing.c \
		execute/executing_bin.c \
		execute/executing_utils.c \
		execute/free_executing_params.c \
		execute/normal_executing.c \
		execute/pipe_executing.c \
		execute/pipe_utils.c \
		execute/redirect_executing.c \
		parse/check_operators.c \
		parse/check_redir_error.c \
		parse/check_syntax.c \
		parse/ckeck_quote.c \
		parse/error_print.c \
		parse/handler_env.c \
		parse/handler_linked_list.c \
		parse/init.c \
		parse/make_nodes.c \
		parse/parsing_utils.c \
		parse/redir.c \
		parse/signal_hanlder.c \
		parse/test.c \
		parse/tokeniz.c \
		utils/free_env.c \
		utils/ft_strcmp.c \
		utils/print_error.c \
		utils/size_func.c \
		utils/value_utils.c \
		builtin_func/builtin_execution.c \
		builtin_func/cd.c \
		builtin_func/echo.c \
		builtin_func/env.c \
		builtin_func/env_parsing_func.c \
		builtin_func/exit.c \
		builtin_func/export.c \
		builtin_func/export_check_and_do.c \
		builtin_func/export_check_validated.c \
		builtin_func/export_do_export.c \
		builtin_func/export_with_no_args.c \
		builtin_func/export_with_no_args_utils.c \
		builtin_func/pwd.c \
		builtin_func/unset.c
OBJS = $(SRCS:%.c=%.o)

LIBFTSRCS = libft/ft_atoi.c \
		libft/ft_bzero.c \
		libft/ft_calloc.c \
		libft/ft_isalnum.c \
		libft/ft_isalpha.c \
		libft/ft_isascii.c \
		libft/ft_isdigit.c \
		libft/ft_isprint.c \
		libft/ft_itoa.c \
		libft/ft_lstadd_back_bonus.c \
		libft/ft_lstadd_front_bonus.c \
		libft/ft_lstclear_bonus.c \
		libft/ft_lstdelone_bonus.c \
		libft/ft_lstiter_bonus.c \
		libft/ft_lstlast_bonus.c \
		libft/ft_lstmap_bonus.c \
		libft/ft_lstnew_bonus.c \
		libft/ft_lstsize_bonus.c \
		libft/ft_memchr.c \
		libft/ft_memcmp.c \
		libft/ft_memcpy.c \
		libft/ft_memmove.c \
		libft/ft_memset.c \
		libft/ft_putchar_fd.c \
		libft/ft_putendl_fd.c \
		libft/ft_putnbr_fd.c \
		libft/ft_putstr_fd.c \
		libft/ft_split.c \
		libft/ft_strcat.c \
		libft/ft_strchr.c \
		libft/ft_strdup.c \
		libft/ft_striteri.c \
		libft/ft_strjoin.c \
		libft/ft_strlcpy.c \
		libft/ft_strlen.c \
		libft/ft_strmapi.c \
		libft/ft_strncmp.c \
		libft/ft_strnstr.c \
		libft/ft_strrchr.c \
		libft/ft_strtrim.c \
		libft/ft_substr.c \
		libft/ft_tolower.c \
		libft/ft_toupper.c
LIBFTOBJS = $(LIBFTSRCS:%.c=%.o)

# Default target
all: $(NAME)

$(NAME):$(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT) $(LREADLINE)

$(LIBFT): $(LIBFTOBJS)
	ar rcs $@ $^

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(LIBFTOBJS)

fclean: clean
	rm -f $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re