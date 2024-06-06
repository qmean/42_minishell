/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuminkim <kyuminkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:48:05 by kyuminkim         #+#    #+#             */
/*   Updated: 2024/06/06 20:11:46 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

t_data	*parse_envp(char **envp);
void	print_env(t_data *data);

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	char	*cmd;
	char	**args;
	t_data	*data;
	pid_t	pid;

	if (argc != 1)
	{
		ft_putstr_fd("Error: too many arguments\n", 2);
		return (1);
	}
	data = parse_envp(envp);
	while (1)
	{
		input = readline("mini_shell$ ");
		args = ft_split(input, ' ');
		cmd = args[0];
		args++;
		pid = fork();
		if (pid == 0)
		{
			execute(data, cmd, args, envp);
		}
		else if (pid < 0)
			ft_putstr_fd("Error: fork failed\n", 2);
		else
			waitpid(pid, NULL, 0);
	}
	return (0);
}

void	print_env(t_data *data)
{
	t_env	*env;
	int		i;

	env = data->env;
	while (env != NULL)
	{
		printf("key = %s\n", env->key);
		i = 0;
		while (env->value[i] != NULL)
		{
			printf("value = %s\n", env->value[i]);
			i++;
		}
		printf("=====================\n");
		env = env->next;
	}
}

t_data	*parse_envp(char **envp)
{
	t_data	*data;
	t_env	*env;
	char	**split;

	data = (t_data *)malloc(sizeof(t_data));
	data->env = NULL;
	while (*envp != NULL)
	{
		env = (t_env *)malloc(sizeof(t_env));
		split = ft_split(*envp, '=');
		env->key = split[0];
		if (split[1] != NULL)
			env->value = ft_split(split[1], ':');
		else
		{
			env->value = malloc(sizeof(char *));
			env->value[0] = NULL;
		}
		env->next = data->env;
		data->env = env;
		envp++;
	}
	return (data);
}
