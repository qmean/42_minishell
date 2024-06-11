/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:33:40 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/12 04:15:11 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void add_token(t_cmd *cmd)
{
    cmd->tokens->data = cmd->buf; // 토큰 저장
    cmd->tokens->next = make_token();
    cmd->tokens = cmd->tokens->next; // 새로운 토큰 생성 후 이동
    cmd->buf = NULL;
}

void add_cmd(t_cmd *cmd)
{
	cmd->next = make_cmd();
	cmd = cmd->next;
	cmd->tokens = make_token();
	cmd->first_token = cmd->tokens;
}