/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 01:53:41 by jaemikim          #+#    #+#             */
/*   Updated: 2024/08/06 15:45:57 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int check_syntax(t_line *lines)
{
	t_cmd *cmd;
	t_token *token;
	t_token *tmp;
	int ret;

	cmd = lines->first_cmd;
	while (cmd)
	{
		token = cmd->first_token;
		if ((token->data == NULL) && (lines->pipe_flag == 1))
			return (error_syntax("|"));
			ret = check_redir_token(cmd, token);
			if (ret == -1)
				return (ret);
		remove_redir_token(cmd->first_token);
		cmd = cmd->next;
		if (lines->pipe_flag == 1)
		{
			if ((cmd != NULL) && (cmd->first_token->data == NULL))
				return (error_syntax("newline"));
		}
	}
	return (0);
}

void	remove_redir_token(t_token *token)
{
	t_token	*tmp;
	t_token	*free_token;

	while (token)
	{
		if (token->redir != 0)
		{
			tmp = token;
			while (tmp->redir != 0)
				tmp = tmp->next;
			while ((tmp->prev != NULL) && (tmp->prev->redir != 0))
			{
				tmp = tmp->prev;
				free_token = tmp->next;
				if (tmp->next->next != NULL)
					remove_redir_token_move(tmp);
				else
					tmp->next = NULL;
				free(free_token->data);
				free(free_token);
			}
		}
		token = token->next;
	}
}

void remove_redir_token_move(t_token *tmp)
{
	tmp->next = tmp->next->next;
	tmp->next->prev = tmp;
}


int	check_redir_token(t_cmd *cmd, t_token *token) {
	while (token) {
		if (token->redir != 0) {
			if (token->next == NULL)
				return (error_syntax(""));
			else if (token->redir == 1)
			{
				if (input_redirection(cmd, token))
					return (-1);
			}
			else if (token->redir == 2)
			{
				if (input_heredoc_redirection(cmd, token))
					return (-1);
			}
			else if (token->redir == 3)
			{
				if (output_redirection(cmd, token))
					return (-1);
			}
			else if (token->redir == 4)
			{
				if (output_append_redirection(cmd, token))
					return (-1);
			}
		}
		token = token->next;
	}
	return (0);
}
