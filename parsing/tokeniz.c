/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeniz.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 00:45:53 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/10 05:18:25 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void tokenize_main(char *line, t_cmd *cmd)
{
    int i;
    
	init(cmd);
    i = 0;
    while (line[i])
    {
        check_quote(line, cmd, i); // 따옴표 검사
        if (check_pipe(line, cmd, i))
            cmd = cmd->next;
        else if (line[i] == ';')
        {
            cmd->pipe_flag = 2;
            if (!cmd->buf)
                error_syntax(';');
            else
                add_token(cmd, cmd->buf);
        }
        else if (line[i] == ' ')
        {
            if (cmd->quote == 0)
                add_token(cmd, cmd->buf);
        }
        else
            cmd->buf = ft_strjoin_free(cmd->buf, line[i]);
        i++;
    }
    if (cmd->quote != 0) // 따옴표가 닫히지 않은 경우
        error_invalid_quote();
}

void add_token(t_cmd *cmd, char *buf)
{
    cmd->tokens->data = buf; // 토큰 저장
    cmd->tokens->next = make_token();
    cmd->tokens = cmd->tokens->next; // 새로운 토큰 생성 후 이동
    cmd->buf = NULL; // 버퍼 초기화
}

void check_quote(char *line, t_cmd *cmd, int i)
{
    check_smallquote(line, cmd, i);
    check_bigquote(line, cmd, i);
}

void check_smallquote(char *line, t_cmd *cmd, int i)
{
    if (line[i] == '\'')
    {
        if (cmd->quote == 0)
            cmd->quote = '\'';
        else if (cmd->quote == '\'')
        {
            cmd->quote = 0;
            add_token(cmd, cmd->buf);
        }
    }
}

void check_bigquote(char *line, t_cmd *cmd, int i)
{
    if (line[i] == '\"')
    {
        if (cmd->quote == 0)
            cmd->quote = '\"';
        else if (cmd->quote == '\"')
        {
            cmd->quote = 0;
            add_token(cmd, cmd->buf);
        }
    }
}

int check_pipe(char *line, t_cmd *cmd, int i)
{
    if (line[i] == '|')
    {
        if (cmd->quote == 0)
        {
            cmd->pipe_flag = 1;
            line[i] = '\0';
            cmd->next = make_cmd();
            return (1);
        }
    }
    return (0);
}