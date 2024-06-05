/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:30:50 by kyumkim           #+#    #+#             */
/*   Updated: 2023/12/07 15:33:33 by kyumkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	cmp;
	char	*s1;
	char	*ret;

	s1 = (char *)s;
	cmp = (char)c;
	ret = 0;
	while (*s1 != 0)
	{
		if (*s1 == cmp)
			ret = s1;
		s1++;
	}
	if (*s1 == cmp)
		ret = s1;
	return (ret);
}
