/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:11:44 by jaemikim          #+#    #+#             */
/*   Updated: 2024/07/28 19:37:24 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int check_escape(char *line, t_line *lines, int *i) {
	if (line[*i] == '\\') {
		if (lines->cmds->quote == 0) // 따옴표가 없는 경우
		{
			*i += 1;
			if (line[*i] == '\0') // 뒤에 아무것도 없는 경우 에러처리     뭐가 있으면 \만 뺴고 버퍼에 넣어서 사용
				error_syntax("'\0'");
		} else if (lines->cmds->quote == '\"') {
			if (line[*i + 1] == '\0')
				error_syntax("'\0'");
			else if (line[*i + 1] == '\"') {
				lines->cmds->buf = ft_strjoin_free(lines->cmds->buf, '\"');
				*i += 2;
				return (1);
			} else if (line[*i + 1] == '\\') {
				*i += 1;
				return (0);
			}
		}
	}
	return (0);
}

int check_semicolon(char *line, t_line *lines, int *i) {
	if (line[*i] == ';') {
		if (lines->cmds->quote == 0) {
			lines->cmds->pipe_flag = 2; // 파이프 플래그 설정
			line[*i] = '\0'; // 라인을 끊은 뒤 명령어 뭉치로 저장
			if (lines->cmds->buf != NULL) // 버퍼에 내용이 있으면 토큰으로 추가
				add_token(lines->cmds);
			add_cmd(lines); // 새로운 명령어 뭉치 생성
			*i += 1;
			if (line[*i] == '|') // 파이프가 나오는 경우
			{
				if (line[*i + 1] == '|') // ||이면 ||로 에러 처리
					return (error_syntax("||"));
				return (error_syntax("|")); // |이면 |로 에러 처리
			}
			if (line[*i] == ';') // ;|이면 에러 처리
				return (error_syntax(";;"));
			return (1);
		}
		// 따옴표가 열려있는 경우 버퍼에 추가
	}
	return (0);
}

int check_space(char *line, t_cmd *cmd, int *i) {
	if (line[*i] == ' ') {
		if (cmd->quote == 0) // 따옴표가 열려있지 않은 경우
		{
			if (cmd->buf != NULL) // 버퍼에 내용이 있으면 토큰으로 추가 없으면 넘어감
			{
				cmd->tokens->isspace = 1; // 마지막에 space로 토큰을 나누었을 경우
				add_token(cmd);
			}
			*i += 1;
			return (1);
		}
	}
	return (0); // 따옴표가 열려있는 경우 버퍼에 추가
}