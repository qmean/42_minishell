/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_add_no_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuminkim <kyuminkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 04:05:42 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/15 23:14:15 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	do_no_value(t_data *data, char *arg)
{
	t_env	*env;
	char	*key;
	int		idx;
	char	**value;

	idx = 0;
	while (arg[idx] != '=')
		idx++;
	key = ft_substr(arg, 0, idx);
	env = find_env_with_key(data, key);
	if (env == NULL)
	{
		value = malloc(sizeof(char *));
		if (value == NULL)
			exit(1); // todo : 에러 처리 추가
		value[0] = NULL;
		add_env_node(data, key, value);
		free(key);
		return ;
	}
	free_values(env->value);
	env->value = malloc(sizeof(char *));
	if (env->value == NULL)
		exit(1); // todo : 에러 처리 추가
	env->value[0] = NULL;
	free(key);
}

// arg가 "key=" 형식인지 확인하도록 해줘
int	check_no_value(char *arg)
{
	int	idx;

	idx = 0;
	while (arg[idx] != '\0')
	{
		if (arg[idx] == '=' && arg[idx + 1] == '\0')
			return (1);
		idx++;
	}
	return (0);
}
