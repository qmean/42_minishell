/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:37:52 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/19 03:02:36 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

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
	else if (token_size(cmd->first_token->next) == 1)
	{
		cd_move_one_arg(line, cmd->first_token->next->data);
	}
	else
	{
		//todo : 에러처리 추간
		ft_putstr_fd("cd: too many arguments\n", 2);
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
		//todo : 에러처리 추가
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
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
		//todo : 에러처리 추가
		ft_putstr_fd("cd: OLDPWD not set\n", 2);
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
		//todo : 에러처리 추가
		ft_putstr_fd("cd: HOME not set\n", 2);
		return ;
	}
	value = getcwd(NULL, 0);
	set_value(line, "OLDPWD", value);
	chdir(home);
	set_value(line, "PWD", home);
}
