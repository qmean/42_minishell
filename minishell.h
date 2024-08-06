/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:32:48 by kyumkim           #+#    #+#             */
/*   Updated: 2024/08/07 03:37:01 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define BCD 1
# define BPWD 2
# define BECHO 3
# define BEXPORT 4
# define BUNSET 5
# define BENV 6
# define BEXIT 7

# include <stdio.h>
# include "libft/libft.h"
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
void	remove_redir_token_move(t_token *tmp);
int		check_redir_token(t_cmd *cmd, t_token *token);
int		check_redir_token2(t_cmd *cmd, t_token *token);

void	execute(t_line *line);
void	unset(t_line *line, t_token *token);
void	cd(t_line *line, t_cmd *cmd);
void	pwd(t_line *line);
void	echo(t_line *line, t_token *token);
void	ft_exit(t_line *line, t_token *token);

// env.c
void	env(t_line *line, t_token *token);

// export.c
void	export(t_line *line, t_token *token);
char	**export_split(char *arg, char *sep);

// export_with_no_args.c
void	export_with_no_args(t_line *line);

// export_add_env.c
int		add_env(t_line *line, char *arg);
int		check_plus(char *arg);

// export_do_export.c
void	do_no_value(t_line *line, char *arg);
void	do_plus(t_line *line, char *arg);
void	do_change(t_line *line, char *arg);
void	do_keys(t_line *line, char *arg);

// export_check_validated.c
int		export_check_validated(char *arg);
int		check_valid_underbar_char(char *arg);

// free_env
void	free_env(t_env *env);

// env_parsing_func.c
char	*find_value(t_line *line, char *key);
t_env	*find_env_with_key(t_line *line, char *key);
void	new_env(t_line *line, char *key, char *value);
void	add_env_value(t_line *line, char *key, char *value);
void	set_value(t_line *line, char *key, char *value);

// value_utils.c
char	**value_split(char *str);
int		cmd_size(t_cmd *cmd);
int		env_size(t_env *start);
int		token_size(t_token *token);
int		ft_strcmp(const char *s1, const char *s2);

void	print_error(char *cmd, char *arg, char *msg);
int		isbuiltin(t_cmd *cmd);

int		free_argv(char **argv);
int		free_envp(char **envp);

void	initialize_pipe(t_line *line);
void	dup_pipe(t_cmd *cur_cmd, t_cmd *prev_cmd);

void	do_normal_cmd(t_line *line, t_cmd *cmd);
void	exec_cmd_pipe(t_line *line, t_cmd *cmd);
void	execute_builtin(t_line *line, t_cmd *cmd, int cmd_def);
char	*check_and_put_path(char *dir_path, char *cmd);
void	execute_bin(t_line *line, t_cmd *cmd, char **argv, char **envp);
char	**cmd_to_argv(t_cmd *cmd);
char	**env_to_envp(t_env *env);
void	do_pipe_cmd(t_line *line, t_cmd *cur_cmd, t_cmd *prev_cmd);

void	do_redirect_cmd(t_cmd *cmd);
void	restore_stdio(t_cmd *cmd, int stdout, int stdin);

t_env	*env_dup(char *key, char *value);
void	do_heredoc(t_cmd *cmd);
#endif
