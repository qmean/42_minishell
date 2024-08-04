/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 01:11:32 by kyumkim           #+#    #+#             */
/*   Updated: 2024/07/31 09:52:59 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executing.h"

char	**env_to_envp(t_env *env)
{
	char	**envp;
	t_env	*env_iter;
	int		idx;

	envp = (char **)malloc(sizeof(char *) * (env_size(env) + 1));
	if (envp == NULL)
		exit(1);
	idx = 0;
	env_iter = env;
	while (env_iter != NULL)
	{
		envp[idx] = ft_strjoin(env_iter->key, "=");
		if (envp[idx] == NULL)
			exit(1);
		envp[idx] = ft_strjoin(envp[idx], env_iter->value);
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

	argv = (char **)malloc(sizeof(char *) * (token_size(cmd->tokens) + 1));
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
