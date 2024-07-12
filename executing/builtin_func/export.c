/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuminkim <kyuminkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 21:36:34 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/19 03:55:25 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	export(t_line *line, t_token *token)
{
	int	exit_flag;

	exit_flag = 0;
	if (token == NULL)
		export_with_no_args(line);
	while (token != NULL)
	{
		if (add_env(line, token->data) == 1)
			exit_flag = 1;
		token = token->next;
	}
	line->exit_flag = exit_flag;
}

char	**export_split(char *arg, char *sep)
{
	char	**result;
	int		idx;
	size_t	len;

	result = (char **)malloc(sizeof(char *) * 2);
	len = ft_strlen(sep);
	idx = 0;
	while (arg[idx] != '\0')
	{
		if (ft_strncmp(arg + idx, sep, len) == 0)
			break ;
		idx++;
	}
	result[0] = ft_substr(arg, 0, idx);
	result[1] = ft_strdup(arg + idx + len);
	if (result[0] == NULL || result[1] == NULL)
		exit(1); // todo : malloc error 추가
	return (result);
}
