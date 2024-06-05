/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:46:39 by kyumkim           #+#    #+#             */
/*   Updated: 2023/10/26 18:11:49 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;
	int		idx;

	idx = 0;
	ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ret == NULL)
		return (NULL);
	while (*s1 != 0)
	{
		ret[idx++] = *s1;
		s1++;
	}
	while (*s2 != 0)
	{
		ret[idx++] = *s2;
		s2++;
	}
	ret[idx] = 0;
	return (ret);
}
