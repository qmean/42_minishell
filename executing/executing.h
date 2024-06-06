/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:32:48 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/06 19:02:34 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTING_H
# define EXECUTING_H
# include "../mainheader.h"
# include "stdio.h"
# include "string.h"
# include "errno.h"
# include "readline/readline.h"

typedef struct s_env
{
	char			*key;
	char			**value;
	struct s_env	*next;
}	t_env;

typedef struct s_data
{
	t_env	*env;
}	t_data;

void	env(t_data *data);
void	cd(t_data *data, char **cmdlist);
void	pwd(t_data *data);

char	**find_value(char *key, t_data *data);
void	execute(t_data *data, char *cmd, char **args, char **envp);

int		cmd_size(char **cmdlist);

#endif
