/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:47:37 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/05 19:31:57 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	readfile(char **buffer, int fd)
{
	char	tmp[BUFFER_SIZE + 1];
	int		read_size;

	if (newline_idx(*buffer) != -1)
		return (0);
	while (newline_idx(*buffer) == -1)
	{
		read_size = read(fd, tmp, BUFFER_SIZE);
		if (read_size == -1)
			return (-1);
		else if (read_size == 0)
		{
			if (ft_strlen(*buffer) == 0)
				return (-1);
			break ;
		}
		tmp[read_size] = 0;
		if (ft_strcat(buffer, tmp) == -1)
			return (-1);
	}
	return (0);
}

int	ft_strcat(char **dest, char *src)
{
	char	*tmp;

	tmp = malloc(ft_strlen(*dest) + ft_strlen(src) + 1);
	if (tmp == NULL)
		return (-1);
	str_ncpy(tmp, *dest, ft_strlen(*dest));
	str_ncpy(tmp + ft_strlen(*dest), src, ft_strlen(src));
	free(*dest);
	*dest = tmp;
	return (0);
}

int	ft_strlen(char *str)
{
	int	ret;

	if (str == NULL)
		return (0);
	ret = 0;
	while (*str != 0)
	{
		str++;
		ret++;
	}
	return (ret);
}

int	newline_idx(char *str)
{
	int	ret;

	if (str == NULL)
		return (-1);
	ret = 0;
	while (*str != 0)
	{
		if (*str == '\n')
			return (ret);
		ret++;
		str++;
	}
	return (-1);
}

void	free_buffer(char **str, char *tmp)
{
	free(*str);
	*str = tmp;
}
