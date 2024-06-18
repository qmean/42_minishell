/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:37:52 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/18 20:50:36 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	set_value(char *key, char *value, t_data *data);
void	cd_move_home(t_data *data);
void	cd_move_one_arg(t_data *data, char *path);
void	cd_move_oldpwd(t_data *data);
void	cd_move_path(t_data *data, char *path);

void	cd(t_data *data, char **args)
{
	if (cmd_size(args) == 0)
	{
		cd_move_home(data);
	}
	else if (cmd_size(args) == 1)
	{
		cd_move_one_arg(data, args[0]);
	}
	else
	{
		//todo : 에러처리 추간
		ft_putstr_fd("cd: too many arguments\n", 2);
	}
}

void	cd_move_one_arg(t_data *data, char *path)
{
	if (!ft_strcmp(path, "~"))
	{
		cd_move_home(data);
		return ;
	}
	if (!ft_strcmp(path, "-"))
	{
		cd_move_oldpwd(data);
		return ;
	}
	cd_move_path(data, path);
}

void	cd_move_path(t_data *data, char *path)
{
	t_env	*env;
	char	*oldpwd;

	oldpwd = getcwd(NULL, 0);
	if (chdir(path) == -1)
	{
		//todo : 에러처리 추가
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return ;
	}
	set_value("OLDPWD", oldpwd, data);
	set_value("PWD", getcwd(NULL, 0), data);
}

void	cd_move_oldpwd(t_data *data)
{
	t_env	*env;
	char	*oldpwd;

	env = find_env_with_key(data, "OLDPWD");
	if (env == NULL)
	{
		//todo : 에러처리 추가
		ft_putstr_fd("cd: OLDPWD not set\n", 2);
		return ;
	}
	oldpwd = getcwd(NULL, 0);
	chdir(env->value[0]);
	set_value("OLDPWD", oldpwd, data);
	set_value("PWD", env->value[0], data);
}

void	cd_move_home(t_data *data)
{
	char	*home;
	char	*key;
	char	*value;

	home = find_value("HOME", data)[0];
	if (home == NULL)
	{
		//todo : 에러처리 추가
		ft_putstr_fd("cd: HOME not set\n", 2);
		return ;
	}
	key = "OLDPWD";
	value = getcwd(NULL, 0);
	set_value(key, value, data);
	chdir(home);
	set_value("PWD", home, data);
}

void	set_value(char *key, char *value, t_data *data)
{
	t_env	*env;

	env = data->env;
	while (env != NULL)
	{
		if (strcmp(env->key, key) == 0)
		{
			if (env->value != NULL)
			{
				free(env->value[0]);
				env->value[0] = strdup(value);
			}
			else
			{
				env->value = malloc(2 * sizeof(char *));
				env->value[0] = strdup(value);
				env->value[1] = NULL;
			}
			return ;
		}
		env = env->next;
	}
	env = malloc(sizeof(t_env));
	env->key = strdup(key);
	env->value = malloc(2 * sizeof(char *));
	env->value[0] = strdup(value);
	env->value[1] = NULL;
	env->next = data->env;
	data->env = env;
}
