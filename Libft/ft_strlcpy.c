/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 21:16:07 by ppizzo            #+#    #+#             */
/*   Updated: 2021/09/05 21:37:16 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		i;

	i = 0;
	if (dstsize <= 0)
	{
		while (src[i] != '\0')
			i++;
		return (i);
	}	
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

/*
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		b;
	char		*s;

	s = (char *)src;
	b = 0;
	if (dstsize > 0)
	{
		while (*src != '\0' && b++ < dstsize - 1)
			*dst++ = *s++;
		*dst = '\0';
	}
	while (*s != '\0')
	{
		b++;
		s++;
	}
	return (b);
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	char c[50];
	char d[50];

	strcpy(c,"c'est vraiment super");
	puts(c);
	strcpy(d,"j'en fait un autre en cat");
	printf("%lu", ft_strlcpy(c, d, 40));
	return 0;
}
*/
