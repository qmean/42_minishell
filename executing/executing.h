/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuminkim <kyuminkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:32:48 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/18 23:18:58 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTING_H
# define EXECUTING_H
# include "../mainheader.h"
# include "stdio.h"
# include "string.h"
# include "errno.h"
# include "fcntl.h"
# include "sys/stat.h"
# include "readline/readline.h"
# include "dirent.h"

typedef struct s_env
{
	char			*key;
	char			**value;
	struct s_env	*next;
}	t_env;

typedef struct s_data
{
	t_env	*env;
}	t_data;

void	execute(t_data *data, char *cmd, char **args, char **input);
void	cd(t_data *data, char **args);
void	pwd(void);
void	echo(char **args);
void	ft_exit(t_data *data, char **args);
void	unset(t_data *data, char **args);
/* ================================== ENV ==================================*/

// env.c
void	env(t_data *data);
void	env_print(t_env *env);

/* ================================== ENV ==================================*/

/* ================================== EXPORT ==================================*/

// export.c
int		export(t_data *data, char **args);

// export_with_no_args.c
void	export_with_no_args(t_data *data);

// export_copy_utils.c
t_env	*copy_env(t_env *env);
char	**copy_value(char **value);

// export_print_utils.c
void	print_env_with_sort(t_env *env);
void	print_export_values(char **value);

// export_sort_utils.c
void	sort_env(t_env *env);
void	swap_env(t_env *env1, t_env *env2);
size_t	value_len(char **value);

// export_add_env.c
int		add_env(t_data *data, char *arg);
void	do_keys(t_data *data, char *arg);

// export_check_validated.c
int		export_check_validated(char *arg);
int		check_valid_first_char(char *arg);
int		check_valid_special_char(char *arg);
int		check_valid_underbar_char(char *arg);

// export_plus.c
char	**plus_split(char *arg);
void	do_plus(t_data *data, char *arg);
void	add_env_node(t_data *data, char *key, char **values);
int		check_plus(char *arg);

// export_change_value.c
int		check_change(char *arg);
void	do_change(t_data *data, char *arg);
char	**change_split(char *arg);

// export_add_no_value.c
void	do_no_value(t_data *data, char *arg);
int		check_no_value(char *arg);


/* ================================== EXPORT ==================================*/

/* ================================== FREE ==================================*/
// free_env
void	free_env(t_env *env);
void	free_values(char **values);
void	delete_values(t_env *env);

/* ================================== FREE ==================================*/

/* ================================== STRING UTILS ==================================*/

// ft_strcmp
int		ft_strcmp(const char *s1, const char *s2);

// value_split.c
char	**value_split(char *str);

/* ================================== STRING UTILS ==================================*/

/* ================================== ENV_UTILS ==================================*/

// env_parsing_func.c
char	**find_value(char *key, t_data *data);
t_env	*find_env_with_key(t_data *data, char *key);
void	new_env(t_data *data, char *key, char *value);

// env_add_env_value.c
void	add_env_value(t_data *data, char *key, char *value);

/* ================================== ENV_UTILS ==================================*/

/* ================================== SIZE_UTILS ==================================*/
int		cmd_size(char **cmdlist);
int		env_size(t_data data);
int		value_size(t_env *env);
/* ================================== SIZE_UTILS ==================================*/
#endif
