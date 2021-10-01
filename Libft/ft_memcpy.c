/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 20:39:29 by ppizzo            #+#    #+#             */
/*   Updated: 2021/09/05 21:28:44 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*res;

	res = dst;
	if (!dst && !src)
		return (0);
	while (n-- > 0)
		*(char *)dst++ = *(char *)src++;
	return (res);
}
