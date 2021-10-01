/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 21:16:25 by ppizzo            #+#    #+#             */
/*   Updated: 2021/09/06 00:12:13 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		s;
	int			i;
	size_t		solde;
	size_t		j;

	i = 0;
	solde = dstsize;
	j = ft_strlen(dst);
	s = ft_strlen(src);
	while (solde > 0 && dst[i])
	{
		solde--;
		i++;
	}
	if (solde == 0)
		return (i + ft_strlen(src));
	while (solde > 1 && *src)
	{
		dst[i] = *src;
		solde--;
		src++;
		i++;
	}
	dst[i] = '\0';
	return (j + s);
}
/*
#include <stdio.h>
#include <stdlib.h>

#include "libft.h"
int	main(void)
{
	char	d[50];
	char	s[50];

	strcpy(d," alerte au loukoum");
	strcpy(s,"ok les babouins du nord");
	printf("%lu",strlcat(d, s, 22));
	strcpy(d," alerte au loukoum");
	strcpy(s,"ok les babouins du nord");


	printf("%lu",ft_strlcat(d, s,22));
	//printf("%zu", ft_strlen("coucouc"));
	return (0);
}
*/
