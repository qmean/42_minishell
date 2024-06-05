/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:15:27 by kyumkim           #+#    #+#             */
/*   Updated: 2023/12/07 17:41:50 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*inp;
	size_t	idx;
	size_t	cnt;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	cnt = 0;
	while (*haystack != 0 && cnt++ < len)
	{
		inp = (char *)haystack;
		idx = 0;
		while (needle[idx] != 0 && idx + cnt <= len)
		{
			if (needle[idx] != *inp)
				break ;
			inp++;
			idx++;
		}
		if (needle[idx] == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
