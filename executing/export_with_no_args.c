/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_with_no_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:46:40 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/19 03:39:18 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

t_env	*copy_env(t_env *env);
void	sort_env(t_env *env);
void	swap_env(t_env *env1, t_env *env2);
void	export_print(t_env *env);

void	export_with_no_args(t_line *line)
{
	t_env	*env;

	env = copy_env(line->env);
	if (env == NULL)
		exit(1);
	sort_env(env);
	export_print(env);
	free_env(env);
}

t_env	*copy_env(t_env *env)
{
	t_env	*ret;
	t_env	*new_env_head;

	ret = (t_env *)malloc(sizeof(t_env));
	if (ret == NULL)
		return (NULL);
	new_env_head = ret;
	while (env)
	{
		ret->key = ft_strdup(env->key);
		if (ret->key == NULL)
			exit(1); // todo : 에러 처리 추가
		if (env->value != NULL)
		{
			ret->value = ft_strdup(env->value);
			if (ret->value == NULL)
				exit(1); // todo : 에러 처리 추가
		}
		else
			ret->value = NULL;
		if (env->next != NULL)
		{
			ret->next = (t_env *)malloc(sizeof(t_env));
			if (ret->next == NULL)
				return (NULL);
			ret = ret->next;
		}
		env = env->next;
	}
	ret->next = NULL;
	return (new_env_head);
}

void	sort_env(t_env *env)
{
	t_env	*tmp;
	t_env	*stop;
	t_env	*iter;

	tmp = env;
	stop = NULL;
	while (tmp != stop)
	{
		iter = tmp;
		while (iter->next != stop)
		{
			if (ft_strcmp(iter->key, iter->next->key) > 0)
				swap_env(iter, iter->next);
			iter = iter->next;
		}
		stop = iter;
	}
}

void	swap_env(t_env *env1, t_env *env2)
{
	char	*key;
	char	*value;

	key = env1->key;
	env1->key = env2->key;
	env2->key = key;
	value = env1->value;
	env1->value = env2->value;
	env2->value = value;
}

void	export_print(t_env *env)
{
	while (env)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(env->key, 1);
		if (env->value != NULL)
		{
			ft_putstr_fd("=\"", 1);
			ft_putstr_fd(env->value, 1);
			ft_putstr_fd("\"\n", 1);
		}
		else
			ft_putstr_fd("\n", 1);
		env = env->next;
	}
}
