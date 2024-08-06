/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeniz.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 00:45:53 by jaemikim          #+#    #+#             */
/*   Updated: 2024/08/06 16:04:04 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	tokenize_main(char *line, t_line *lines)
{
	int	i;
	int	ret;

	i = 0;
	while (line[i])
	{
		ret = check_issue(line, lines, &i);
		if (ret == 1)
			continue ;
		else if (ret == -1)
			return ;
		else
			lines->cmds->buf = ft_strjoin_free(lines->cmds->buf, line[i]);
		i++;
	}
	if (lines->cmds->quote != 0)
		error_invalid_quote();
	if ((line[i] == '\0') && (lines->cmds->buf != NULL))
		add_token(lines->cmds);
	check_syntax(lines);
}

int	check_issue(char *line, t_line *lines, int *i)
{
	int	ret;

	ret = check_quote(line, lines->cmds, i);
	if (ret != 0)
		return (ret);
	ret = check_space(line, lines->cmds, i);
	if (ret != 0)
		return (ret);
	ret = check_pipe(line, lines, i);
	if (ret != 0)
		return (ret);
	ret = check_env(line, lines, i);
	if (ret != 0)
		return (ret);
	ret = check_redir(line, lines, i);
	if (ret != 0)
		return (ret);
	return (0);
}
