/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing_bin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 01:12:05 by kyumkim           #+#    #+#             */
/*   Updated: 2024/08/07 04:31:02 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_bin(t_line *line, t_cmd *cmd, char **argv, char **envp)
{
	char	*path;
	char	**values;

	path = NULL;
	values = value_split(find_value(line, "PATH"));
	while (*values)
	{
		path = check_and_put_path(*values, cmd->first_token->data);
		if (path != NULL)
			break ;
		values++;
	}
	if (path == NULL)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd->first_token->data, 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(126);
	}
	execve(path, argv, envp);
}

char	*check_and_put_path(char *dir_path, char *cmd)
{
	DIR				*dir;
	struct dirent	*entry;
	char			*path;

	dir = opendir(dir_path);
	if (dir == NULL)
		return (NULL);
	entry = readdir(dir);
	while (entry != NULL)
	{
		if (!ft_strcmp(entry->d_name, cmd))
		{
			path = ft_strjoin(dir_path, "/");
			path = ft_strjoin(path, cmd);
			return (path);
		}
		entry = readdir(dir);
	}
	return (NULL);
}
