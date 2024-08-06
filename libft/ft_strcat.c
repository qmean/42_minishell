/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 00:22:24 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/16 01:02:26 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
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
