/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 00:22:24 by kyumkim           #+#    #+#             */
/*   Updated: 2023/12/07 17:50:55 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	len;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	len = 0;
	while (*dst != 0)
	{
		len++;
		dst++;
	}
	while (len + 1 < dstsize && *src != 0)
	{
		*dst++ = *src++;
		len++;
	}
	*dst = 0;
	if (dstlen < dstsize)
		return (dstlen + srclen);
	else
		return (srclen + dstsize);
}
