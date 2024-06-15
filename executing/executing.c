/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuminkim <kyuminkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:11:50 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/18 22:08:50 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	exec_cmd(t_data *data, char *cmd, char **args);
char 	**env_to_char(t_env *env);
int		ft_env_size(t_env *env);
void	print_char_envp(char **envp);

char *check_and_put_path(char *dirPath, char *cmd);

void	execute(t_data *data, char *cmd, char **args, char **input)
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
		echo(args);
	else if (!ft_strcmp(cmd, "exit"))
		ft_exit(data, args);
	else if (!ft_strcmp(cmd, "pwd"))
		pwd();
	else
	{
		pid = fork();
		if (pid == 0)
			exec_cmd(data, cmd, input);
		else
		{
			waitpid(pid, &wait_status, 0);
		}
	}
}

void	exec_cmd(t_data *data, char *cmd, char **args)
{
	char		**paths;
	char		*path;
	char		**envp;
	int			i;

	i = 0;
	while (args[i] != NULL)
		printf("args[%d] = %s\n", i++, args[i]);
	paths = find_value("PATH", data);
	if (paths == NULL)
	{
		ft_putstr_fd("command not found\n", 2);
		exit(1);
	}
	i = 0;
	path = check_and_put_path(paths[i], cmd);
	while (paths[i] != NULL)
	{
		path = check_and_put_path(paths[i], cmd);
		if (path != NULL)
			break ;
		i++;
	}
	if (path == NULL)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(1);
	}
	envp = env_to_char(data->env);
	execve(path, args, envp);
}

char	*check_and_put_path(char *dirPath, char *cmd)
{
	DIR				*dir;
	struct dirent	*entry;
	char			*path;

	dir = opendir(dirPath);
	if (dir == NULL)
		return (NULL);
	entry = readdir(dir);
	while (entry != NULL)
	{
		if (!ft_strcmp(entry->d_name, cmd))
		{
			path = ft_strjoin(dirPath, "/");
			path = ft_strjoin(path, cmd);
			return (path);
		}
		entry = readdir(dir);
	}
	return (NULL);
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
