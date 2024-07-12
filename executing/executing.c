/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuminkim <kyuminkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:11:50 by kyumkim           #+#    #+#             */
/*   Updated: 2024/07/12 15:05:44 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	exec_cmd(t_line *line, t_cmd *cmd);
void	execute_builtin(t_line *line, t_cmd *cmd, int cmd_def);
char	*check_and_put_path(char *dir_path, char *cmd);
char	**cmd_to_argv(t_cmd *cmd);
char	**env_to_envp(t_env *env);
void	exec_pipe_cmd(t_line *line, t_cmd *cmd, int pipe_idx);

void	execute(t_line *line)
{
	t_cmd	*cmd;
	int		idx;
	int 	pipe;

	idx = 0;
	cmd = line->first_cmd;
	pipe = cmd->pipe_flag;
	while (cmd)
	{
		if (!pipe)
			exec_cmd(line, cmd);
		else
			exec_pipe_cmd(line, cmd, idx % 2);
		cmd = cmd->next;
		idx++;
	}
	if (pipe)
	{
		while (idx--)
			wait(NULL);
	}
}

void exec_pipe_cmd(t_line *line, t_cmd *cmd, int pipe_idx)
{
	int		pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (pipe_idx >= 0)
		{
			dup2(STDIN_FILENO, line->pipe[pipe_idx][0]);
		}
		if (cmd->next != NULL)
			dup2(STDOUT_FILENO, line->pipe[1 - pipe_idx][1]);
		exec_cmd(line, cmd);
		// todo : 에러 처리 로직 추가
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd->first_token->data, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		exit(126);
	}
	else
	{
		waitpid(pid, &status, 0);
			close(line->pipe[pipe_idx][0]);
			close(line->pipe[1 - pipe_idx][1]);
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
	if (cmd->pipe_flag)
	{
		exit(line->exit_flag);
	}
}

void	execute_bin(t_line *line, t_cmd *cmd)
{
	char	*path;
	char	**argv;
	char	**envp;
	char	**values;
	int		pid;
	int		status;

	path = NULL;
	values = value_split(find_value(line, "PATH"));
	while (*values)
	{
		path = check_and_put_path(*values, cmd->first_token->data);
		if (path != NULL)
			break ;
		values++;
	}
	if (path == NULL)
	{
		// todo : 에러 처리 로직 추가
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
		// todo : 에러 처리 로직 추가
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

	envp = (char **)malloc(sizeof(char *) * (env_size(env) + 1));
	if (envp == NULL)
		exit(1); // todo : 에러 처리 추가
	idx = 0;
	iter = env;
	while (iter != NULL)
	{
		envp[idx] = ft_strjoin(iter->key, "=");
		// todo : free 해줘야 함
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
	while (token != NULL && token->data != NULL)
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
