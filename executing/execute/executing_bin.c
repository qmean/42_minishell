/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing_bin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 01:12:05 by kyumkim           #+#    #+#             */
/*   Updated: 2024/07/31 11:08:06 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executing.h"

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
		print_error(cmd->first_token->data, NULL, "command not found");
		line->exit_flag = 127;
		return ;
	}
	if (cmd->input_file != -2 || cmd->output_file != -2)
		do_redirect_cmd(line, cmd);
	execve(path, argv, envp);
	print_error(cmd->first_token->data, NULL, "command not found");
	exit(126);
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
