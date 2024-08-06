/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:32:13 by kyumkim           #+#    #+#             */
/*   Updated: 2024/08/07 03:29:44 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_env(t_env *env)
{
	t_env	*tmp;
	t_env	*free_env;

	free_env = env;
	while (free_env)
	{
		tmp = free_env->next;
		free(free_env->key);
		free(free_env->value);
		free(free_env);
		free_env = tmp;
	}
}
