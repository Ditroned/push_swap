/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 00:36:49 by ppizzo            #+#    #+#             */
/*   Updated: 2021/09/05 21:32:40 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*k;

	k = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*k == (unsigned char )c)
			return ((void *)k);
		k++;
	}
	return (NULL);
}
