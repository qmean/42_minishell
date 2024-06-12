/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:33:40 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/12 12:01:45 by jaemikim         ###   ########.fr       */
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

void	add_cmd(t_cmd *cmd)
{
	cmd->next = make_cmd();
	cmd = cmd->next;
	cmd->tokens = make_token();
	cmd->first_token = cmd->tokens;
}

void	free_cmd(t_cmd *cmd)
{
    t_cmd	*tmp;

    while (cmd)
    {
        tmp = cmd->next;
        free_token(cmd->first_token);
        free(cmd);
        cmd = tmp;
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