/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeniz.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 00:45:53 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/12 04:36:30 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void tokenize_main(char *line, t_cmd *cmd)
{
    int i;
    
    i = 0;
    while (line[i])
    {
        check_quote(line, cmd, &i); // 따옴표 검사
        check_pipe(line, cmd, &i); // 파이프 검사
        check_escape(line, cmd, &i); // 이스케이프 검사
        //     continue;
        check_semicolon(line, cmd, &i); // 세미콜론 검사
        //     continue;
    //     else 
    if (line[i] == ' ')
        {
            while (line[i] == ' ')
                i++;
    //         // if (line[i] == '<' || line[i] == '>')
    //         //     check_redir(line, cmd, &i);
            if (cmd->quote == 0)
                add_token(cmd);
        }
            
    //     // else if (line[i] == '$')
    //     // {
            
    //     // }
        // else
            cmd->buf = ft_strjoin_free(cmd->buf, line[i]);
        i++;
    }
        if (line[i] == '\0')
            add_token(cmd);
    if (cmd->quote != 0) // 따옴표가 닫히지 않은 경우
        error_invalid_quote();
    print_cmd(cmd);
}