/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 00:58:40 by jaemikim          #+#    #+#             */
/*   Updated: 2024/08/06 17:52:12 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>

# include "../libft.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <termios.h>

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_token
{
	int				isspace;
	char			*data;
	int				redir;

	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef struct s_cmd
{
	char			*buf;
	char			quote;
	int				input_file;
	int				output_file;
	char			*heredoc_str;

	int				pipe[2];
	t_token			*first_token;
	t_token			*tokens;
	t_env			*env;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_line
{
	t_cmd	*first_cmd;
	t_cmd	*cmds;
	t_env	*env;
	int		pipe_flag;
	int		exit_flag;
}	t_line;

int		iswhitespace(char *c);
void	set_signal(void);
void	signal_handler(int signo);
void	sigint_printc_off(void);
void	sigint_printc_on(void);
void	sig_term_handler(void);
t_cmd	*make_cmd(void);
t_token	*make_token(void);
void	init(t_line *lines);
void	tokenize_main(char *line, t_line *lines);
void	add_token(t_cmd *cmd);
int		check_pipe(char *line, t_line *lines, int *i);
int		check_quote(char *line, t_cmd *cmd, int *i);
int		check_smallquote(char *line, t_cmd *cmd, int *i);
int		check_bigquote(char *line, t_cmd *cmd, int *i);
int		error_syntax(char *c);
int		error_invalid_quote(void);
int		check_escape(char *line, t_line *lines, int *i);
int		check_semicolon(char *line, t_line *lines, int *i);
void	add_cmd(t_line *lines);
char	*ft_strjoin_free(char *s1, char s2);
void	free_cmd(t_line *lines);
void	free_token(t_token *token);
int		check_space(char *line, t_cmd *cmd, int *i);
int		check_env(char *line, t_line *lines, int *i);
void	get_env_value(char *key, t_line *line);
int		ft_strcmp_par(const char *s1, const char *s2);
int		check_issue(char *line, t_line *lines, int *i);
int		check_redir(char *line, t_line *lines, int *i);
int		check_redir_right(char *line, t_line *lines, int *i);
int		check_redir_left(char *line, t_line *lines, int *i);
int		check_syntax(t_line *lines);
void	print_cmd(t_line *lines);
int		error_nofile(char *c);
int		input_redirection(t_cmd *cmds, t_token *token);
int		output_redirection(t_cmd *cmds,	t_token *token);
int		output_append_redirection(t_cmd *cmds, t_token *token);
int		input_heredoc_redirection(t_cmd *cmds, t_token *token);
void	remove_redir_token(t_token *token);
int		handle_special_characters(char *line, t_line *lines, int *i);
void	handle_underbar(char *line, int *i, char **key);
int		check_redir_syntax1(char *line, int i);
int		check_redir_syntax2(char *line, int *i);
int		check_redir_syntax3(char *line, int *i);
int		check_redir_syntax4(char *line, int *i);

#endif
