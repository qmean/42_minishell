/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_do_export.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 01:39:17 by kyumkim           #+#    #+#             */
/*   Updated: 2024/08/07 04:25:13 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	do_no_value(t_line *line, char *arg)
{
	t_env	*env;
	char	*empty_value;
	char	*key;

	key = ft_substr(arg, 0, ft_strlen(arg) - 1);
	env = find_env_with_key(line, key);
	empty_value = ft_strdup("");
	if (empty_value == NULL)
		exit(1);
	if (env == NULL)
	{
		new_env(line, key, empty_value);
		free(key);
		free(empty_value);
	}
	else
	{
		free(key);
		free(env->value);
		env->value = empty_value;
	}
}

void	do_plus(t_line *line, char *arg)
{
	char	**splited;

	splited = export_split(arg, "+=");
	add_env_value(line, splited[0], splited[1]);
	free(splited[0]);
	free(splited[1]);
	free(splited);
}

void	do_change(t_line *line, char *arg)
{
	char	**splited;
	t_env	*env;

	splited = export_split(arg, "=");
	env = find_env_with_key(line, splited[0]);
	if (env == NULL)
	{
		new_env(line, splited[0], splited[1]);
		free(splited[0]);
		free(splited[1]);
	}
	else
	{
		free(env->value);
		env->value = splited[1];
		free(splited[0]);
	}
	free(splited);
}

void	do_keys(t_line *line, char *arg)
{
	t_env	*new;

	if (find_env_with_key(line, arg))
		return ;
	new = (t_env *)malloc(sizeof(t_env));
	if (new == NULL)
		exit(1);
	new->key = ft_strdup(arg);
	new->value = NULL;
	new->next = line->env;
	line->env = new;
}
