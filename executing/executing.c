/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuminkim <kyuminkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:11:50 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/16 01:18:01 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void echo(char **pString, char **pString1);
int	export(t_data *data, char **args);
void	exec_cmd(t_data *data, char *cmd, char **args);
void	unset(t_data *data, char **args);
char 	**env_to_char(t_env *env);
int		ft_env_size(t_env *env);
void	print_char_envp(char **envp);

void	execute(t_data *data, char *cmd, char **args)
{
	int	pid;
	int wait_status;

	if (!ft_strcmp(cmd, "env"))
		env(data);
	else if (!ft_strcmp(cmd, "cd"))
		cd(data, args);
	else if (!ft_strcmp(cmd, "export"))
		export(data, args);
	else if (!ft_strcmp(cmd, "unset"))
		unset(data, args);
	else if (!ft_strcmp(cmd, "echo"))
		echo(args, args);
	else if (!ft_strcmp(cmd, "exit"))
		exit(0);
	else if (!ft_strcmp(cmd, "pwd"))
		pwd();
	else
	{
		pid = fork();
		if (pid == 0)
			exec_cmd(data, cmd, args);
		else
		{
			waitpid(pid, &wait_status, 0);
			if (WIFEXITED(wait_status))
				printf("======exit status = %d=======\n", WEXITSTATUS(wait_status));
			else
				printf("======exit status = %d=======\n", WEXITSTATUS(wait_status));
		}
	}
}

void	exec_cmd(t_data *data, char *cmd, char **args)
{
	char		**paths;
	char		*path;
	char		**new_args;
	char		**envp;
	struct stat	*buf;

	paths = find_value("PATH", data);
	if (paths == NULL)
	{
		ft_putstr_fd("command not found\n", 2);
		return ;
	}
	new_args = (char **)malloc(sizeof(char *) * value_len(args) + 2);
	int idx = 0;
	new_args[idx++] = NULL;
	while (args[idx - 1])
	{
		new_args[idx] = args[idx - 1];
		idx++;
	}
	new_args[idx] = NULL;
	while (*paths)
	{
		path = ft_strjoin(*paths, "/");
		path = ft_strjoin(path, cmd);
		new_args[0] = path;
		envp = env_to_char(data->env);
		if (open(path, O_RDONLY) != -1)
		{
			idx = 0;
			while (new_args[idx])
			{
				printf("new_args[%d] = %s\n", idx, new_args[idx]);
				idx++;
			}
			if (execve(path, new_args, envp) == -1)
				exit(1);
		}
		else
		{
			paths++;
		}
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
	envp = (char **)malloc(sizeof(char *) * (ft_env_size(env) + 1));
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

int		ft_env_size(t_env *env)
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
