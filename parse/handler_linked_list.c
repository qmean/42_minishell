/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_linked_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:33:40 by jaemikim          #+#    #+#             */
/*   Updated: 2024/08/07 04:05:41 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_token(t_cmd *cmd)
{
	t_token	*new_token;

	if (cmd->tokens->data == NULL)
	{
		cmd->tokens->data = cmd->buf;
	}
	else
	{
		new_token = make_token();
		cmd->tokens->next = new_token;
		new_token->prev = cmd->tokens;
		cmd->tokens = new_token;
		cmd->tokens->data = cmd->buf;
	}
	cmd->buf = NULL;
}

void	add_cmd(t_line *lines)
{
	if (lines->cmds == NULL)
	{
		lines->cmds = make_cmd();
		lines->first_cmd = lines->cmds;
		lines->cmds->tokens = make_token();
		lines->cmds->first_token = lines->cmds->tokens;
		return ;
	}
	lines->cmds->next = make_cmd();
	lines->cmds = lines->cmds->next;
}

void	free_cmd(t_line *lines)
{
	t_cmd	*tmp;
	t_cmd	*free_cmd;

	free_cmd = lines->first_cmd;
	while (free_cmd)
	{
		tmp = free_cmd->next;
		free_token(free_cmd->first_token);
		free(free_cmd->buf);
		if (free_cmd->heredoc_str != NULL)
			free(free_cmd->heredoc_str);
		free(free_cmd);
		free_cmd = tmp;
	}
	lines->cmds = NULL;
	lines->first_cmd = NULL;
	lines->pipe_flag = 0;
}

void	free_token(t_token *token)
{
	t_token	*tmp;
	t_token	*free_token;

	tmp = token;
	free_token = tmp;
	while (free_token)
	{
		tmp = free_token->next;
		free(free_token->data);
		free(free_token);
		free_token = tmp;
	}
}
