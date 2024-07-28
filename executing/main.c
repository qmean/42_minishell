/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jammin <jammin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:48:01 by kyumkim           #+#    #+#             */
/*   Updated: 2024/07/07 16:28:43 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void  parse_envp(t_line *line, char **envp);
char	**env_split(char *str);
t_line	*init_line(void);

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	struct termios	term;
	t_line	*cmds;

	cmds = init_line();
	parse_envp(cmds, envp);
	t_env *test = cmds->env;
	// while (test)
	// {
	// 	printf("key: %s, value: %s\n", test->key, test->value);
	// 	test = test->next;
	// }
	tcgetattr(0, &term);
	set_signal();
	while ((line = readline("minishell$ ")))
	{
		if ((line[0] != '\0') && (!iswhitespace(line))) // 빈문자열이 아니고 공백문자열이 아닐 때
		{
			init(cmds);
			cmds->cmds->env = malloc(sizeof(t_env));
			add_history(line);
			tokenize_main(line, cmds);
			check_syntax(cmds);
			print_cmd(cmds->first_cmd);

			// execute(cmds);
			// if (cmds->cmds->first_token->next->redir == 3)
			// 	printf(input_redirection("redir.c"));
			free_cmd(cmds);
		}
		free(line);
	}
	sig_term_handler(); // ctrl + D 핸들러
	tcsetattr(0, TCSANOW, &term);
}

t_line	*init_line(void)
{
	t_line	*line;

	line = (t_line *)malloc(sizeof(t_line));
	if (line == NULL)
		exit(1); // todo : 에러 처리 추가
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
			exit(1); // todo : 에러 처리 추가
		ret[1] = NULL;
		return (ret);
	}
	ret[0] = ft_substr(str, 0, idx);
	ret[1] = ft_strdup(str + idx + 1);
	if (ret[0] == NULL || ret[1] == NULL)
		exit(1); // todo : 에러 처리 추가
	return (ret);
}

void  parse_envp(t_line *line, char **envp)
{
	t_env	*env;
	char	**split;

	env = NULL;
	while (*envp)
	{
		split = env_split(*envp);
		new_env(line, split[0], split[1]);
		envp++;
	}
	return ;
}
