/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_with_no_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:46:40 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/09 23:07:01 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	export_with_no_args(t_data *data)
{
	t_env	*env;

	env = copy_env(data->env);
	if (env == NULL)
		exit(1);
	sort_env(env);
	print_env_with_sort(env);
	free_env(env);
}
