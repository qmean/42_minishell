/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 23:06:17 by kyumkim           #+#    #+#             */
/*   Updated: 2023/12/07 17:37:08 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	ret;
	size_t	cnt;

	ret = ft_strlen(src);
	if (dstsize == 0)
		return (ret);
	cnt = 1;
	while (cnt < dstsize && *src != 0)
	{
		*dst = *src;
		dst++;
		src++;
		cnt++;
	}
	*dst = 0;
	return (ret);
}
