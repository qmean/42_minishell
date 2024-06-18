/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeniz.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 00:45:53 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/19 03:49:15 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// TODO : 에러가 날 경우 그대로 라인을 넘겨주도록 변경

void tokenize_main(char *line, t_line *lines)
{
    int i;
    
    i = 0;
    while (line[i])
    {
        if (check_quote(line, lines->cmds, &i)) // 따옴표 검사
            continue;
        else if (check_space(line, lines->cmds, &i)) // 공백 검사
            continue;
        else if (check_pipe(line, lines, &i)) // 파이프 검사
            continue;
        else if (check_semicolon(line, lines, &i)) // 세미콜론 검사
            continue;
        else if (check_escape(line, lines, &i)) // 이스케이프 검사
            continue;
        else if (check_env(line, lines, &i))
            continue;
        else
            lines->cmds->buf = ft_strjoin_free(lines->cmds->buf, line[i]);
        i++;
    }
    if (lines->cmds->quote != 0) // 따옴표가 닫히지 않은 경우
        error_invalid_quote();
    if ((line[i] == '\0') && (lines->cmds->buf != NULL)) // 라인이 끝나고 버퍼에 내용이 있으면 토큰으로 추가
        lines->cmds->tokens->data = lines->cmds->buf;
    print_cmd(lines->first_cmd);
}