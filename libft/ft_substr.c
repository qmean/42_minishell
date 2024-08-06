/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:06:24 by kyumkim           #+#    #+#             */
/*   Updated: 2023/10/29 17:29:49 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ret;
	int		idx;

	idx = 0;
	if (start >= ft_strlen(s))
		len = 1;
	else if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start + 1;
	else
		len++;
	ret = (char *)malloc(sizeof(char) * len);
	if (ret == NULL)
		return (NULL);
	while (--len)
	{
		ret[idx] = s[start];
		start++;
		idx++;
	}
	ret[idx] = 0;
	return (ret);
}
