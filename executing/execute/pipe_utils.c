/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 19:35:26 by kyumkim           #+#    #+#             */
/*   Updated: 2024/07/28 23:30:42 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executing.h"

void	initialize_pipe(t_line *line)
{
	int 	idx;
	t_cmd	*cmd;

	if (!line->pipe_flag)
		return ;
	idx = 0;
	cmd = line->first_cmd;
	while (cmd->next == NULL)
	{
		pipe(line->cmds[idx].pipe);
		cmd = cmd->next;
	}
}

void	dup_pipe(t_cmd *cur_cmd, t_cmd *prev_cmd)
{
	if (prev_cmd == NULL)
	{
		dup2(cur_cmd->pipe[1], STDOUT_FILENO);
	}
	else if (cur_cmd->next == NULL)
	{
		dup2(prev_cmd->pipe[0], STDIN_FILENO);
		dup2(cur_cmd->pipe[1], STDOUT_FILENO);
	}
	else
	{
		dup2(prev_cmd->pipe[0], STDIN_FILENO);
	}
}