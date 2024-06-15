/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeniz.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jammin <jammin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 00:45:53 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/14 04:10:03 by jammin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
        // if (check_semicolon(line, lines->cmds, &i)) // 세미콜론 검사
        //     continue;
        // check_escape(line, cmd, &i); // 이스케이프 검사
        //     continue;
        else
            lines->cmds->buf = ft_strjoin_free(lines->cmds->buf, line[i]);
        i++;
    }
    if (lines->cmds->quote != 0) // 따옴표가 닫히지 않은 경우
        error_invalid_quote();
    if ((line[i] == '\0') && (lines->cmds->buf != NULL)) // 라인이 끝나고 버퍼에 내용이 있으면 토큰으로 추가
        add_token(lines->cmds);
    print_cmd(lines->first_cmd);
}