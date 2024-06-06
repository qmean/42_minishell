/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuminkim <kyuminkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:24:22 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/06 18:48:49 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	pwd(t_data *data)
{
	t_env	*env;
	char	**pwd;

	env = data->env;
	pwd = find_value("PWD", data);
	if (pwd != NULL)
		ft_putstr_fd(pwd[0], 1);
	ft_putstr_fd("\n", 1);
	return ;
}
