/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_with_no_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:46:40 by kyumkim           #+#    #+#             */
/*   Updated: 2024/08/07 01:38:23 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
	t_env	*tmp;

	ret = (t_env *)malloc(sizeof(t_env));
	if (ret == NULL)
		return (NULL);
	new_env_head = ret;
	while (env)
	{
		tmp = env_dup(env->key, env->value);
		ret->next = tmp;
		ret = tmp;
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
