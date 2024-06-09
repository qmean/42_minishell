/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:32:48 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/10 03:45:50 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTING_H
# define EXECUTING_H
# include "../mainheader.h"
# include "stdio.h"
# include "string.h"
# include "errno.h"
# include "readline/readline.h"

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

void	env(t_data *data);
void	cd(t_data *data, char **cmdlist);
void	pwd(t_data *data);

/* ================================== EXPORT ==================================*/

// export.c
void	export(t_data *data, char **args);

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

// export_check_validated.c
int		export_check_validated(char *arg);
int		check_valid_first_char(char *arg);
int		check_valid_special_char(char *arg);
int		check_valid_underbar_char(char *arg);

// export_plus.c
char	**plus_split(char *arg);
void	do_plus(t_data *data, char *arg);
void	add_env_value(t_data *data, char *key, char *value);
void	add_env_node(t_data *data, char *key, char **values);
int		check_plus(char *arg);

// export_change_value.c
int		check_change(char *arg);
void	do_change(t_data *data, char *arg);
void	change_env_value(t_data *data, char *key, char *value);
char	**change_split(char *arg);

/* ================================== EXPORT ==================================*/

/* ================================== FREE ==================================*/
// free_env
void	free_env(t_env *env);
void	free_values(char **values);

/* ================================== FREE ==================================*/

// ft_strcmp
int		ft_strcmp(const char *s1, const char *s2);

char	**find_value(char *key, t_data *data);
void	execute(t_data *data, char *cmd, char **args);

int		cmd_size(char **cmdlist);
#endif
