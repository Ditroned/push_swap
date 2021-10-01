/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 12:42:10 by ppizzo            #+#    #+#             */
/*   Updated: 2021/09/03 21:45:17 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dst;
	char	*cdst;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dst = malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (dst);
	cdst = dst;
	while (*src)
		*cdst++ = *src++;
	*cdst = '\0';
	return (dst);
}
