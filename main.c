/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:28:43 by jaemikim          #+#    #+#             */
/*   Updated: 2024/08/07 04:22:21 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_envp(t_line *line, char **envp);
char	**env_split(char *str);
t_line	*init_line(void);
void	free_lines(t_line *line);

void leak_check(void)
{
	system("leaks minishell");
}

int	main(int argc, char **argv, char **envp)
{
	char			*line;
	struct termios	term;
	t_line			*cmd_line;

	atexit(leak_check);
	argv[argc -1] = NULL;
	cmd_line = init_line();
	parse_envp(cmd_line, envp);
	envp = NULL;
	tcgetattr(0, &term);
	set_signal();
	line = readline("minishell$ ");
	while (line)
	{
		if ((line[0] != '\0') && (!iswhitespace(line)))
		{
			init(cmd_line);
			add_history(line);
			tokenize_main(line, cmd_line);
			execute(cmd_line);
			free_cmd(cmd_line);
		}
		free(line);
		line = readline("minishell$ ");
	}
	free_lines(cmd_line);
	sig_term_handler();
	tcsetattr(0, TCSANOW, &term);
}

t_line	*init_line(void)
{
	t_line	*line;

	line = (t_line *)malloc(sizeof(t_line));
	if (line == NULL)
		exit(1);
	line->env = NULL;
	line->exit_flag = 0;
	return (line);
}

char	**env_split(char *str)
{
	char	**ret;
	int		idx;

	ret = (char **)malloc(sizeof(char *) * 2);
	idx = 0;
	while (str[idx] != '=' && str[idx] != '\0')
		idx++;
	if (str[idx] == '\0')
	{
		ret[0] = ft_strdup(str);
		if (ret[0] == NULL)
			exit(1);
		ret[1] = NULL;
		return (ret);
	}
	ret[0] = ft_substr(str, 0, idx);
	ret[1] = ft_strdup(str + idx + 1);
	if (ret[0] == NULL || ret[1] == NULL)
		exit(1);
	return (ret);
}

void	parse_envp(t_line *line, char **envp)
{
	char	**split;
	int		idx;

	idx = 0;
	while (envp[idx] != NULL)
	{
		split = env_split(envp[idx]);
		new_env(line, split[0], split[1]);
		free(split[0]);
		free(split[1]);
		free(split);
		idx++;
	}
}

void	free_lines(t_line *line)
{
	free_env(line->env);
	free(line);
}
