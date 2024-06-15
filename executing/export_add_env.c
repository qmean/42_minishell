/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_add_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuminkim <kyuminkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:30:12 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/15 23:04:12 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	check_and_add_env(t_data *data, char *arg);


int	add_env(t_data *data, char *arg)
{
	if (export_check_validated(arg))
		return (1);
	if (check_valid_underbar_char(arg))
		return (0);
	check_and_add_env(data, arg);
	return (0);
}

void	check_and_add_env(t_data *data, char *arg)
{
	if (check_plus(arg))
		do_plus(data, arg);
	else if (check_change(arg))
		do_change(data, arg);
	else if (check_no_value(arg))
		do_no_value(data, arg);
	else
		do_keys(data, arg);
}

void	do_keys(t_data *data, char *arg)
{
	t_env	*new;

	if (find_env_with_key(data, arg))
		return ;
	new = (t_env *)malloc(sizeof(t_env));
	if (new == NULL)
		exit(1);
	new->key = ft_strdup(arg);
	new->value = NULL;
	new->next = data->env;
	data->env = new;
}
