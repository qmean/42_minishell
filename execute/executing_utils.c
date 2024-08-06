/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 01:11:32 by kyumkim           #+#    #+#             */
/*   Updated: 2024/08/07 04:35:22 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**env_to_envp(t_env *env)
{
	char	**envp;
	char	*tmp;
	t_env	*env_iter;
	int		idx;

	envp = (char **)malloc(sizeof(char *) * (env_size(env) + 1));
	if (envp == NULL)
		exit(1);
	idx = 0;
	env_iter = env;
	while (env_iter != NULL)
	{
		tmp = ft_strjoin(env_iter->key, "=");
		if (tmp == NULL)
			exit(1);
		envp[idx] = ft_strjoin(tmp, env_iter->value);
		free(tmp);
		if (envp[idx] == NULL)
			exit(1);
		idx++;
		env_iter = env_iter->next;
	}
	envp[idx] = NULL;
	return (envp);
}

char	**cmd_to_argv(t_cmd *cmd)
{
	t_token	*token;
	char	**argv;
	int		idx;

	argv = (char **)malloc(sizeof(char *) * (token_size(cmd->first_token) + 1));
	if (argv == NULL)
		exit(1);
	idx = 0;
	token = cmd->first_token;
	while (token != NULL)
	{
		argv[idx] = ft_strdup(token->data);
		if (argv[idx] == NULL)
			exit(1);
		idx++;
		token = token->next;
	}
	argv[idx] = NULL;
	return (argv);
}
