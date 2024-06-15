/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 01:17:21 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/16 01:40:49 by jaemikim         ###   ########.fr       */
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