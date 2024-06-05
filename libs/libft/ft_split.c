/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:42:57 by kyumkim           #+#    #+#             */
/*   Updated: 2023/11/07 15:42:58 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		wordcount(const char *s, char c);
void	splitfree(char **ret, int retidx);
void	makeidx(int *idx1, int *idx2, const char *s, char c);

char	**ft_split(const char *s, char c)
{
	char	**ret;
	int		retidx;
	int		idx1;
	int		idx2;

	ret = (char **)malloc(sizeof(char *) * (wordcount(s, c) + 1));
	if (ret == NULL)
		return (NULL);
	idx1 = 0;
	retidx = 0;
	while (retidx < wordcount(s, c))
	{
		makeidx(&idx1, &idx2, s, c);
		ret[retidx] = ft_substr(s, idx1, idx2 - idx1);
		if (ret[retidx] == NULL)
		{
			splitfree(ret, retidx);
			return (NULL);
		}
		idx1 = idx2;
		retidx++;
	}
	ret[retidx] = NULL;
	return (ret);
}

int	wordcount(const char *s, char c)
{
	int	flag;
	int	ret;

	flag = 0;
	ret = 0;
	while (*s != 0)
	{
		if (*s == c)
			flag = 0;
		else if (*s != c && flag == 0)
		{
			flag = 1;
			ret++;
		}
		s++;
	}
	return (ret);
}

void	splitfree(char **ret, int retidx)
{
	int	idx;

	idx = 0;
	while (idx < retidx)
	{
		free(ret[idx]);
		idx++;
	}
	free(ret);
	return ;
}

void	makeidx(int *idx1, int *idx2, const char *s, char c)
{
	while (s[*idx1] == c && s[*idx1] != 0)
		(*idx1)++;
	*idx2 = *idx1;
	while (s[*idx2] != c && s[*idx2] != 0)
		(*idx2)++;
	return ;
}
