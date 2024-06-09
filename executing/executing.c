/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:11:50 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/08 21:36:46 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void echo(char **pString, char **pString1);
void	export(t_data *data, char **args);
void	exec_cmd(t_data *data, char *cmd, char **args);
void	unset(t_data *data, char **args);
char 	**env_to_char(t_env *env);
int		env_size(t_env *env);
void	print_char_envp(char **envp);

//todo: strcmp -> ft_strcmp
void	execute(t_data *data, char *cmd, char **args)
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
}

void	exec_cmd(t_data *data, char *cmd, char **args)
{
	char	**paths;
	char	*path;
	char	**envp;

	paths = find_value("PATH", data);
	if (paths == NULL)
	{
		ft_putstr_fd("command not found\n", 2);
		return ;
	}
	while (*paths)
	{
		path = ft_strjoin(*paths, "/");
		path = ft_strjoin(path, cmd);
		envp = env_to_char(data->env);
//		print_char_envp(envp);
		if (execve(path, args, envp) == -1)
		{
			paths++;
		}
		else
			break ;
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

char	**env_to_char(t_env *env)
{
	char	**envp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	envp = (char **)malloc(sizeof(char *) * (env_size(env) + 1));
	env = env->next;
	while (env)
	{
		envp[j] = ft_strjoin(env->key, "=");
		i = 0;
		while (env->value[i] != NULL)
			envp[j] = ft_strjoin(envp[j], env->value[i++]);
		j++;
		env = env->next;
	}
	envp[j] = NULL;
	return (envp);
}

int		env_size(t_env *env)
{
	int		i;

	i = 0;
	while (env)
	{
		i++;
		env = env->next;
	}
	return (i);
}

void	print_char_envp(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		printf("envp[%d] = %s\n", i, envp[i]);
		i++;
	}
}