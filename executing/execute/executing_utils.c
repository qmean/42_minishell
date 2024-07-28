/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 01:11:32 by kyumkim           #+#    #+#             */
/*   Updated: 2024/07/29 01:11:52 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executing.h"

char	**env_to_envp(t_env *env)
{
	char	**envp;
	t_env	*iter;
	int		idx;

	envp = (char **)malloc(sizeof(char *) * (env_size(env) + 1));
	if (envp == NULL)
		exit(1);
	idx = 0;
	iter = env;
	while (iter != NULL)
	{
		envp[idx] = ft_strjoin(iter->key, "=");
		if (envp[idx] == NULL)
			exit(1);
		envp[idx] = ft_strjoin(envp[idx], iter->value);
		if (envp[idx] == NULL)
			exit(1);
		idx++;
		iter = iter->next;
	}
	envp[idx] = NULL;
	return (envp);
}

char	**cmd_to_argv(t_cmd *cmd)
{
	t_token	*token;
	char	**argv;
	int		idx;

	argv = (char **)malloc(sizeof(char *) * (token_size(cmd->tokens) + 1));
	if (argv == NULL)
		exit(1);
	idx = 0;
	token = cmd->first_token;
	while (token != NULL && token->data != NULL)
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
