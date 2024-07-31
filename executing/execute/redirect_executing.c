/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_executing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 01:14:10 by kyumkim           #+#    #+#             */
/*   Updated: 2024/07/31 11:05:28 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executing.h"

int	do_heredoc(t_line *line, t_cmd *cmd);

void	do_redirect_cmd(t_line *line, t_cmd *cmd)
{
	if (cmd->input_file == -2 && cmd->output_file == -2)
		return ;
	if (cmd->input_file >= 0)
		dup2(cmd->input_file, STDIN_FILENO);
	if (cmd->output_file > 0)
		dup2(cmd->output_file, STDOUT_FILENO);
	if (cmd->output_file == 0)
		exit(do_heredoc(line, cmd));
}

int	do_heredoc(t_line *line, t_cmd *cmd)
{
	pid_t	pid;
	int		pipe_fd[2];
	int		exit_status;
	char	*heredoc_line;

	pipe(pipe_fd);
	pid = fork();
	if (pid == -1)
	{
		print_error(cmd->first_token->data, NULL, "fork error");
		exit(1);
	}
	else if (pid == 0)
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		do_pipe_cmd(line, cmd);
		exit(line->exit_flag);
	}
	else
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		while (1)
		{
			heredoc_line = readline("> ");
			if (strcmp(heredoc_line, cmd->heredoc_str) == 0)
				break ;
			write(pipe_fd[1], heredoc_line, ft_strlen(heredoc_line));
			write(pipe_fd[1], "\n", 1);
		}
		waitpid(pid, &exit_status, 0);
	}
	return (exit_status);
}