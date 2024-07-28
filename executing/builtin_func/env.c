/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:32:10 by kyumkim           #+#    #+#             */
/*   Updated: 2024/07/12 14:58:44 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	env_print(t_env *env);

void	env(t_line *line, t_token *token)
{
	t_env	*env;

	// todo : 파이프 처리시 token의 data가 null 이 되는 파싱예외 수정후 리팩토링
	if (token != NULL && token->data != NULL)
	{
		ft_putstr_fd("env: ", 2);
		ft_putstr_fd(token->data, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		line->exit_flag = 1;
		return ;
	}
	env = line->env;
	while (env != NULL)
	{
		if (env->value == NULL)
		{
			env = env->next;
			continue ;
		}
		env_print(env);
		env = env->next;
	}
}

void	env_print(t_env *env)
{
	ft_putstr_fd(env->key, 1);
	ft_putchar_fd('=', 1);
	ft_putstr_fd(env->value, 1);
	ft_putchar_fd('\n', 1);
}
