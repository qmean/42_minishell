/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:52:41 by kyumkim           #+#    #+#             */
/*   Updated: 2023/12/07 17:36:41 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isinset(const char c, const char *set);
int	frontidx(const char *s1, const char *set);
int	backidx(const char *s1, const char *set);

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*ret;
	int		bidx;
	int		fidx;

	if (ft_strlen(s1) == 0)
	{
		ret = (char *)malloc(sizeof(char) * 1);
		if (ret == NULL)
			return (NULL);
		*ret = 0;
		return (ret);
	}
	fidx = frontidx(s1, set);
	bidx = backidx(s1, set);
	if (bidx < fidx)
	{
		ret = (char *)malloc(sizeof(char) * 1);
		if (ret == NULL)
			return (NULL);
		*ret = 0;
		return (ret);
	}
	return (ft_substr(s1, fidx, bidx - fidx + 1));
}

int	isinset(const char c, const char *set)
{
	while (*set != 0)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

int	frontidx(const char *s1, const char *set)
{
	int		ret;

	ret = 0;
	while (*s1 != 0)
	{
		if (isinset(*s1, set))
			ret++;
		else
			break ;
		s1++;
	}
	return (ret);
}

int	backidx(const char *s1, const char *set)
{
	int		ret;

	ret = ft_strlen(s1) - 1;
	while (ret != 0)
	{
		if (!isinset(s1[ret], set))
			break ;
		ret--;
	}
	return (ret);
}
