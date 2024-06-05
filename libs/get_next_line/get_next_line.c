/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:43:30 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/05 19:31:48 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];

	if (BUFFER_SIZE < 1 || fd < 0 || fd > OPEN_MAX)
		return (NULL);
	if (readfile(&buffer[fd], fd) == -1)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	return (make_return(&buffer[fd]));
}

char	*make_return(char	**buffer)
{
	int	lineidx;

	if (*buffer == NULL)
		return (NULL);
	lineidx = newline_idx(*buffer);
	if (lineidx == -1)
		return (ft_substr(buffer, ft_strlen(*buffer) - 1));
	else
		return (ft_substr(buffer, lineidx));
}

char	*ft_strdup(char *str)
{
	char	*ret;
	int		retidx;

	if (str == NULL)
		return (NULL);
	ret = malloc(ft_strlen(str) + 1);
	if (ret == NULL)
		return (NULL);
	retidx = 0;
	while (*str != 0)
	{
		ret[retidx] = *str;
		retidx++;
		str++;
	}
	ret[retidx] = 0;
	return (ret);
}

char	*ft_substr(char **str, int endidx)
{
	char	*ret;
	char	*tmp;

	if ((ft_strlen(*str) - endidx) == 0)
	{
		free_buffer(str, NULL);
		return (ft_strdup(*str));
	}
	ret = malloc(endidx + 2);
	if (ret == NULL)
	{
		free_buffer(str, NULL);
		return (NULL);
	}
	tmp = malloc(ft_strlen(*str) - endidx);
	if (tmp == NULL)
	{
		free(ret);
		free_buffer(str, NULL);
		return (NULL);
	}
	str_ncpy(ret, *str, endidx + 1);
	str_ncpy(tmp, (*str) + endidx + 1, ft_strlen(*str) - endidx - 1);
	free_buffer(str, tmp);
	return (ret);
}

void	str_ncpy(char *dest, char *src, int n)
{
	int	idx;

	idx = 0;
	while (idx < n)
	{
		dest[idx] = *src;
		src++;
		idx++;
	}
	dest[idx] = 0;
}
