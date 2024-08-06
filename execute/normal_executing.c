/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_executing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 01:10:51 by kyumkim           #+#    #+#             */
/*   Updated: 2024/08/07 01:13:28 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	normal_execute_bin(char **argv, char **envp, t_line *line, t_cmd *cmd);

void	do_normal_cmd(t_line *line, t_cmd *cmd)
{
	int		cmd_def;
	char	**argv;
	char	**envp;

	do_redirect_cmd(cmd);
	cmd_def = isbuiltin(cmd);
	if (cmd_def)
		execute_builtin(line, cmd, cmd_def);
	else
	{
		argv = cmd_to_argv(cmd);
		envp = env_to_envp(line->env);
		normal_execute_bin(argv, envp, line, cmd);
		free_argv(argv);
		free_envp(envp);
	}
}

void	normal_execute_bin(char **argv, char **envp, t_line *line, t_cmd *cmd)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		print_error(cmd->first_token->data, NULL, "fork error");
	else if (pid == 0)
		execute_bin(line, cmd, argv, envp);
	else
	{
		close(cmd->input_file);
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			line->exit_flag = WEXITSTATUS(status);
	}
}
