/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jammin <jammin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:11:44 by jaemikim          #+#    #+#             */
/*   Updated: 2024/07/07 16:02:50 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int check_pipe(char *line, t_line *lines, int *i) {
	if (line[*i] == '|') {
		if (lines->cmds->quote == 0) {
			line[*i] = '\0'; // 라인을 끊은 뒤 명령어 뭉치로 저장
			if (lines->cmds->buf != NULL) // 버퍼에 내용이 있으면 토큰으로 추가
				add_token(lines->cmds);
			lines->pipe_flag = 1; // 파이프 플래그 설정
			add_cmd(lines); // 새로운 명령어 뭉치 생성
			*i += 1;
			if (line[*i] == '|') // 파이프 연속으로 나오는 경우
			{
				if ((line[*i + 2] == '|') && (line[*i + 1] == '|')) // ||||이면 ||로 에러 처리
					return (error_syntax("||"));
				if (line[*i + 1] == '|') // |||이면 |로 에러 처리
					return (error_syntax("|"));
				*i += 1; // ||이면 다음으로 넘어감
			}
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

int check_redir(char *line, t_line *lines, int *i)
{
	int	ret;

	ret = check_redir_right(line, lines, i);
	if (ret != 0)
		return (ret);
	ret = check_redir_left(line, lines, i);
	return (ret);
}

int	check_redir_right(char *line, t_line *lines, int *i)
{
	if ((lines->pipe_flag == 0) && (line[*i] == '>'))
	{
		*i += 1;
		if (lines->cmds->buf != NULL)
			add_token(lines->cmds); // 리다이렉션 앞부분을 토큰으로 분리
		lines->cmds->tokens->redir = 1; // 리다이렉션 플래그 설정
		if (line[*i] == '>')
		{
			*i += 1;
			lines->cmds->tokens->redir = 2; // 리다이렉션 플래그 설정
			if (line[*i] == '>')
			{
				if (line[*i + 1] == '>')
					return (error_syntax(">>")); // >>>> 에러 처리
				if (line[*i + 1] == '|')
					return (error_syntax(">|")); // >>>| 에러 처리
				return (error_syntax(">")); // >>> 에러 처리
			}
			if (line[*i] == '|') // >>| 에러 처리
				return (error_syntax("|"));
		}
		if (line[*i] == '<') // >< 에러 처리
		{
			*i += 1;
			if (line[*i] == '<') // ><< 에러 처리
			{
				while (line[*i] == ' ')
					*i += 1;
				if (line[*i + 1] == '<') // ><<< 에러 처리
					return (error_syntax("<<<"));
				return (error_syntax("<<"));
			}
			if (line[*i] == '>') // ><> 에러 처리
				return (error_syntax("<>"));
			return (error_syntax("<"));
		}

		if (line[*i] == '|') // >| 에러 처리 -> newline
			return (error_syntax(""));
		return (1);
	}
	return (0);
}

int	check_redir_left(char *line, t_line *lines, int *i)
{
	if ((lines->cmds->quote == 0) && (line[*i] == '<'))
	{
		*i += 1;
		if (lines->cmds->buf != NULL)
			add_token(lines->cmds);
		lines->cmds->tokens->redir = 3;
		if (line[*i] == '<')
		{
			*i += 1;
			lines->cmds->tokens->redir = 4;
			if (line[*i] == '<')
			{
				if (line[*i + 1] == '<') // <<<< 에러 처리
				{
					if (line[*i + 2] == '<') // <<<<< 에러 처리
					{
						if (line[*i + 3] == '<') // <<<<<< 에러 처리
							return (error_syntax("<<<"));
						return (error_syntax("<<"));
					}
					if (line[*i + 2] == '>')
						return (error_syntax("<>"));
					return (error_syntax("<"));
				}
				if (line[*i + 1] == '>') // <<<> 에러 처리
					return (error_syntax(">"));
				if (line[*i + 1] == '|')
					return (error_syntax("|"));
				return (0);
			}
			if (line[*i] == '>') // <<> 에러 처리
				return (error_syntax(">"));
		}
		if (line[*i] == '|') // <| <<| 에러 처리
			return (error_syntax("|"));
		return (1);
	}
	return (0);
}