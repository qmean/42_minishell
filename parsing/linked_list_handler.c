/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jammin <jammin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:33:40 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/14 03:59:42 by jammin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	add_token(t_cmd *cmd)
{
    cmd->tokens->data = cmd->buf; // 토큰 저장
    cmd->tokens->next = make_token();
    cmd->tokens = cmd->tokens->next; // 새로운 토큰 생성 후 이동
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
}

void	free_token(t_token *token)
{
    t_token *tmp;

    while (token)
    {
        tmp = token->next;
		free(token->data);
        free(token);
        token = tmp;
    }
}