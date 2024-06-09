/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:15:17 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/09 23:15:47 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	swap_env(t_env *env1, t_env *env2)
{
	char	*key;
	char	**value;

	key = env1->key;
	env1->key = env2->key;
	env2->key = key;
	value = env1->value;
	env1->value = env2->value;
	env2->value = value;
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
