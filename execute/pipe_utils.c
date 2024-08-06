/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 19:35:26 by kyumkim           #+#    #+#             */
/*   Updated: 2024/08/07 01:13:28 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	initialize_pipe(t_line *line)
{
	t_cmd	*cmd;

	if (!line->pipe_flag)
		return ;
	cmd = line->first_cmd;
	while (cmd->next != NULL)
	{
		pipe(line->cmds->pipe);
		cmd = cmd->next;
	}
}

void	dup_pipe(t_cmd *cur_cmd, t_cmd *prev_cmd)
{
	if (prev_cmd == NULL)
	{
		dup2(cur_cmd->pipe[1], 1);
	}
	else if (cur_cmd->next != NULL)
	{
		dup2(prev_cmd->pipe[0], 0);
		dup2(cur_cmd->pipe[1], 1);
	}
	else
	{
		dup2(prev_cmd->pipe[0], 0);
		close(prev_cmd->pipe[0]);
	}
}
