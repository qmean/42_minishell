/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student42.ac.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 01:53:41 by jaemikim          #+#    #+#             */
/*   Updated: 2024/07/01 00:36:00 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		check_syntax(t_line *lines)
{
	t_cmd	*cmd;
	t_token	*token;
	t_token *tmp;

	cmd = lines->first_cmd;
	while (cmd)
	{
		token = cmd->first_token;
		if ((token->data == NULL) && (lines->pipe_flag == 1)) // 공백 | 예외처리
			return (error_syntax("|"));
		while (token)
		{
			if (token->redir != 0)
			{
				if (token->next == NULL) // 리다이렉션 뒤에 아무것도 없는 경우
					return (error_syntax(""));
				else if (token->redir == 1) {
					if (input_redirection(cmd, token))
						return (-1);
				}
				else if (token->redir == 2) {
					if (input_heredoc_redirection(cmd, token))
						return (-1);
				}
				else if (token->redir == 3) {
					if (output_redirection(cmd, token))
						return (-1);
				}
				else if (token->redir == 4) {
					if (output_append_redirection(cmd, token))
						return (-1);
				}
			}
			token = token->next;
		}
		remove_redir_token(cmd->first_token);
		cmd = cmd->next;
		if (lines->pipe_flag == 1)
		{
			if ((cmd != NULL) && (cmd->first_token->data == NULL)) // |뒤 공백 예외처리
				return (error_syntax("newline"));
		}
	}
	return (0);
}

void	remove_redir_token(t_token *token)
{
	t_token *tmp;
	t_token *free_token;

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
				{
					tmp->next = tmp->next->next;
					tmp->next->prev = tmp;
				}
				else
					tmp->next = NULL;
				free(free_token->data);
				free(free_token);
			}
		}
		token = token->next;
	}
}