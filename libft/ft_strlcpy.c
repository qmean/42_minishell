/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 23:06:17 by kyumkim           #+#    #+#             */
/*   Updated: 2024/06/12 03:57:36 by jaemikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src)
{
	size_t	ret;

	ret = ft_strlen(src);
	dst = malloc(ret + 1);
	if (dst == NULL)
		return (0);
	while (*src != 0)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = 0;
	return (ret);
}
