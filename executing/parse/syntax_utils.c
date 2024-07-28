/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <jaemikim@student42.ac.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:17:26 by jaemikim          #+#    #+#             */
/*   Updated: 2024/07/07 16:24:50 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"


// redir 뒤에 오는 토큰을 redir_arg[1]에 저장하고 뒤 토큰을 삭제

void make_redir_token(t_token *token, t_token *next)
{
  if (!token || !next) return; // 기본적인 널 체크

  // 데이터 복제
  token->redir_args[0] = ft_strdup(token->data); // 현재 토큰 데이터 복제
  token->redir_args[1] = ft_strdup(next->data); // 다음 토큰 데이터 복제
  if (next->data)
    free(next->data); // 원본 다음 데이터 해제
  next->data = NULL; // 포인터를 널로 설정

  // 링크 업데이트
  t_token *temp_next = next->next; // 다음의 다음을 임시 저장
  free(next); // 다음 토큰 해제
  token->next = temp_next; // 현재 토큰을 다음의 다음으로 연결
}