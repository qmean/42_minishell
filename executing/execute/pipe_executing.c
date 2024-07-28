/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_executing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 01:08:19 by kyumkim           #+#    #+#             */
/*   Updated: 2024/07/29 01:10:33 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executing.h"

void	do_pipe_cmd(t_line *line, t_cmd *cmd)
{
	pid_t	pid;
	t_cmd	*cur_cmd;
	t_cmd	*prev_cmd;
	int 	wait_status;

	initialize_pipe(line);
	prev_cmd = NULL;
	cur_cmd = cmd;
	while (cur_cmd != NULL)
	{
		pid = fork();
		if (pid == 0)
		{
			if (cur_cmd->input_file != 0)
				dup_pipe(cur_cmd, prev_cmd);
			else
				dup2(cur_cmd->pipe[1], STDOUT_FILENO);
			exec_cmd_pipe(line, cur_cmd);
		}
		cur_cmd = cur_cmd->next;
	}
	// pid = 마지막 자식 프로세스의 pid
	waitpid(pid, &wait_status, 0);
}

void	exec_cmd_pipe(t_line *line, t_cmd *cmd)
{
	int		cmd_def;
	char	**argv;
	char	**envp;

	cmd_def = isbuiltin(cmd);
	argv = cmd_to_argv(cmd);
	envp = env_to_envp(line->env);
	if (cmd_def)
		execute_builtin(line, cmd, cmd_def);
	else
		execute_bin(line, cmd, argv, envp);
	free_envp(envp);
	free_argv(argv);
}
