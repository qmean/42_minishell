/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_parsing_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:39:06 by kyumkim           #+#    #+#             */
/*   Updated: 2024/08/07 01:54:25 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*find_value(t_line *line, char *key)
{
	t_env	*env;

	env = line->env;
	while (env)
	{
		if (!ft_strcmp(env->key, key))
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

t_env	*find_env_with_key(t_line *line, char *key)
{
	t_env	*iter;

	iter = line->env;
	while (iter)
	{
		if (!ft_strcmp(iter->key, key))
			return (iter);
		iter = iter->next;
	}
	return (NULL);
}

// key 에 해당하는 env 를 찾아서 value 를 뒤에 추가한다.
// env 가 없으면 새로 만든다.
// 문자열을 덧붙일 경우에는 파라미터로 들어온 value 는 free 를 해준다.
void	add_env_value(t_line *line, char *key, char *value)
{
	t_env	*env;
	char	*new_value;
	char	*tmp;

	env = find_env_with_key(line, key);
	if (env == NULL)
	{
		new_env(line, key, value);
		return ;
	}
	tmp = ft_strdup(env->value);
	new_value = ft_strcat(tmp, value);
	if (new_value == NULL)
		exit(1);
	tmp = env->value;
	env->value = new_value;
	free(tmp);
}

void	new_env(t_line *line, char *key, char *value)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (new == NULL)
		exit(1);
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	if (new->key == NULL || new->value == NULL)
		exit(1);
	if (line->env == NULL)
	{
		line->env = new;
		return ;
	}
	new->next = line->env;
	line->env = new;
}

void	set_value(t_line *line, char *key, char *value)
{
	t_env	*env;

	env = find_env_with_key(line, key);
	if (env == NULL)
	{
		new_env(line, key, value);
		return ;
	}
	free(env->value);
	env->value = value;
}
