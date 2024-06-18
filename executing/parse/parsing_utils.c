/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 01:17:21 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/19 03:02:23 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int    iswhitespace(char *c)
{
    while (*c != '\0')
    { 
        if ((*c == ' ' || *c == '\t' || *c == '\n' || *c == '\v' || *c == '\f' || *c == '\r') == 0)
            return (0);
        c++;
    }
    return (1);

}

char	*ft_strjoin_free(char *s1, char s2)
{
	char	*ret;
	int		idx;
	char	*tmp;
	
	ret = malloc(ft_strlen(s1) * 2);
	if (ret == NULL)
		return (NULL);
    if (s1 == NULL)
    {
        ret[0] = s2;
        ret[1] = 0;
        return (ret);
    }
	tmp = s1;
	idx = 0;
	while (*s1 != 0)
	{
		ret[idx++] = *s1;
		s1++;
	}
	ret[idx++] = s2;
	ret[idx] = 0;
	if (tmp != NULL)
		free(tmp);
	return (ret);
}

int	ft_strcmp_par(const char *s1, const char *s2)
{
	while (*s1 != 0 && *s2 != 0)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

char	*ft_strcat_env(char *dst, const char *src)
{
	size_t				srclen;
	size_t				dstlen;
	unsigned long long	i;
	char				*tmp;

	i = 0;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	tmp = (char *) malloc(sizeof(char) * (dstlen + srclen + 1));
	if (!tmp)
		return (NULL);
	while (i < dstlen)
	{
		tmp[i] = dst[i];
		i++;
	}
	while (i < srclen + dstlen)
	{
		tmp[i] = src[i - dstlen];
		i++;
	}
	tmp[i] = '\0';
	free(dst);
	return (tmp);
}
