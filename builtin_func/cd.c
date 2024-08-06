/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:37:52 by kyumkim           #+#    #+#             */
/*   Updated: 2024/08/07 01:13:43 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cd_move_home(t_line *line);
void	cd_move_one_arg(t_line *line, char *path);
void	cd_move_oldpwd(t_line *line);
void	cd_move_path(t_line *line, char *path);

void	cd(t_line *line, t_cmd *cmd)
{
	if (token_size(cmd->first_token->next) == 0)
	{
		cd_move_home(line);
	}
	else if (token_size(cmd->first_token->next) >= 1)
	{
		cd_move_one_arg(line, cmd->first_token->next->data);
	}
}

void	cd_move_one_arg(t_line *line, char *path)
{
	if (!ft_strcmp_par(path, "~"))
	{
		cd_move_home(line);
		return ;
	}
	if (!ft_strcmp_par(path, "-"))
	{
		cd_move_oldpwd(line);
		return ;
	}
	cd_move_path(line, path);
}

void	cd_move_path(t_line *line, char *path)
{
	char	*oldpwd;
	char	*pwd;

	oldpwd = getcwd(NULL, 0);
	if (chdir(path) == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		line->exit_flag = 1;
		return ;
	}
	pwd = getcwd(NULL, 0);
	set_value(line, "OLDPWD", oldpwd);
	set_value(line, "PWD", pwd);
}

void	cd_move_oldpwd(t_line *line)
{
	t_env	*env;
	char	*oldpwd;
	char	*pwd;

	env = find_env_with_key(line, "OLDPWD");
	if (env == NULL)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd("cd: OLDPWD not set\n", 2);
		line->exit_flag = 1;
		return ;
	}
	oldpwd = getcwd(NULL, 0);
	chdir(env->value);
	pwd = getcwd(NULL, 0);
	set_value(line, "OLDPWD", oldpwd);
	set_value(line, "PWD", pwd);
}

void	cd_move_home(t_line *line)
{
	char	*home;
	char	*value;

	home = find_value(line, "HOME");
	if (home == NULL)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd("cd: HOME not set\n", 2);
		line->exit_flag = 1;
		return ;
	}
	value = getcwd(NULL, 0);
	set_value(line, "OLDPWD", value);
	chdir(home);
	set_value(line, "PWD", home);
}
