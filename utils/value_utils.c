/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 23:40:35 by kyumkim           #+#    #+#             */
/*   Updated: 2024/08/07 01:54:54 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		count_length(char *str);
int		count_values_by_string(const char *values);
void	check_ret(char **ret, int size);

char	**value_split(char *str)
{
	char	**ret;
	int		idx;
	int		cnt;
	int		len;

	ret = (char **)malloc(sizeof(char *) * (count_values_by_string(str) + 1));
	if (ret == NULL)
		exit(1);
	idx = 0;
	cnt = 0;
	while (str[idx] != '\0')
	{
		len = count_length(str + idx);
		if (len == 0)
			ret[cnt] = ft_strdup("");
		else
			ret[cnt] = ft_substr(str, idx, len);
		idx += len + 1;
		cnt++;
	}
	if (str[idx - 1] == ':')
		ret[cnt++] = ft_strdup("");
	ret[cnt] = NULL;
	check_ret(ret, cnt);
	return (ret);
}

void	check_ret(char **ret, int size)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		if (ret[idx] == NULL)
			exit(1);
		idx++;
	}
}

int	count_length(char *str)
{
	int	len;

	len = 0;
	while (str[len] != ':' && str[len] != '\0')
		len++;
	return (len);
}

int	count_values_by_string(const char *values)
{
	int	cnt;
	int	idx;

	cnt = 1;
	idx = 0;
	while (values[idx])
	{
		if (values[idx] == ':')
			cnt++;
		idx++;
	}
	return (cnt);
}
