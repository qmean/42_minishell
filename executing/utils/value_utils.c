/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 23:40:35 by kyumkim           #+#    #+#             */
/*   Updated: 2024/08/03 23:07:12 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

int	count_values_by_string(const char *values);

char	**value_split(char *str)
{
	char	**ret;
	int		idx;
	int		cnt;
	int		len;

	ret = (char **) malloc(sizeof(char *) * (count_values_by_string(str) + 1));
	if (ret == NULL)
		exit(1);
	idx = 0;
	cnt = 0;
	while (str[idx] != '\0')
	{
		len = 0;
		while (str[idx + len] != ':' && str[idx + len] != '\0')
			len++;
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
	return (ret);
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
