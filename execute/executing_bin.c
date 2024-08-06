/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing_bin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 01:12:05 by kyumkim           #+#    #+#             */
/*   Updated: 2024/08/07 05:50:15 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*check_defined_path(char *cmd);

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
		path = check_defined_path(cmd->first_token->data);
	if (path == NULL)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd->first_token->data, 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(126);
	}
	if (execve(path, argv, envp) == -1)
		print_error(cmd->first_token->data, NULL, strerror(errno));
}

char	*check_and_put_path(char *dir_path, char *cmd)
{
	DIR				*dir;
	struct dirent	*entry;
	char			*path;
	char			*tmp;

	dir = opendir(dir_path);
	if (dir == NULL)
		return (NULL);
	entry = readdir(dir);
	while (entry != NULL)
	{
		if (!ft_strcmp(entry->d_name, cmd))
		{
			tmp = ft_strjoin(dir_path, "/");
			path = ft_strjoin(tmp, cmd);
			free(tmp);
			return (path);
		}
		entry = readdir(dir);
	}
	return (NULL);
}

char	*check_defined_path(char *cmd)
{
	if (ft_strncmp(cmd, "/", 1) != 0
		&& ft_strncmp(cmd, "./", 2) != 0
		&& ft_strncmp(cmd, "../", 3) != 0)
		return (NULL);
	if (access(cmd, F_OK) != 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		exit(127);
	}
	if (access(cmd, X_OK) != 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		exit(126);
	}
	return (cmd);
}
