/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuminkim <kyuminkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:32:48 by kyumkim           #+#    #+#             */
/*   Updated: 2024/07/29 01:09:59 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTING_H
# define EXECUTING_H

#include "./parse/parsing.h"

#define BCD 1
# define BPWD 2
# define BECHO 3
# define BEXPORT 4
# define BUNSET 5
# define BENV 6
# define BEXIT 7


void	execute(t_line *line);
void	unset(t_line *line, t_token *token);
void	cd(t_line *line, t_cmd *cmd);
void	pwd(t_line *line);
void	echo(t_line *line, t_token *token);
void	ft_exit(t_line *line, t_token *token);
/* ================================== ENV ==================================*/

// env.c
void	env(t_line *line, t_token *token);

/* ================================== ENV ==================================*/

/* ================================== EXPORT ==================================*/

// export.c
void	export(t_line *line, t_token *token);
char	**export_split(char *arg,  char *sep);
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

/* ================================== EXPORT ==================================*/

/* ================================== FREE ==================================*/
// free_env
void	free_env(t_env *env);

/* ================================== FREE ==================================*/

/* ================================== ENV_UTILS ==================================*/
// env_parsing_func.c
char	*find_value(t_line *line, char *key);
t_env	*find_env_with_key(t_line *line, char *key);
void	new_env(t_line *line, char *key, char *value);
void	add_env_value(t_line *line, char *key, char *value);
void	set_value(t_line *line, char *key, char *value);

// value_utils.c
char	**value_split(char *str);
/* ================================== ENV_UTILS ==================================*/

/* ================================== SIZE_UTILS ==================================*/
int		cmd_size(t_cmd *cmd);
int		env_size(t_env *start);
int		token_size(t_token *token);
/* ================================== SIZE_UTILS ==================================*/
int		ft_strcmp(const char *s1, const char *s2);

void	print_error(char *cmd, char *arg, char *msg);
int		isbuiltin(t_cmd *cmd);

int		free_argv(char **argv);
int		free_envp(char **envp);

void	initialize_pipe(t_line *line);
void	dup_pipe(t_cmd *cur_cmd, t_cmd *prev_cmd);

void	do_pipe_cmd(t_line *line, t_cmd *cmd);

void	do_normal_cmd(t_line *line, t_cmd *cmd);
void	exec_cmd_pipe(t_line *line, t_cmd *cmd);
void	execute_builtin(t_line *line, t_cmd *cmd, int cmd_def);
char	*check_and_put_path(char *dir_path, char *cmd);
void	execute_bin(t_line *line, t_cmd *cmd, char **argv, char **envp);
char	**cmd_to_argv(t_cmd *cmd);
char	**env_to_envp(t_env *env);
void	do_pipe_cmd(t_line *line, t_cmd *cmd);
#endif
