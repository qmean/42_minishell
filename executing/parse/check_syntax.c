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

	cmd = lines->first_cmd;
	while (cmd)
	{
		token = cmd->first_token;
		while (token)
		{
			// if ((token->next != NULL) && (token->next->redir != 0))
			// 	make_redir_token(token, token->next);
			if (cmd->next != NULL) {
				if ((cmd->next->tokens->redir != 0) && (token->pipe_flag == 1))
					return (error_syntax("pipe and redirection"));
			}
				// if ((cmd->tokens->redir != 0) && (cmd->tokens->pipe_flag == 1))
			// 	return (error_syntax("pipe and redirection"));

			token = token->next;
		}
		cmd = cmd->next;
	}
	return (0);
}