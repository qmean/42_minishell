/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_executing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 01:10:51 by kyumkim           #+#    #+#             */
/*   Updated: 2024/07/29 01:11:09 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executing.h"

void	do_normal_cmd(t_line *line, t_cmd *cmd)
{
	int		cmd_def;
	int		status;
	pid_t	pid;
	char	**argv;
	char	**envp;

	cmd_def = isbuiltin(cmd);
	argv = cmd_to_argv(cmd);
	envp = env_to_envp(line->env);
	if (cmd_def)
		execute_builtin(line, cmd, cmd_def);
	else
	{
		pid = fork();
		if (pid == -1)
			print_error(cmd->first_token->data, NULL, "fork error");
		else if (pid == 0)
			execute_bin(line, cmd, argv, envp);
		else
		{
			waitpid(pid, &status, 0);
			if (WIFEXITED(status))
				line->exit_flag = WEXITSTATUS(status);
		}
	}
	free_envp(envp);
	free_argv(argv);
}
