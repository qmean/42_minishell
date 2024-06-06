/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:37:52 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/06 20:05:35 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	set_value(char *key, char *value, t_data *data);

void	cd(t_data *data, char **cmdlist)
{
	char	**home;
	char	*oldpwd;
	char	*newpwd;

	oldpwd = getcwd(NULL, 0);
	if (cmd_size(cmdlist) > 1)
	{
		// todo : 에러처리 추가
		ft_putstr_fd("cd: too many arguments\n", 2);
		return ;
	}
	else if (cmd_size(cmdlist) == 0)
	{
		home = find_value("HOME", data);
		if (home != NULL)
			newpwd = home[0];
	}
	else
	{
		if (strcmp(cmdlist[0], "~") == 0)
		{
			home = find_value("HOME", data);
			if (home != NULL)
			{
				newpwd = ft_strjoin(home[0], cmdlist[0] + 1);
			}
			else
			{
				ft_putstr_fd("cd: HOME not set\n", 2);
				return ;
			}
		}
		else if (strcmp(cmdlist[0], "-") == 0)
		{
			newpwd = oldpwd;
		}
		else
			newpwd = cmdlist[0];
	}
	oldpwd = getcwd(NULL, 0);
	if (chdir(newpwd) == -1)
	{
		strerror(errno);
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd("\n", 2);
		exit(1);
	}
	else
	{
		set_value("OLDPWD", oldpwd, data);
		set_value("PWD", newpwd, data);
		free(oldpwd);
		free(newpwd);
	}
}

void	set_value(char *key, char *value, t_data *data)
{
	t_env	*env;

	env = data->env;
	while (env != NULL)
	{
		if (strcmp(env->key, key) == 0)
		{
			free(env->value[0]);
			env->value[0] = strdup(value);
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
