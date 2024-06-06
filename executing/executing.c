/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:11:50 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/06 20:03:36 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void echo(char **pString, char **pString1);
void	export(t_data *data, char **args);
void	exec_cmd(t_data *data, char *cmd, char **args);
void	unset(t_data *data, char **args);


//todo: strcmp -> ft_strcmp
void	execute(t_data *data, char *cmd, char **args, char **envp)
{
	if (!strcmp(cmd, "env"))
		env(data);
	else if (!strcmp(cmd, "cd"))
		cd(data, args);
	else if (!strcmp(cmd, "export"))
		export(data, args);
	else if (!strcmp(cmd, "unset"))
		unset(data, args);
	else if (!strcmp(cmd, "echo"))
		echo(args, args);
	else if (!strcmp(cmd, "exit"))
		exit(0);
	else if (!strcmp(cmd, "pwd"))
		pwd(data);
	else
		exec_cmd(data, cmd, args);
	return ;
}

void	exec_cmd(t_data *data, char *cmd, char **args)
{
	char	**paths;
	char	*joined;

	paths = find_value("PATH", data);
	if (paths == NULL)
	{
		ft_putstr_fd("command not found\n", 2);
		return ;
	}
	while (*paths)
	{
		joined = ft_strjoin(*paths, "/");
		if (execve(ft_strjoin(joined, cmd), args, NULL) == -1)
			paths++;
	}
	ft_putstr_fd("command not found\n", 2);
}

void	echo(char **pString, char **pString1)
{
	int	i;

	i = 0;
	while (pString[i])
	{
		ft_putstr_fd(pString[i], 1);
		i++;
	}
	ft_putstr_fd("\n", 1);
}

void	unset(t_data *data, char **args)
{
	t_env	*env;
	int		i;

	i = 0;
	while (args[i])
	{
		env = data->env;
		while (env)
		{
			if (!ft_strncmp(env->key, args[i], ft_strlen(args[i])))
			{
				env->value[0] = NULL;
				break ;
			}
			env = env->next;
		}
		i++;
	}
}

void	export(t_data *data, char **args)
{
	t_env	*env;
	int		i;

	i = 0;
	while (args[i])
	{
		env = data->env;
		while (env)
		{
			if (!ft_strncmp(env->key, args[i], ft_strlen(args[i])))
			{
				env->value[0] = args[i + 1];
				break ;
			}
			env = env->next;
		}
		i++;
	}
}
