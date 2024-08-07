/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_executing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 01:08:19 by kyumkim           #+#    #+#             */
/*   Updated: 2024/08/07 05:19:31 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	close_all_pipe(t_line *line);
void	handle_last_cmd(t_line *line, pid_t pid);

void	do_pipe_cmd(t_line *line, t_cmd *cur_cmd, t_cmd *prev_cmd)
{
	pid_t	pid;

	if (cur_cmd == NULL)
		return ;
	pipe(cur_cmd->pipe);
	pid = fork();
	if (pid == 0)
	{
		if (cur_cmd->input_file == 0)
			do_heredoc(cur_cmd);
		dup_pipe(cur_cmd, prev_cmd);
		do_redirect_cmd(cur_cmd);
		exec_cmd_pipe(line, cur_cmd);
		exit(line->exit_flag);
	}
	else if (pid == -1)
		print_error(cur_cmd->first_token->data, NULL, "fork error");
	else
	{
		if (cur_cmd->next == NULL)
			handle_last_cmd(line, pid);
		waitpid(pid, NULL, 0);
		close(cur_cmd->pipe[1]);
		do_pipe_cmd(line, cur_cmd->next, cur_cmd);
	}
}

void	handle_last_cmd(t_line *line, pid_t pid)
{
	int	wait_status;

	close_all_pipe(line);
	waitpid(pid, &wait_status, 0);
	if (WIFEXITED(wait_status))
		line->exit_flag = WEXITSTATUS(wait_status);
}

void	close_all_pipe(t_line *line)
{
	t_cmd	*cmd;

	cmd = line->first_cmd;
	while (cmd != NULL)
	{
		close(cmd->pipe[0]);
		cmd = cmd->next;
	}
}

void	exec_cmd_pipe(t_line *line, t_cmd *cmd)
{
	int		cmd_def;
	char	**argv;
	char	**envp;

	cmd_def = isbuiltin(cmd);
	if (cmd_def)
		execute_builtin(line, cmd, cmd_def);
	else
	{
		argv = cmd_to_argv(cmd);
		envp = env_to_envp(line->env);
		execute_bin(line, cmd, argv, envp);
		free_envp(envp);
		free_argv(argv);
	}
}
