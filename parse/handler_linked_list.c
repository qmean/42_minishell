/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_linked_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:33:40 by jaemikim          #+#    #+#             */
/*   Updated: 2024/08/07 01:13:35 by kyumkim          ###   ########.fr       */
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
	lines->cmds->next = make_cmd();
	lines->cmds = lines->cmds->next;
	lines->cmds->tokens = make_token();
	lines->cmds->first_token = lines->cmds->tokens;
}

void	free_cmd(t_line *lines)
{
	t_cmd	*tmp;

	lines->cmds = lines->first_cmd;
	while (lines->cmds)
	{
		tmp = lines->cmds->next;
		free_token(lines->cmds->first_token);
		free(lines->cmds);
		lines->cmds = tmp;
	}
	lines->cmds = NULL;
	lines->first_cmd = NULL;
	lines->pipe_flag = 0;
}

void	free_token(t_token *token)
{
	t_token	*tmp;

	while (token)
	{
		tmp = token->next;
		free(token->data);
		free(token);
		token = tmp;
	}
}
