/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuminkim <kyuminkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:11:50 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/19 03:51:01 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	exec_cmd(t_line *line, t_cmd *cmd);
void	execute_builtin(t_line *line, t_cmd *cmd, int cmd_def);
int		isbuiltin(t_cmd *cmd);
void	execute_bin(t_line *line, t_cmd *cmd);
char	*check_and_put_path(char *dir_path, char *cmd);
char	**cmd_to_argv(t_cmd *cmd);
char	**env_to_envp(t_env *env);

void	execute(t_line *line)
{
	t_cmd	*cmd;

	cmd = line->first_cmd;
	while (cmd)
	{
		exec_cmd(line, cmd);
		cmd = cmd->next;
	}
}

void	exec_cmd(t_line *line, t_cmd *cmd)
{
	int	is_builtin;

	is_builtin = isbuiltin(cmd);
	if (is_builtin)
		execute_builtin(line, cmd, is_builtin);
	else
		execute_bin(line, cmd);
}

void	execute_bin(t_line *line, t_cmd *cmd)
{
	char	*path;
	char	**argv;
	char	**envp;
	int		pid;
	int		status;

	path = check_and_put_path(line->env->value, cmd->first_token->data);
	if (path == NULL)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd->first_token->data, 2);
		ft_putstr_fd(": command not found\n", 2);
		line->exit_flag = 127;
		return ;
	}
	argv = cmd_to_argv(cmd);
	pid = fork();
	envp = env_to_envp(line->env);
	if (pid == 0)
	{
		execve(path, argv, envp);
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd->first_token->data, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		exit(126);
	}
	waitpid(pid, &status, 0);
	line->exit_flag = WEXITSTATUS(status);
	free(path);
	free(argv);
}

char	**env_to_envp(t_env *env)
{
	char	**envp;
	t_env	*iter;
	int		idx;

	iter = env;
	idx = 0;
	while (iter != NULL)
	{
		idx++;
		iter = iter->next;
	}
	envp = (char **)malloc(sizeof(char *) * (idx + 1));
	if (envp == NULL)
		exit(1); // todo : 에러 처리 추가
	idx = 0;
	iter = env;
	while (iter != NULL)
	{
		envp[idx] = ft_strjoin(iter->key, "=");
		envp[idx] = ft_strjoin(envp[idx], iter->value);
		if (envp[idx] == NULL)
			exit(1); // todo : 에러 처리 추가
		idx++;
		iter = iter->next;
	}
	envp[idx] = NULL;
	return (envp);
}

char	**cmd_to_argv(t_cmd *cmd)
{
	t_token	*token;
	char	**argv;
	int		idx;

	argv = (char **)malloc(sizeof(char *) * (token_size(cmd->tokens) + 1));
	if (argv == NULL)
		exit(1); // todo : 에러 처리 추가
	idx = 0;
	token = cmd->first_token;
	while (token != NULL)
	{
		argv[idx] = ft_strdup(token->data);
		if (argv[idx] == NULL)
			exit(1); // todo : 에러 처리 추가
		idx++;
		token = token->next;
	}
	argv[idx] = NULL;
	return (argv);
}

void	execute_builtin(t_line *line, t_cmd *cmd, int cmd_def)
{
	if (cmd_def == BCD)
		cd(line, cmd);
	else if (cmd_def == BECHO)
		echo(line, cmd->first_token->next);
	else if (cmd_def == BENV)
		env(line, cmd->first_token->next);
	else if (cmd_def == BEXPORT)
		export(line, cmd->first_token->next);
	else if (cmd_def == BPWD)
		pwd(line);
	else if (cmd_def == BUNSET)
		unset(line, cmd->first_token->next);
	else if (cmd_def == BEXIT)
		ft_exit(line, cmd->first_token->next);
}

int	isbuiltin(t_cmd *cmd)
{
	if (!ft_strcmp(cmd->first_token->data, "cd"))
		return (BCD);
	if (!ft_strcmp(cmd->first_token->data, "echo"))
		return (BECHO);
	if (!ft_strcmp(cmd->first_token->data, "env"))
		return (BENV);
	if (!ft_strcmp(cmd->first_token->data, "export"))
		return (BEXPORT);
	if (!ft_strcmp(cmd->first_token->data, "pwd"))
		return (BPWD);
	if (!ft_strcmp(cmd->first_token->data, "unset"))
		return (BUNSET);
	return (0);
}

char	*check_and_put_path(char *dir_path, char *cmd)
{
	DIR				*dir;
	struct dirent	*entry;
	char			*path;

	dir = opendir(dir_path);
	if (dir == NULL)
		return (NULL);
	entry = readdir(dir);
	while (entry != NULL)
	{
		if (!ft_strcmp(entry->d_name, cmd))
		{
			path = ft_strjoin(dir_path, "/");
			path = ft_strjoin(path, cmd);
			return (path);
		}
		entry = readdir(dir);
	}
	return (NULL);
}
