/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paring_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 01:17:21 by jaemikim          #+#    #+#             */
/*   Updated: 2024/06/10 04:46:17 by jaemikim         ###   ########.fr       */
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

char	*ft_strjoin_free(const char *s1, char s2)
{
	char	*ret;
	int		idx;

	idx = 0;
	ret = malloc(ft_strlen(s1)+ 2);
	if (ret == NULL)
		return (NULL);
	while (*s1 != 0)
	{
		ret[idx++] = *s1;
		s1++;
	}
    ret[idx++] = s2;
	ret[idx] = 0;
    free(s1);
	return (ret);
}